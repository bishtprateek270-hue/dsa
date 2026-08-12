# 1. Two Sum

[LeetCode Problem Link](https://leetcode.com/problems/two-sum) | **Difficulty:** Easy

---

## 📌 Pattern
**Hash Map**

## 📝 Problem Statement
Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice. You can return the answer in any order.

---

## 💡 Approach

For every number at index `i`:

1. Calculate the complement:
   $$\text{needed} = \text{target} - \text{nums}[i]$$
2. Use an `unordered_map<int, int>` to store numbers that have already been seen, mapping `number -> index`.
3. Check if `needed` already exists in the map:
   - If found, return `{map[needed], i}` as the result.
   - If not found, store the current number and its index: `map[nums[i]] = i`.

---

## 🔍 Step-by-Step Example

```text
nums = [2, 7, 11, 15]
target = 9

For i = 0 (nums[0] = 2):
  needed = 9 - 2 = 7
  7 is not seen yet -> Store map[2] = 0

For i = 1 (nums[1] = 7):
  needed = 9 - 7 = 2
  2 exists in map at index 0!

Answer = [0, 1]
```

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$ — We iterate through the array of size $n$ once. Searching and insertion in `unordered_map` takes $\mathcal{O}(1)$ average time.
- **Space Complexity:** $\mathcal{O}(n)$ — In the worst case, we store up to $n$ elements in the hash map.

---

## 🔑 Key Learning
Hash maps allow us to look up whether a required complement value has already appeared in $\mathcal{O}(1)$ average time complexity.

## 🛠️ C++ Concept Used
- `std::unordered_map<int, int>` for fast key-value lookups.
- `mp.find(needed) != mp.end()` to check key existence in the map.
