# Beginner's Guide to Contains Duplicate

Welcome! This guide explains the **Contains Duplicate** problem step-by-step in simple, plain English.

---

## 🎯 What is the Problem Asking?

Given a list of numbers `nums`, check if any number appears **at least twice** in the list.

- Return **`true`** if there is any duplicate.
- Return **`false`** if every single number is unique.

### Examples:
- `[1, 2, 3, 1]` $\rightarrow$ `true` (The number `1` appears twice).
- `[1, 2, 3, 4]` $\rightarrow$ `false` (All numbers are unique).

---

## 💡 The Real-Life Analogy: The VIP Guest Checklist

Imagine security at a venue checking guests in:

### ❌ The Slow Way:
For every guest coming in, you look through all previous tickets from start to finish. If the list has 10,000 guests, this gets extremely slow ($\mathcal{O}(N^2)$ time).

### ✅ The Smart Way (Hash Set):
Security keeps a **VIP Box** (Hash Set):
1. When a guest arrives, security checks: *"Is this name inside the VIP Box?"*
2. **If YES:** "Stop right there! You've already checked in!" $\rightarrow$ Return `true`!
3. **If NO:** Put their name inside the VIP Box and let them in.

In C++, a "VIP Box that stores unique items" is called an `unordered_set`.

---

## 🕵️ Step-by-Step Walkthrough with an Example

Let's trace `nums = [1, 2, 3, 1]`:

1. **Index 0 (Value = 1):**
   - Is `1` in set `s`? **No**, set is `{}`.
   - Insert `1` into set $\rightarrow$ Set becomes `{1}`.

2. **Index 1 (Value = 2):**
   - Is `2` in set `s`? **No**.
   - Insert `2` into set $\rightarrow$ Set becomes `{1, 2}`.

3. **Index 2 (Value = 3):**
   - Is `3` in set `s`? **No**.
   - Insert `3` into set $\rightarrow$ Set becomes `{1, 2, 3}`.

4. **Index 3 (Value = 1):**
   - Is `1` in set `s`? **YES!**
   - Return **`true`** immediately! 🎉

---

## 💻 Code & Line-by-Line Explanation

Here is the C++ code from `contains-duplicate.cpp`:

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s; // Step 1: Create our empty Hash Set

        for(int i : nums) {   // Step 2: Loop through each number in nums
            // Step 3: If number i is already inside the set
            if(s.find(i) != s.end()) {
                return true;  // Duplicate detected!
            }
            // Step 4: Add number i to the set
            s.insert(i);
        }

        return false; // Loop finished with zero duplicates
    }
};
```

### Line-by-Line Breakdown:

- **Line 4: `unordered_set<int> s;`**
  - Creates a hash set. A set automatically handles lookup in $\mathcal{O}(1)$ average constant time.

- **Line 5: `for(int i : nums)`**
  - Iterates over each number `i` in array `nums`.

- **Line 6: `if(s.find(i) != s.end())`**
  - `s.find(i)` looks for `i` in the set.
  - `!= s.end()` means *"The number was found in the set!"*

- **Line 7: `return true;`**
  - We immediately stop and return `true` as soon as a duplicate is spotted.

- **Line 9: `s.insert(i);`**
  - Adds current number `i` to the set so it can be checked against future numbers in the loop.

---

## ⏱️ How Fast Is It? (Complexity)

- **Time Complexity: $\mathcal{O}(N)$**  
  We only walk through the array once. Checking or inserting into `unordered_set` takes $\mathcal{O}(1)$ time on average.
- **Space Complexity: $\mathcal{O}(N)$**  
  In the worst case (when no duplicates exist), the set stores all $N$ numbers.
