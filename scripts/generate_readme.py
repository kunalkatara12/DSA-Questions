#!/usr/bin/env python3
"""Generate README.md from the C++ solution files."""

from __future__ import annotations

import re
from pathlib import Path
from urllib.parse import quote


ROOT = Path(__file__).resolve().parents[1]
README = ROOT / "README.md"

TOPIC_ORDER = [
    "Array",
    "Backtracking",
    "Binary Search Tree",
    "Dynamic Programming",
    "Graph",
    "Greedy",
    "Linked List",
    "Matrix",
    "Recursion",
    "Sliding Window",
    "Stack and Queues",
    "String",
    "Tree",
]

TITLE_OVERRIDES = {
    "Array/(018)Choclate Distribution Problem.cpp": "Chocolate Distribution Problem",
    "Array/(031)Three Sum.cpp": "Three Sum",
    "Array/(033)Find Duplicate.cpp": "Find Duplicate",
    "Array/(052)Kth Largest Element.cpp": "Kth Largest Element",
    "Array/(054)4Sum.cpp": "4Sum",
    "Array/(067)Longest Subarray with 0 Sum.cpp": "Longest Subarray with 0 Sum",
    "Array/(081)Count subarray with xor k.cpp": "Count Subarrays with XOR K",
    "Array/(082)Pow(x.n).cpp": "Pow(x, n)",
    "Array/(090)Repeat and Missing.cpp": "Repeat and Missing Number",
    "Array/(095)Kadanes.cpp": "Maximum Subarray Sum - Kadane's Algorithm",
    "Array/(097)Merge Overlapping Subinterval.cpp": "Merge Overlapping Intervals",
    "Array/(098)Merge Sorted Array.cpp": "Merge Sorted Array",
    "Array/(102)Min operations to Form Subseq.cpp": "Minimum Operations to Form Subsequence With Target Sum",
    "Backtracking/(126)PermutationsOfString.cpp": "Permutations of a String",
    "Backtracking/(127)FindMaxNoInKSwap.cpp": "Largest Number in K Swaps",
    "Binary Search Tree/(084)Search Key.cpp": "Search Key in a BST",
    "Binary Search Tree/(085)Construct a BST from given keys.cpp": "Convert Sorted Array to BST",
    "Binary Search Tree/(104)Construct a BST from preorder traversal.cpp": "Construct BST from Preorder Traversal",
    "Binary Search Tree/(105)Validate BST.cpp": "Validate BST",
    "Dynamic Programming/(036)0-1 Knapsack.cpp": "0-1 Knapsack",
    "Dynamic Programming/(037)Subset Sum.cpp": "Subset Sum",
    "Dynamic Programming/(039)Count Subset Sum.cpp": "Count Subsets With Sum K",
    "Dynamic Programming/(041)Coin Change.cpp": "Coin Change - Number of Ways",
    "Dynamic Programming/(042)Minimum no. of Coin.cpp": "Minimum Number of Coins",
    "Dynamic Programming/(043)LongestCommonSubsequence.cpp": "Longest Common Subsequence",
    "Dynamic Programming/(044)LongestCommonSubstring.cpp": "Longest Common Substring",
    "Dynamic Programming/(045)PrintLCS.cpp": "Print LCS",
    "Dynamic Programming/(091)Print SCS.cpp": "Print Shortest Common Supersequence",
    "Dynamic Programming/(093)Palindrome Partioning.cpp": "Palindrome Partitioning",
    "Dynamic Programming/(094)Longest Increasing Subsequences.cpp": "Longest Increasing Subsequence",
    "Dynamic Programming/(100)Egg Drop.cpp": "Egg Dropping Puzzle",
    "Dynamic Programming/(117)Minimum Sum Path.cpp": "Minimum Path Sum",
    "Dynamic Programming/(121)Minimum_No_Of_Ins_and_Del.cpp": "Minimum Insertions and Deletions",
    "Dynamic Programming/(122)TwoEggDrop.cpp": "Two Egg Drop",
    "Dynamic Programming/(124)PrintLIS.cpp": "Print Longest Increasing Subsequence",
    "Graph/(019)BFS of Graph.cpp": "BFS of Graph",
    "Graph/(020)DFS of Graph.cpp": "DFS of Graph",
    "Graph/(022)Find Center of Star.cpp": "Find Center of Star Graph",
    "Graph/(025)Detect Cycle in Undirected Graph.cpp": "Detect Cycle in Undirected Graph",
    "Graph/(110)Bipartite GraphBFS.cpp": "Bipartite Graph - BFS",
    "Graph/(112)Shortest Path in UG.cpp": "Shortest Path in Unweighted Graph",
    "Graph/(113)DijkstraAlgorithm.cpp": "Dijkstra Algorithm",
    "Graph/(115)MSTusingPrims.cpp": "Minimum Spanning Tree - Prim's Algorithm",
    "Graph/(116)MSTusing_Kruskal.cpp": "Minimum Spanning Tree - Kruskal's Algorithm",
    "Greedy/(080)N_meetings.cpp": "N Meetings in One Room",
    "Greedy/(107)Job Sequencing.cpp": "Job Sequencing",
    "Linked List/(016)Convert Binary Number to Linked List to Integer.cpp": "Convert Binary Number in a Linked List to Integer",
    "Linked List/(035)Reverse.cpp": "Reverse Linked List",
    "Linked List/(055)Starting Point of Cycle.cpp": "Starting Point of Cycle",
    "Linked List/(057)Merge Two Sorted List.cpp": "Merge Two Sorted Lists",
    "Linked List/(058)Remove Kth node.cpp": "Remove Nth Node From End",
    "Linked List/(060)Intersection Point.cpp": "Intersection Point of Two Linked Lists",
    "Matrix/(008)MaxAreaRectangle.cpp": "Maximal Rectangle",
    "Matrix/(026)No. of Islands.cpp": "Number of Islands",
    "Matrix/(069)Rotate Matrix.cpp": "Rotate Matrix",
    "Recursion/(056)Subset Sums2.cpp": "Subsets II",
    "Sliding Window/(103)Longest Substring with unique characters.cpp": "Longest Substring Without Repeating Characters",
    "Stack and Queues/(005)NextGreaterElement-1.cpp": "Next Greater Element I",
    "Stack and Queues/(007)LargestRectangleHistogram.cpp": "Largest Rectangle in Histogram",
    "Stack and Queues/(013)Evaluation Postfix Expression.cpp": "Evaluation of Postfix Expression",
    "Stack and Queues/(014)Implement Queue using Stacks.cpp": "Implement Queue Using Stacks",
    "Stack and Queues/(024)Rotten Oranges.cpp": "Rotten Oranges",
    "Stack and Queues/(028)Distance of nearest cell having 1.cpp": "Distance of Nearest Cell Having 1",
    "String/(003)ValidParenthesis.cpp": "Valid Parentheses",
    "String/(062)Reverse a String.cpp": "Reverse Words in a String",
    "String/(063)Roman-Int.cpp": "Roman to Integer",
    "String/(064)MyAtoi.cpp": "String to Integer - Atoi",
    "String/(065)Check For Anagram.cpp": "Valid Anagram",
    "String/(066)KMP.cpp": "KMP Pattern Matching",
    "Tree/(009)Max Depth Of BinaryTree.cpp": "Maximum Depth of Binary Tree",
    "Tree/(010)Diameter Of Binary Tree.cpp": "Diameter of Binary Tree",
    "Tree/(046)Left View of Tree.cpp": "Left View of Binary Tree",
    "Tree/(047)Top View of Tree.cpp": "Top View of Binary Tree",
    "Tree/(048)Level Order Traversal.cpp": "Level Order Traversal",
    "Tree/(049)Vertical Order Traversal.cpp": "Vertical Order Traversal",
    "Tree/(050)Maximum Width of BT.cpp": "Maximum Width of Binary Tree",
    "Tree/(051)Kth Largest Element in BST.cpp": "Kth Largest Element in BST",
    "Tree/(073)Morris Inorder.cpp": "Morris Inorder Traversal",
    "Tree/(074)Morris Preorder.cpp": "Morris Preorder Traversal",
    "Tree/(075)Root To Leaf.cpp": "Root to Leaf Paths",
    "Tree/(076) Bottom View.cpp": "Bottom View of Binary Tree",
    "Tree/(078) Identical Tree.cpp": "Identical Tree",
    "Tree/(086)Populating Next Right Pointer.cpp": "Populating Next Right Pointers",
    "Tree/(087)Max Path Sum.cpp": "Maximum Path Sum",
    "Tree/(088)Zig Zag.cpp": "Zig Zag Level Order Traversal",
    "Tree/(089)Flatten Tree To List.cpp": "Flatten Binary Tree to Linked List",
}


