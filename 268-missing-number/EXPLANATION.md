# Beginner's Guide to Missing Number

Welcome! This guide explains the **Missing Number** problem step-by-step in simple, plain English.

---

## 🎯 What is the Problem Asking?

You are given an array `nums` containing $N$ distinct numbers taken from the range `[0, N]`.

Because the range contains $N + 1$ total numbers, **exactly one number is missing**. You need to find and return that missing number.

### Examples:
- `nums = [3, 0, 1]` ($N = 3$, expected range `[0, 1, 2, 3]`).
  - Present: `0, 1, 3`
  - Missing: **`2`**

- `nums = [0, 1]` ($N = 2$, expected range `[0, 1, 2]`).
  - Present: `0, 1`
  - Missing: **`2`**

---

## 💡 The Real-Life Analogy: Roll Call / Attendance

Imagine a classroom of 4 students assigned numbers `0, 1, 2, 3`.

### Hash Set Approach (Checking Off Names)
1. You put all present students in a group (`s = {3, 0, 1}`).
2. You call out numbers from `0` to `3` one by one:
   - "Number 0?" $\rightarrow$ Here!
   - "Number 1?" $\rightarrow$ Here!
   - "Number 2?" $\rightarrow$ Silent... (Found the missing student!).

In C++, we use an `unordered_set` for this.

---

## 🕵️ Step-by-Step Walkthrough with an Example

Let's trace `nums = [3, 0, 1]`:

1. **Step 1: Build the Set**
   - Read `3` $\rightarrow$ Set: `{3}`
   - Read `0` $\rightarrow$ Set: `{3, 0}`
   - Read `1` $\rightarrow$ Set: `{3, 0, 1}`

2. **Step 2: Check Range `0` to `3`**
   - Check `i = 0`: Is `0` in set? Yes.
   - Check `i = 1`: Is `1` in set? Yes.
   - Check `i = 2`: Is `2` in set? **NO!**
   - Return **`2`**!

---

## 💻 Code & Line-by-Line Explanation

Here is the C++ code from `missing-number.cpp`:

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> s; // Step 1: Create our empty attendance set

        // Step 2: Insert every present number into the set
        for(int i : nums) {
            s.insert(i);
        }

        // Step 3: Check numbers from 0 up to nums.size()
        for(int i = 0; i <= nums.size(); i++) {
            if(s.find(i) == s.end()) {
                return i; // Number i was not found in the set!
            }
        }

        return -1; // Fallback
    }
};
```

### Line-by-Line Breakdown:

- **Line 4: `unordered_set<int> s;`**
  - Creates a hash set to store all values from `nums`.

- **Lines 6-8: `for(int i : nums) { s.insert(i); }`**
  - Iterates through `nums` and inserts every number into the hash set.

- **Line 11: `for(int i = 0; i <= nums.size(); i++)`**
  - Loops `i` from `0` all the way up to `nums.size()` (inclusive). Note `<=`, because if array size is `3`, the valid numbers are `0, 1, 2, 3`.

- **Line 12: `if(s.find(i) == s.end())`**
  - Checks if number `i` is missing from the set.
  - `== s.end()` means *"We searched the set and couldn't find `i`!"*

- **Line 13: `return i;`**
  - Returns the missing number `i`.

---

## ⏱️ How Fast Is It? (Complexity)

- **Time Complexity: $\mathcal{O}(N)$**  
  We insert $N$ items into the set and do up to $N+1$ lookups. Each lookup takes $\mathcal{O}(1)$ time.
- **Space Complexity: $\mathcal{O}(N)$**  
  The hash set stores $N$ elements.
