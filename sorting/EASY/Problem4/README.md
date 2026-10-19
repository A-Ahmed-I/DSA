# Height Checker Problem

## Problem Description

A school is trying to arrange students in a line in **non-decreasing order of height**.

You are given an array `heights` representing the current order of students.

Your task is to:

> Count how many indices where the current order does NOT match the expected sorted order.

[Original Problem](https://neetcode.io/problems/height-checker/question)

---

## Approach

1. Copy the original array.
2. Sort the copied array.
3. Compare both arrays index by index.
4. Count mismatches.

---

## Complexity

- Time Complexity: **O(n log n)** (due to sorting)
- Space Complexity: **O(n)**

---

## Examples

### Example 1

Input:

```
[1,1,4,2,1,3]
```

Output:

```
3
```

---

### Example 2

Input:

```
[5,1,2,3,4]
```

Output:

```
5
```

---

### Example 3

Input:

```
[1,2,3,4,5]
```

Output:

```
0
```

---

## Bonus Optimization (Counting Sort)

Since values are between **1 → 100**, we can use Counting Sort to achieve:

- Time Complexity: **O(n)**
- Space Complexity: **O(1)**