def solution_files() -> dict[str, list[Path]]:
    topics: dict[str, list[Path]] = {}
    ordered_topics = [topic for topic in TOPIC_ORDER if (ROOT / topic).is_dir()]
    extra_topics = sorted(
        path.name
        for path in ROOT.iterdir()
        if path.is_dir() and not path.name.startswith(".") and path.name not in TOPIC_ORDER
    )

    for topic in ordered_topics + extra_topics:
        files = sorted((ROOT / topic).glob("*.cpp"), key=sort_key)
        if files:
            topics[topic] = files

    return topics


def sort_key(path: Path) -> tuple[int, str]:
    number = problem_number(path)
    return (int(number) if number.isdigit() else 10**9, path.name.lower())


def problem_number(path: Path) -> str:
    match = re.match(r"\((\d+)\)", path.name.strip())
    return match.group(1) if match else "-"


def problem_title(path: Path) -> str:
    rel = path.relative_to(ROOT).as_posix()
    if rel in TITLE_OVERRIDES:
        return TITLE_OVERRIDES[rel]

    text = path.read_text(encoding="utf-8", errors="ignore")
    for pattern in (r"Problem Title:\s*(.+)", r"Problem:\s*(.+)"):
        match = re.search(pattern, text)
        if match:
            title = clean_title(match.group(1))
            if title:
                return title

    stem = re.sub(r"^\(\d+\)\s*", "", path.stem.strip())
    return clean_title(stem)


