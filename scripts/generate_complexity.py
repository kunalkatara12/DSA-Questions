#!/usr/bin/env python3
"""Estimate time and space complexity for a single C++ solution file.

This is a heuristic helper, not a full compiler-grade analyzer.
It works best for the competitive-programming style solutions in this repo.
"""

from __future__ import annotations

import argparse
import re
from dataclasses import dataclass
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]

CONTAINER_PATTERNS = {
    "vector": r"\bvector\s*<",
    "map": r"\bmap\s*<",
    "unordered_map": r"\bunordered_map\s*<",
    "set": r"\bset\s*<",
    "unordered_set": r"\bunordered_set\s*<",
    "queue": r"\bqueue\s*<",
    "deque": r"\bdeque\s*<",
    "stack": r"\bstack\s*<",
    "priority_queue": r"\bpriority_queue\s*<",
    "string": r"\bstring\b",
}


@dataclass
class ComplexityEstimate:
    time_complexity: str
    space_complexity: str
    time_reason: str
    space_reason: str


def storage_declaration_patterns() -> list[str]:
    return [
        r"\bvector\s*<[^;=]+>\s+\w+",
        r"\bmap\s*<[^;=]+>\s+\w+",
        r"\bunordered_map\s*<[^;=]+>\s+\w+",
        r"\bset\s*<[^;=]+>\s+\w+",
        r"\bunordered_set\s*<[^;=]+>\s+\w+",
        r"\bqueue\s*<[^;=]+>\s+\w+",
        r"\bdeque\s*<[^;=]+>\s+\w+",
        r"\bstack\s*<[^;=]+>\s+\w+",
        r"\bpriority_queue\s*<[^;=]+>\s+\w+",
        r"\bstring\s+\w+",
    ]


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Estimate time and space complexity for one C++ solution file."
    )
    parser.add_argument("file", help="Path to the .cpp file")
    parser.add_argument(
        "--write",
        action="store_true",
        help="Write the generated time/space complexity into the file comment block.",
    )
    return parser.parse_args()


def resolve_file(path_str: str) -> Path:
    path = Path(path_str)
    if not path.is_absolute():
        path = ROOT / path
    path = path.resolve()

    if not path.is_file():
        raise SystemExit(f"File not found: {path_str}")
    if path.suffix != ".cpp":
        raise SystemExit("Only .cpp files are supported.")
    return path


def strip_comments_and_strings(code: str) -> str:
    result: list[str] = []
    i = 0
    in_block = False
    in_line = False
    in_string = False
    string_char = ""

    while i < len(code):
        ch = code[i]
        nxt = code[i + 1] if i + 1 < len(code) else ""

        if in_block:
            if ch == "*" and nxt == "/":
                in_block = False
                i += 2
            else:
                i += 1
            continue

        if in_line:
            if ch == "\n":
                in_line = False
                result.append("\n")
            i += 1
            continue

        if in_string:
            if ch == "\\":
                i += 2
                continue
            if ch == string_char:
                in_string = False
                string_char = ""
            i += 1
            continue

        if ch == "/" and nxt == "*":
            in_block = True
            i += 2
            continue

        if ch == "/" and nxt == "/":
            in_line = True
            i += 2
            continue

        if ch in {'"', "'"}:
            in_string = True
            string_char = ch
            i += 1
            continue

        result.append(ch)
        i += 1

    return "".join(result)


def function_blocks(code: str) -> dict[str, str]:
    pattern = re.compile(
        r"(?:^|\n)\s*(?:[\w:<>~*&]+\s+)+(?P<name>[A-Za-z_]\w*)\s*\([^;{}()]*\)\s*\{",
        re.MULTILINE,
    )
    blocks: dict[str, str] = {}

    for match in pattern.finditer(code):
        name = match.group("name")
        start = match.end() - 1
        depth = 0
        end = start

        while end < len(code):
            if code[end] == "{":
                depth += 1
            elif code[end] == "}":
                depth -= 1
                if depth == 0:
                    blocks[name] = code[start : end + 1]
                    break
            end += 1

    return blocks


def max_loop_depth(code: str) -> int:
    lines = code.splitlines()
    depth = 0
    max_depth = 0
    pending_loop_levels: list[int] = []
    brace_depth = 0

    for raw_line in lines:
        line = raw_line.strip()
        if not line:
            open_braces = raw_line.count("{")
            close_braces = raw_line.count("}")
            brace_depth += open_braces - close_braces
            while pending_loop_levels and brace_depth < pending_loop_levels[-1]:
                pending_loop_levels.pop()
            depth = len(pending_loop_levels)
            continue

        close_braces = raw_line.count("}")
        brace_depth -= close_braces
        while pending_loop_levels and brace_depth < pending_loop_levels[-1]:
            pending_loop_levels.pop()

        line_loop_count = len(re.findall(r"\b(for|while)\s*\(", line))
        for _ in range(line_loop_count):
            depth = len(pending_loop_levels) + 1
            max_depth = max(max_depth, depth)

            if "{" in line:
                pending_loop_levels.append(brace_depth + line.count("{"))

        open_braces = raw_line.count("{")
        brace_depth += open_braces
        depth = len(pending_loop_levels)

    return max_depth


def recursion_profile(code: str) -> tuple[int, int]:
    blocks = function_blocks(code)
    recursive_functions = 0
    max_self_calls = 0

    for name, body in blocks.items():
        calls = len(re.findall(rf"\b{re.escape(name)}\s*\(", body))
        self_calls = max(calls - 1, 0)
        if self_calls > 0:
            recursive_functions += 1
            max_self_calls = max(max_self_calls, self_calls)

    return recursive_functions, max_self_calls


