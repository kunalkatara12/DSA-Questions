# DSA Questions

![Language](https://img.shields.io/badge/Language-C%2B%2B17-00599C?style=for-the-badge&logo=cplusplus)
![Solutions](https://img.shields.io/badge/Solutions-134-2E7D32?style=for-the-badge)
![Topics](https://img.shields.io/badge/Topics-13-6A1B9A?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Syntax%20Checked-1565C0?style=for-the-badge)

A curated collection of Data Structures and Algorithms questions solved in C++.
The goal of this repository is simple: clean problem statements, correct solutions, and an easy-to-browse index for interview and competitive-programming revision.

> This README is generated from the repository files. Run `python3 scripts/generate_readme.py` after adding, renaming, or removing solutions.

## Highlights

| Metric | Count |
| --- | ---: |
| Total C++ solutions | 134 |
| Topic folders | 13 |
| Primary language | C++17 |
| Current syntax status | Passing with GNU-style `<bits/stdc++.h>` support |

## Topics

| Topic | Problems |
| --- | ---: |
| Array | 23 |
| Backtracking | 2 |
| Binary Search Tree | 4 |
| Dynamic Programming | 29 |
| Graph | 14 |
| Greedy | 4 |
| Linked List | 10 |
| Matrix | 4 |
| Recursion | 6 |
| Sliding Window | 4 |
| Stack and Queues | 9 |
| String | 6 |
| Tree | 19 |

## Repository Layout

```text
DSA-Questions/
├── Array/
├── Backtracking/
├── Binary Search Tree/
├── Dynamic Programming/
├── Graph/
├── Greedy/
├── Linked List/
├── Matrix/
├── Recursion/
├── Sliding Window/
├── Stack and Queues/
├── String/
└── Tree/
```

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

To estimate time and space complexity for a single solution file:

```bash
python3 scripts/generate_complexity.py "Recursion/(134)Remove Linked List Elements.cpp"
```

To write the generated complexity back into the file comment block:

```bash
python3 scripts/generate_complexity.py "Recursion/(134)Remove Linked List Elements.cpp" --write
```

To compile a single solution with GCC:

```bash
g++ -std=c++17 "Array/(083)Reverse Pairs.cpp" -o reverse_pairs
```

Most files are written as judge-style snippets. Some include an empty or sample `main()` only for local compilation.

## Problem Index

### Array

| # | Problem |
| --- | --- |
| 001 | [Set Matrix Zeroes](Array/%28001%29Set%20Matrix%20Zeroes.cpp) |
| 002 | [Move Zeroes](Array/%28002%29Move%20Zeroes.cpp) |
| 017 | [Two Sum](Array/%28017%29Two%20Sum.cpp) |
| 018 | [Chocolate Distribution Problem](Array/%28018%29Choclate%20Distribution%20Problem.cpp) |
| 029 | [Best Time to Buy and Sell Stock](Array/%28029%29Best%20Time%20to%20Buy%20and%20Sell%20Stock.cpp) |
| 030 | [Pascal's Triangle](Array/%28030%29Pascal%27s%20Triangle.cpp) |
| 031 | [Three Sum](Array/%28031%29Three%20Sum.cpp) |
| 033 | [Find Duplicate](Array/%28033%29Find%20Duplicate.cpp) |
| 052 | [Kth Largest Element](Array/%28052%29Kth%20Largest%20Element.cpp) |
| 054 | [4Sum](Array/%28054%294Sum.cpp) |
| 067 | [Longest Subarray with 0 Sum](Array/%28067%29Longest%20Subarray%20with%200%20Sum.cpp) |
| 068 | [Unique Paths](Array/%28068%29Unique%20Paths.cpp) |
| 081 | [Count Subarrays with XOR K](Array/%28081%29Count%20subarray%20with%20xor%20k.cpp) |
| 082 | [Pow(x, n)](Array/%28082%29Pow%28x.n%29.cpp) |
| 083 | [Reverse Pairs](Array/%28083%29Reverse%20Pairs.cpp) |
| 090 | [Repeat and Missing Number](Array/%28090%29Repeat%20and%20Missing.cpp) |
| 095 | [Maximum Subarray Sum - Kadane's Algorithm](Array/%28095%29Kadanes.cpp) |
| 097 | [Merge Overlapping Intervals](Array/%28097%29Merge%20Overlapping%20Subinterval.cpp) |
| 098 | [Merge Sorted Array](Array/%28098%29Merge%20Sorted%20Array.cpp) |
| 102 | [Minimum Operations to Form Subsequence With Target Sum](Array/%28102%29Min%20operations%20to%20Form%20Subseq.cpp) |
| 106 | [Longest Consecutive Sequence](Array/%28106%29Longest%20Consecutive%20Sequence.cpp) |
| 130 | [Insert Interval](Array/%28130%29Insert%20Interval.cpp) |
| 133 | [Next Permutation](Array/%28133%29Next%20Permutation.cpp) |

### Backtracking

| # | Problem |
| --- | --- |
| 126 | [Permutations of a String](Backtracking/%28126%29PermutationsOfString.cpp) |
| 127 | [Largest Number in K Swaps](Backtracking/%28127%29FindMaxNoInKSwap.cpp) |

### Binary Search Tree

| # | Problem |
| --- | --- |
| 084 | [Search Key in a BST](Binary%20Search%20Tree/%28084%29Search%20Key.cpp) |
| 085 | [Convert Sorted Array to BST](Binary%20Search%20Tree/%28085%29Construct%20a%20BST%20from%20given%20keys.cpp) |
| 104 | [Construct BST from Preorder Traversal](Binary%20Search%20Tree/%28104%29Construct%20a%20BST%20from%20preorder%20traversal.cpp) |
| 105 | [Validate BST](Binary%20Search%20Tree/%28105%29Validate%20BST.cpp) |

### Dynamic Programming

| # | Problem |
| --- | --- |
| 012 | [Trapping Rain Water](Dynamic%20Programming/%28012%29Trapping%20Rain%20Water.cpp) |
| 036 | [0-1 Knapsack](Dynamic%20Programming/%28036%290-1%20Knapsack.cpp) |
| 037 | [Subset Sum](Dynamic%20Programming/%28037%29Subset%20Sum.cpp) |
| 038 | [Partition Equal Subset Sum](Dynamic%20Programming/%28038%29Partition%20Equal%20Sum.cpp) |
| 039 | [Count Subsets With Sum K](Dynamic%20Programming/%28039%29Count%20Subset%20Sum.cpp) |
| 040 | [Rod Cutting](Dynamic%20Programming/%28040%29Rod%20Cutting.cpp) |
| 041 | [Coin Change - Number of Ways](Dynamic%20Programming/%28041%29Coin%20Change.cpp) |
| 042 | [Minimum Number of Coins](Dynamic%20Programming/%28042%29Minimum%20no.%20of%20Coin.cpp) |
| 043 | [Longest Common Subsequence](Dynamic%20Programming/%28043%29LongestCommonSubsequence.cpp) |
| 044 | [Longest Common Substring](Dynamic%20Programming/%28044%29LongestCommonSubstring.cpp) |
| 045 | [Print LCS](Dynamic%20Programming/%28045%29PrintLCS.cpp) |
| 091 | [Print Shortest Common Supersequence](Dynamic%20Programming/%28091%29Print%20SCS.cpp) |
| 092 | [Matrix Chain Multiplication](Dynamic%20Programming/%28092%29Matrix%20Chain%20Multiplication.cpp) |
| 093 | [Palindrome Partitioning](Dynamic%20Programming/%28093%29Palindrome%20Partioning.cpp) |
| 094 | [Longest Increasing Subsequence](Dynamic%20Programming/%28094%29Longest%20Increasing%20Subsequences.cpp) |
| 096 | [Maximum Product Subarray](Dynamic%20Programming/%28096%29Maximum%20Product%20Subarray.cpp) |
| 099 | [Word Break](Dynamic%20Programming/%28099%29Word%20Break.cpp) |
| 100 | [Egg Dropping Puzzle](Dynamic%20Programming/%28100%29Egg%20Drop.cpp) |
| 101 | [Russian Doll Envelopes](Dynamic%20Programming/%28101%29Russian%20Doll%20Envelope.cpp) |
| 114 | [Maximum sum increasing subsequence](Dynamic%20Programming/%28114%29Maximum%20Sum%20Increasing%20Subsequence.cpp) |
| 117 | [Minimum Path Sum](Dynamic%20Programming/%28117%29Minimum%20Sum%20Path.cpp) |
| 121 | [Minimum Insertions and Deletions](Dynamic%20Programming/%28121%29Minimum_No_Of_Ins_and_Del.cpp) |
| 122 | [Two Egg Drop](Dynamic%20Programming/%28122%29TwoEggDrop.cpp) |
| 123 | [Largest Divisible Subset](Dynamic%20Programming/%28123%29LargestDivisibleSubset.cpp) |
| 124 | [Print Longest Increasing Subsequence](Dynamic%20Programming/%28124%29PrintLIS.cpp) |
| 125 | [Generate Parentheses](Dynamic%20Programming/%28125%29GenerateParenthesis.cpp) |
| 128 | [Maximum Number of Operations With the Same Score II](Dynamic%20Programming/%28128%29MaxNumberOfOperations.cpp) |
| 129 | [Wildcard Matching](Dynamic%20Programming/%28129%29WildcardMatching.cpp) |
| 131 | [Best Time to Buy and Sell Stock with Cooldown](Dynamic%20Programming/%28131%29Best%20Time%20to%20Buy%20and%20Sell%20Stock%20with%20Cooldown.cpp) |

### Graph

| # | Problem |
| --- | --- |
| 019 | [BFS of Graph](Graph/%28019%29BFS%20of%20Graph.cpp) |
| 020 | [DFS of Graph](Graph/%28020%29DFS%20of%20Graph.cpp) |
| 021 | [Flood Fill](Graph/%28021%29Flood%20Fill.cpp) |
| 022 | [Find Center of Star Graph](Graph/%28022%29Find%20Center%20of%20Star.cpp) |
| 025 | [Detect Cycle in Undirected Graph](Graph/%28025%29Detect%20Cycle%20in%20Undirected%20Graph.cpp) |
| 109 | [Topological Sort](Graph/%28109%29TopologicalSort.cpp) |
| 110 | [Bipartite Graph - BFS](Graph/%28110%29Bipartite%20GraphBFS.cpp) |
| 111 | [Strongly Connected Components](Graph/%28111%29Strongly%20Connected%20Components.cpp) |
| 112 | [Shortest Path in Unweighted Graph](Graph/%28112%29Shortest%20Path%20in%20UG.cpp) |
| 113 | [Dijkstra Algorithm](Graph/%28113%29DijkstraAlgorithm.cpp) |
| 115 | [Minimum Spanning Tree - Prim's Algorithm](Graph/%28115%29MSTusingPrims.cpp) |
| 116 | [Minimum Spanning Tree - Kruskal's Algorithm](Graph/%28116%29MSTusing_Kruskal.cpp) |
| 118 | [Mother Vertex](Graph/%28118%29Mother%20Vertex.cpp) |
| 132 | [Number of Provinces](Graph/%28132%29No.%20of%20Provinces.cpp) |

### Greedy

| # | Problem |
| --- | --- |
| 079 | [Minimum Platforms](Greedy/%28079%29Min_Platforms.cpp) |
| 080 | [N Meetings in One Room](Greedy/%28080%29N_meetings.cpp) |
| 107 | [Job Sequencing](Greedy/%28107%29Job%20Sequencing.cpp) |
| 108 | [Fractional Knapsack](Greedy/%28108%29Fractional%20Knapsack.cpp) |

### Linked List

| # | Problem |
| --- | --- |
| 006 | [Middle of the Linked List](Linked%20List/%28006%29Middle%20of%20the%20Linked%20List.cpp) |
| 015 | [Linked List Cycle](Linked%20List/%28015%29Linked%20List%20Cycle.cpp) |
| 016 | [Convert Binary Number in a Linked List to Integer](Linked%20List/%28016%29Convert%20Binary%20Number%20to%20Linked%20List%20to%20Integer.cpp) |
| 023 | [Add Two Numbers](Linked%20List/%28023%29%20Add%20Two%20Numbers.cpp) |
| 035 | [Reverse Linked List](Linked%20List/%28035%29Reverse.cpp) |
| 055 | [Starting Point of Cycle](Linked%20List/%28055%29Starting%20Point%20of%20Cycle.cpp) |
| 057 | [Merge Two Sorted Lists](Linked%20List/%28057%29Merge%20Two%20Sorted%20List.cpp) |
| 058 | [Remove Nth Node From End](Linked%20List/%28058%29Remove%20Kth%20node.cpp) |
| 059 | [Delete Node in a Linked List](Linked%20List/%28059%29Delete%20a%20node%20in%20List.cpp) |
| 060 | [Intersection Point of Two Linked Lists](Linked%20List/%28060%29Intersection%20Point.cpp) |

### Matrix

| # | Problem |
| --- | --- |
| 008 | [Maximal Rectangle](Matrix/%28008%29MaxAreaRectangle.cpp) |
| 026 | [Number of Islands](Matrix/%28026%29No.%20of%20Islands.cpp) |
| 027 | [Search a 2D Matrix](Matrix/%28027%29Search%20in%20matrix.cpp) |
| 069 | [Rotate Matrix](Matrix/%28069%29Rotate%20Matrix.cpp) |

### Recursion

| # | Problem |
| --- | --- |
| 032 | [Sort Colors](Recursion/%28032%29Sort%20Colors.cpp) |
| 053 | [Subset Sums](Recursion/%28053%29subset%20Sums.cpp) |
| 056 | [Subsets II](Recursion/%28056%29Subset%20Sums2.cpp) |
| 071 | [Combination Sum](Recursion/%28071%29CombinationSum.cpp) |
| 072 | [Combination Sum II](Recursion/%28072%29Combination%20Sum2.cpp) |
| 134 | [Remove Linked List Elements](Recursion/%28134%29Remove%20Linked%20List%20Elements.cpp) |

### Sliding Window

| # | Problem |
| --- | --- |
| 061 | [Sliding Window Maximum](Sliding%20Window/%28061%29Sliding%20Window%20Maximum.cpp) |
| 103 | [Longest Substring Without Repeating Characters](Sliding%20Window/%28103%29Longest%20Substring%20with%20unique%20characters.cpp) |
| 119 | [Maximum Sum of Almost Unique Subarray](Sliding%20Window/%28119%29Maximum%20sum%20of%20almost%20unique%20subarray.cpp) |
| 120 | [Minimum Window Substring](Sliding%20Window/%28120%29Minimum%20Window%20Substring.cpp) |

### Stack and Queues

| # | Problem |
| --- | --- |
| 004 | [Stock Span Problem](Stack%20and%20Queues/%28004%29StockSpanProblem.cpp) |
| 005 | [Next Greater Element I](Stack%20and%20Queues/%28005%29NextGreaterElement-1.cpp) |
| 007 | [Largest Rectangle in Histogram](Stack%20and%20Queues/%28007%29LargestRectangleHistogram.cpp) |
| 013 | [Evaluation of Postfix Expression](Stack%20and%20Queues/%28013%29Evaluation%20Postfix%20Expression.cpp) |
| 014 | [Implement Queue Using Stacks](Stack%20and%20Queues/%28014%29Implement%20Queue%20using%20Stacks.cpp) |
| 024 | [Rotten Oranges](Stack%20and%20Queues/%28024%29Rotten%20Oranges.cpp) |
| 028 | [Distance of Nearest Cell Having 1](Stack%20and%20Queues/%28028%29Distance%20of%20nearest%20cell%20having%201.cpp) |
| 034 | [Sort a Stack](Stack%20and%20Queues/%28034%29Sort%20a%20Stack.cpp) |
| 070 | [Min Stack](Stack%20and%20Queues/%28070%29Min%20Stack.cpp) |

### String

| # | Problem |
| --- | --- |
| 003 | [Valid Parentheses](String/%28003%29ValidParenthesis.cpp) |
| 062 | [Reverse Words in a String](String/%28062%29Reverse%20a%20String.cpp) |
| 063 | [Roman to Integer](String/%28063%29Roman-Int.cpp) |
| 064 | [String to Integer - Atoi](String/%28064%29MyAtoi.cpp) |
| 065 | [Valid Anagram](String/%28065%29Check%20For%20Anagram.cpp) |
| 066 | [KMP Pattern Matching](String/%28066%29KMP.cpp) |

### Tree

| # | Problem |
| --- | --- |
| 009 | [Maximum Depth of Binary Tree](Tree/%28009%29Max%20Depth%20Of%20BinaryTree.cpp) |
| 010 | [Diameter of Binary Tree](Tree/%28010%29Diameter%20Of%20Binary%20Tree.cpp) |
| 011 | [Symmetric Tree](Tree/%28011%29Symmetric%20Tree.cpp) |
| 046 | [Left View of Binary Tree](Tree/%28046%29Left%20View%20of%20Tree.cpp) |
| 047 | [Top View of Binary Tree](Tree/%28047%29Top%20View%20of%20Tree.cpp) |
| 048 | [Level Order Traversal](Tree/%28048%29Level%20Order%20Traversal.cpp) |
| 049 | [Vertical Order Traversal](Tree/%28049%29Vertical%20Order%20Traversal.cpp) |
| 050 | [Maximum Width of Binary Tree](Tree/%28050%29Maximum%20Width%20of%20BT.cpp) |
| 051 | [Kth Largest Element in BST](Tree/%28051%29Kth%20Largest%20Element%20in%20BST.cpp) |
| 073 | [Morris Inorder Traversal](Tree/%28073%29Morris%20Inorder.cpp) |
| 074 | [Morris Preorder Traversal](Tree/%28074%29Morris%20Preorder.cpp) |
| 075 | [Root to Leaf Paths](Tree/%28075%29Root%20To%20Leaf.cpp) |
| 076 | [Bottom View of Binary Tree](Tree/%28076%29%20Bottom%20View.cpp) |
| 077 | [Balanced Binary Tree](Tree/%28077%29Balanced%20Binary%20Tree.cpp) |
| 078 | [Identical Tree](Tree/%28078%29%20Identical%20Tree.cpp) |
| 086 | [Populating Next Right Pointers](Tree/%28086%29Populating%20Next%20Right%20Pointer.cpp) |
| 087 | [Maximum Path Sum](Tree/%28087%29Max%20Path%20Sum.cpp) |
| 088 | [Zig Zag Level Order Traversal](Tree/%28088%29Zig%20Zag.cpp) |
| 089 | [Flatten Binary Tree to Linked List](Tree/%28089%29Flatten%20Tree%20To%20List.cpp) |

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