def clean_title(title: str) -> str:
    title = title.strip().strip("*")
    title = re.sub(r"^\d+\.\s*", "", title)
    title = title.replace("_", " ")
    title = re.sub(r"(?<=[a-z])(?=[A-Z])", " ", title)
    title = re.sub(r"\s+", " ", title)
    return title.strip()


def readme_link(path: Path) -> str:
    rel = path.relative_to(ROOT).as_posix()
    return quote(rel, safe="/")


def render_badges(total: int, topic_count: int) -> str:
    return "\n".join(
        [
            "![Language](https://img.shields.io/badge/Language-C%2B%2B17-00599C?style=for-the-badge&logo=cplusplus)",
            f"![Solutions](https://img.shields.io/badge/Solutions-{total}-2E7D32?style=for-the-badge)",
            f"![Topics](https://img.shields.io/badge/Topics-{topic_count}-6A1B9A?style=for-the-badge)",
            "![Status](https://img.shields.io/badge/Status-Syntax%20Checked-1565C0?style=for-the-badge)",
        ]
    )


def render_topics_table(topics: dict[str, list[Path]]) -> str:
    rows = ["| Topic | Problems |", "| --- | ---: |"]
    rows.extend(f"| {topic} | {len(files)} |" for topic, files in topics.items())
    return "\n".join(rows)


def render_layout(topics: dict[str, list[Path]]) -> str:
    lines = ["```text", "DSA-Questions/"]
    topic_names = list(topics)
    for index, topic in enumerate(topic_names):
        prefix = "└──" if index == len(topic_names) - 1 else "├──"
        lines.append(f"{prefix} {topic}/")
    lines.append("```")
    return "\n".join(lines)


def render_problem_index(topics: dict[str, list[Path]]) -> str:
    sections: list[str] = []
    for topic, files in topics.items():
        sections.extend(
            [
                f"### {topic}",
                "",
                "| # | Problem |",
                "| --- | --- |",
            ]
        )
        for path in files:
            number = problem_number(path)
            title = problem_title(path)
            sections.append(f"| {number} | [{title}]({readme_link(path)}) |")
        sections.append("")
    return "\n".join(sections).rstrip()


def render_readme() -> str:
    topics = solution_files()
    total = sum(len(files) for files in topics.values())

    return f"""# DSA Questions

{render_badges(total, len(topics))}

A curated collection of Data Structures and Algorithms questions solved in C++.
The goal of this repository is simple: clean problem statements, correct solutions, and an easy-to-browse index for interview and competitive-programming revision.

> This README is generated from the repository files. Run `python3 scripts/generate_readme.py` after adding, renaming, or removing solutions.

## Highlights

| Metric | Count |
| --- | ---: |
| Total C++ solutions | {total} |
| Topic folders | {len(topics)} |
| Primary language | C++17 |
| Current syntax status | Passing with GNU-style `<bits/stdc++.h>` support |

## Topics

{render_topics_table(topics)}

## Repository Layout

{render_layout(topics)}

Each file is named with the sheet/problem number and the problem title:

```text
Topic/(number)Problem Name.cpp
```

## How To Use

Clone the repo, open a topic folder, and read the file for the problem statement, link, and C++ solution.

To add the next question interactively:

```bash
python3 scripts/add_question.py
```

To add a question directly from the CLI:

```bash
python3 scripts/add_question.py --topic "Array" --name "New Problem Name"
```

To compile a single solution with GCC:

```bash
g++ -std=c++17 "Array/(083)Reverse Pairs.cpp" -o reverse_pairs
```

Most files are written as judge-style snippets. Some include an empty or sample `main()` only for local compilation.

## Problem Index

{render_problem_index(topics)}

## Quality Notes

- Solutions target C++17 and competitive-programming judges.
- Files are syntax-checked as standalone snippets with GNU-style `<bits/stdc++.h>` support.
- Problem statements and links are kept close to the solution files for quick revision.
- Local build outputs, operating-system files, and scratch files are ignored by `.gitignore`.

## Contributing

Contributions are welcome. A good contribution should:

1. Keep the problem statement/link at the top of the file.
2. Prefer clear, accepted, judge-compatible C++17.
3. Include time and space complexity when helpful.
4. Run `python3 scripts/generate_readme.py` after changing solution files.
5. Avoid committing local binaries, editor files, or scratch programs.

## Profiles

- [LeetCode](https://leetcode.com/kunalkatara888/)
- [HackerRank](https://www.hackerrank.com/kunalkatara888?hr_r=1)
- [CodeChef](https://www.codechef.com/users/kunalkatara12)

## References

- [Striver SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)
- [Take U Forward - Graphs](https://www.youtube.com/playlist?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn)
- [Take U Forward - Trees](https://www.youtube.com/playlist?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)
- [Aditya Verma - Dynamic Programming](https://www.youtube.com/playlist?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go)
- [Aditya Verma - Sliding Window](https://www.youtube.com/playlist?list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj)
- [Aditya Verma - Stack](https://www.youtube.com/playlist?list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd)
"""


def main() -> None:
    README.write_text(render_readme(), encoding="utf-8")
    print(f"Updated {README.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
