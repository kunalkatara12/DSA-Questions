#!/usr/bin/env python3
"""Create the next numbered DSA question file and refresh README.md."""

from __future__ import annotations

import argparse
import re
from pathlib import Path

import generate_readme


ROOT = Path(__file__).resolve().parents[1]


def topic_folders() -> list[str]:
    ordered = [topic for topic in generate_readme.TOPIC_ORDER if (ROOT / topic).is_dir()]
    extras = sorted(
        path.name
        for path in ROOT.iterdir()
        if path.is_dir()
        and not path.name.startswith(".")
        and path.name not in generate_readme.TOPIC_ORDER
        and path.name != "scripts"
    )
    return ordered + extras


def existing_numbers() -> list[int]:
    numbers: list[int] = []
    for topic in topic_folders():
        for path in (ROOT / topic).glob("*.cpp"):
            match = re.match(r"\((\d+)\)", path.name.strip())
            if match:
                numbers.append(int(match.group(1)))
    return numbers


def next_question_number() -> int:
    numbers = existing_numbers()
    return max(numbers, default=0) + 1


def sanitize_name(name: str) -> str:
    cleaned = re.sub(r"[\\/:*?\"<>|]", "", name.strip())
    cleaned = re.sub(r"\s+", " ", cleaned)
    return cleaned


def select_topic() -> str:
    topics = topic_folders()
    print("Select topic folder:")
    for index, topic in enumerate(topics, start=1):
        print(f"{index:2}. {topic}")

    while True:
        choice = input("Enter number: ").strip()
        if choice.isdigit() and 1 <= int(choice) <= len(topics):
            return topics[int(choice) - 1]
        print("Please enter a valid topic number.")


def prompt_name() -> str:
    while True:
        name = sanitize_name(input("Question name: "))
        if name:
            return name
        print("Question name cannot be empty.")


def starter_template(title: str) -> str:
    return f"""/*
Link:
Problem: {title}
Difficulty:

Statement:

Approach:

Time Complexity:
Space Complexity:
*/

#include <bits/stdc++.h>
using namespace std;

"""


def create_question(topic: str, name: str, number: int | None, empty: bool) -> Path:
    topic_path = ROOT / topic
    if not topic_path.is_dir():
        raise SystemExit(f"Topic folder does not exist: {topic}")

    cleaned_name = sanitize_name(name)
    if not cleaned_name:
        raise SystemExit("Question name cannot be empty.")

    question_number = number if number is not None else next_question_number()
    file_path = topic_path / f"({question_number:03d}){cleaned_name}.cpp"

    if file_path.exists():
        raise SystemExit(f"File already exists: {file_path.relative_to(ROOT)}")

    content = "" if empty else starter_template(cleaned_name)
    file_path.write_text(content, encoding="utf-8")
    return file_path


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Create the next numbered DSA question file."
    )
    parser.add_argument("-t", "--topic", help="Topic folder, for example: Array")
    parser.add_argument("-n", "--name", help="Question name, for example: Two Sum")
    parser.add_argument(
        "--number",
        type=int,
        help="Use a specific problem number instead of the next global number.",
    )
    parser.add_argument(
        "--empty",
        action="store_true",
        help="Create a truly empty .cpp file instead of the starter template.",
    )
    parser.add_argument(
        "--no-readme",
        action="store_true",
        help="Do not regenerate README.md after creating the file.",
    )
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    topic = args.topic or select_topic()
    name = args.name or prompt_name()

    created = create_question(topic, name, args.number, args.empty)
    print(f"Created {created.relative_to(ROOT)}")

    if not args.no_readme:
        generate_readme.main()


if __name__ == "__main__":
    main()
