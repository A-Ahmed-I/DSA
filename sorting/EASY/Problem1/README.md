# Contains Duplicate

## Problem Overview

Given an integer array `nums`, determine whether any value appears **at least twice**.

- Return `true` if any duplicate exists.
- Return `false` if all elements are distinct.

[Original Problem](https://neetcode.io/problems/duplicate-integer/question?list=neetcode150)

---

## Examples

### Example 1

```
Input: nums = [1, 2, 3, 1]
Output: true
```

### Example 2

```
Input: nums = [1, 2, 3, 4]
Output: false
```

---

## Approach

### Key Idea

Use a **Hash Set (unordered_set)** to track unique elements.

- Convert the array into a set.
- If duplicates exist, the set size will be **smaller** than the array size.

### Why it works

A set automatically removes duplicate values.  
So:

```
If set size != original size → duplicates exist
```

---

## Complexity Analysis

| Complexity | Value |
| ---------- | ----- |
| Time       | O(n)  |
| Space      | O(n)  |

- **Time:** We iterate through the array once.
- **Space:** Extra memory for the set.

---