def detect_sort(code: str) -> bool:
    return bool(re.search(r"\bsort\s*\(", code))


def detect_priority_queue_ops(code: str) -> bool:
    return bool(re.search(r"\bpriority_queue\s*<", code))


def detect_tree_or_graph_traversal(code: str) -> bool:
    graph_words = ("adj", "visited", "bfs", "dfs", "queue<", "stack<")
    return any(word in code for word in graph_words)


def detect_2d_storage(code: str) -> bool:
    lines = [line.strip() for line in code.splitlines() if ";" in line]
    return any(
        re.search(r"\bvector\s*<\s*vector\s*<", line)
        or re.search(r"\b\w+\s+\w+\s*\[[^\]]+\]\s*\[[^\]]+\]", line)
        for line in lines
    )


def detect_linear_storage(code: str) -> bool:
    lines = [line.strip() for line in code.splitlines() if ";" in line]
    for line in lines:
        for pattern in storage_declaration_patterns():
            if re.search(pattern, line):
                return True
    return False


def estimate_time(code: str) -> tuple[str, str]:
    loop_depth = max_loop_depth(code)
    recursive_functions, max_self_calls = recursion_profile(code)
    has_sort = detect_sort(code)
    has_priority_queue = detect_priority_queue_ops(code)
    is_graph_like = detect_tree_or_graph_traversal(code)

    if max_self_calls >= 2:
        if loop_depth >= 1:
            return "O(n * 2^n)", "multiple self-recursive calls inside iterative work"
        return "O(2^n)", "multiple self-recursive calls suggest branching recursion"

    if has_sort and loop_depth >= 2:
        return "O(n^2 log n)", "sorting plus nested iteration"
    if has_sort:
        return "O(n log n)", "dominant sorting step detected"

    if has_priority_queue and is_graph_like:
        return "O(E log V)", "graph traversal with priority queue pattern detected"

    if recursive_functions > 0:
        if loop_depth >= 2:
            return "O(n^2)", "linear recursion combined with nested iterative work"
        return "O(n)", "single-path recursion pattern detected"

    if loop_depth >= 3:
        return "O(n^3)", "triple nested loops detected"
    if loop_depth == 2:
        return "O(n^2)", "nested loops detected"
    if loop_depth == 1:
        return "O(n)", "single main loop detected"

    return "O(1)", "no dominant loops, sort, or recursion detected"


def estimate_space(code: str) -> tuple[str, str]:
    recursive_functions, _ = recursion_profile(code)
    has_2d_storage = detect_2d_storage(code)
    has_linear_storage = detect_linear_storage(code)

    if has_2d_storage and recursive_functions > 0:
        return "O(n^2)", "2D storage dominates auxiliary space"
    if has_2d_storage:
        return "O(n^2)", "2D table or matrix-style auxiliary storage detected"
    if recursive_functions > 0 and has_linear_storage:
        return "O(n)", "recursion stack and linear auxiliary containers detected"
    if recursive_functions > 0:
        return "O(n)", "recursion stack detected"
    if has_linear_storage:
        return "O(n)", "linear auxiliary container usage detected"
    return "O(1)", "no obvious auxiliary storage beyond a few pointers/variables"


def estimate_complexity(path: Path) -> ComplexityEstimate:
    raw_code = path.read_text(encoding="utf-8", errors="ignore")
    code = strip_comments_and_strings(raw_code)
    time_complexity, time_reason = estimate_time(code)
    space_complexity, space_reason = estimate_space(code)
    return ComplexityEstimate(
        time_complexity=time_complexity,
        space_complexity=space_complexity,
        time_reason=time_reason,
        space_reason=space_reason,
    )


def replace_or_fill(label: str, value: str, text: str) -> str:
    pattern = re.compile(rf"^({re.escape(label)}\s*:\s*).*$", re.MULTILINE)
    match = pattern.search(text)
    if match:
        return pattern.sub(rf"\1{value}", text, count=1)
    return text


def write_estimate(path: Path, estimate: ComplexityEstimate) -> None:
    text = path.read_text(encoding="utf-8")
    has_time_label = "Time Complexity:" in text
    has_space_label = "Space Complexity:" in text
    updated = replace_or_fill("Time Complexity", estimate.time_complexity, text)
    updated = replace_or_fill("Space Complexity", estimate.space_complexity, updated)

    if "Space Complexity" not in updated and "Time Complexity" in updated:
        updated = re.sub(
            r"^(Time Complexity\s*:\s*.*)$",
            rf"\1\nSpace Complexity: {estimate.space_complexity}",
            updated,
            count=1,
            flags=re.MULTILINE,
        )

    if not has_time_label and not has_space_label:
        raise SystemExit(
            "Could not find Time Complexity / Space Complexity lines to update."
        )

    if updated != text:
        path.write_text(updated, encoding="utf-8")


def main() -> None:
    args = parse_args()
    path = resolve_file(args.file)
    estimate = estimate_complexity(path)

    print(f"File: {path.relative_to(ROOT)}")
    print(f"Estimated Time Complexity: {estimate.time_complexity}")
    print(f"Reason: {estimate.time_reason}")
    print(f"Estimated Space Complexity: {estimate.space_complexity}")
    print(f"Reason: {estimate.space_reason}")
    print("Note: this is a heuristic estimate, so verify before committing.")

    if args.write:
        write_estimate(path, estimate)
        print("Updated file comment block.")


if __name__ == "__main__":
    main()
