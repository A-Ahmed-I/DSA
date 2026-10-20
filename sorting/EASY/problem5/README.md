# Maximum Product Difference Between Two Pairs

## Problem Description

You are given an integer array `nums`.

Your task is to choose **four distinct indices**:

- `(w, x)` → first pair
- `(y, z)` → second pair

Such that the following value is **maximized**:

```
(nums[w] * nums[x]) - (nums[y] * nums[z])
```

[Original Problem](https://neetcode.io/problems/maximum-product-difference-between-two-pairs/question)

---

## Key Idea

To maximize the product difference:

- Choose the **two largest numbers** → maximize the first product
- Choose the **two smallest numbers** → minimize the second product

Final formula:

```
(max1 * max2) - (min1 * min2)
```

---

## Approach

1. Sort the array
2. Take:
   - The two largest elements
   - The two smallest elements

3. Compute the result

---

## Complexity

- Time Complexity: **O(n log n)** (due to sorting)
- Space Complexity: **O(1)**

---

## Examples

### Example 1

Input:

```
nums = [5,6,2,7,4]
```

Output:

```
34
```

---

### Example 2

Input:

```
nums = [4,2,5,9,7,4,8]
```

Output:

```
64
```

---

## Optimized Approach (O(n))

Instead of sorting, you can scan the array once and track:

- The two largest numbers
- The two smallest numbers

---

## Optimized C++ Code

```cpp
class Solution
{
public:
    int maxProductDifference(vector<int>& nums)
    {
        int max1 = 0, max2 = 0;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int num : nums)
        {
            // track largest
            if (num > max1)
            {
                max2 = max1;
                max1 = num;
            }
            else if (num > max2)
            {
                max2 = num;
            }

            // track smallest
            if (num < min1)
            {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2)
            {
                min2 = num;
            }
        }

        return (max1 * max2) - (min1 * min2);
    }
};
```
