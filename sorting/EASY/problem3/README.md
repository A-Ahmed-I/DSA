# Majority Element

## Problem Overview

Given an array `nums` of size `n`, return the majority element.

The majority element is the element that appears more than $\left\lfloor n/2 \right\rfloor$ times in the array. You may assume that the majority element always exists.

[Original Problem](https://neetcode.io/problems/majority-element/question)

---

## Examples

### Example 1

```cpp
Input: nums = [5, 5, 1, 1, 1, 5, 5]
Output: 5
```

### Example 2

```cpp
Input: nums = [2, 2, 2]
Output: 2
```

---

## Approach (Boyer-Moore Voting Algorithm)

### Key Idea

- Keep track of a candidate element and a counter.
- Traverse the array once.
- If the current element matches the candidate, increase the counter.
- Otherwise, decrease the counter.
- When the counter becomes zero, reset the candidate and continue.
- The remaining candidate is the majority element.

---

## Why it Works

- If an element appears more than half the time, it will survive the cancellation process.
- Every time a different element is paired with it, the counter is reduced.
- After processing all elements, the remaining candidate must be the majority element.

---

## Complexity Analysis

| Complexity | Value |
| ---------- | ----- |
| Time       | O(n)  |
| Space      | O(n)  |

- **Time:** Single pass through the array.
- **Space:** Constant extra space.

---
