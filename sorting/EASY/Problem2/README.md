# Valid Anagram

## Problem Overview

Given two strings `s` and `t`, return `true` if `t` is an **anagram** of `s`, otherwise return `false`.

An **anagram** is a word formed by rearranging the letters of another word using **all original characters exactly once**.

[Original Problem](https://neetcode.io/problems/is-anagram/question?list=neetcode150)

---

## Examples

### Example 1

```
Input: s = "anagram", t = "nagaram"
Output: true
```

### Example 2

```
Input: s = "rat", t = "car"
Output: false
```

---

## Approach (Frequency Count)

### Key Idea

- Use an array of size 26 to count character frequencies.
- Increment for characters in `s`.
- Decrement for characters in `t`.
- If all values are zero → both strings are anagrams.

---

## Why it Works

- Both strings must have the **same characters with the same frequency**.
- Any mismatch will leave a non-zero value in the frequency array.

---

## Complexity Analysis

| Complexity | Value |
| ---------- | ----- |
| Time       | O(n)  |
| Space      | O(1)  |

- **Time:** One pass through both strings.
- **Space:** Fixed array of size 26 (constant space).

---

## Alternative Approaches

### 1. Sorting

```cpp
bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}
```

- Time: O(n log n)
- Space: O(1)

---

### 2. Hash Map (for Unicode)

```cpp
unordered_map<char, int> freq;

for (char c : s) freq[c]++;
for (char c : t) freq[c]--;

for (auto &p : freq)
    if (p.second != 0) return false;

return true;
```

- Useful when characters are **not limited to lowercase English letters**

---
