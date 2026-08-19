# Beginner's Guide to Majority Element

Welcome! This guide explains the **Majority Element** problem step-by-step in simple, plain English.

---

## 🎯 What is the Problem Asking?

Given a list of numbers, find the **majority element**.

The **majority element** is defined as the number that appears **more than half the time** (more than $\lfloor N / 2 \rfloor$ times).

For example:
- `nums = [3, 2, 3]` $\rightarrow$ Total size = 3. `3` appears twice ($2 > 1.5$). Answer: `3`.
- `nums = [2, 2, 1, 1, 1, 2, 2]` $\rightarrow$ Total size = 7. `2` appears 4 times ($4 > 3.5$). Answer: `2`.

---

## 💡 The Real-Life Analogy: Frequency Counter

Imagine you are counting votes in a classroom election.

1. You create a score sheet (a Frequency Map).
2. Every time a vote comes in for candidate `X`, you add 1 to candidate `X`'s tally.
3. At the end, you look for the candidate who got more than 50% of all votes!

In C++, this score sheet is represented by an `unordered_map<int, int>`.

---

## 🕵️ Step-by-Step Walkthrough with an Example

Let's trace `nums = [3, 2, 3]`:

1. **Step 1: Count Frequencies**
   - Read `3`: Map becomes `{3: 1}`
   - Read `2`: Map becomes `{3: 1, 2: 1}`
   - Read `3`: Map becomes `{3: 2, 2: 1}`

2. **Step 2: Check Threshold**
   - Total size $N = 3$. Half size $N / 2 = 1.5$.
   - Look at `3`: count is `2`. Is $2 > 1$? **YES!**
   - Return `3`.

---

## 💻 Code & Line-by-Line Explanation

Here is the C++ code from `majority-element.cpp`:

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq; // Step 1: Create our vote-counter map

        // Step 2: Loop through each number in nums and count frequency
        for(int i : nums) {
            freq[i]++;
        }

        // Step 3: Find which number's count is strictly greater than N/2
        for(auto x : freq) {
            if(x.second > nums.size() / 2) {
                return x.first; // x.first is the number, x.second is its count
            }
        }

        return -1; // Fallback
    }
};
```

### Line-by-Line Breakdown:

- **Line 4: `unordered_map<int,int> freq;`**
  - Creates a hash map where keys are numbers from `nums`, and values are how many times each number appears.

- **Line 5-7: `for(int i : nums) { freq[i]++; }`**
  - Range-based for-loop. For every number `i` in `nums`, increment its count `freq[i]` by 1.

- **Line 8: `for(auto x : freq)`**
  - Loops through each key-value pair `x` stored inside our hash map `freq`.
  - `x.first` refers to the number value.
  - `x.second` refers to how many times that number appeared.

- **Line 9: `if(x.second > nums.size() / 2)`**
  - Checks if the count `x.second` is strictly greater than half the size of `nums`.

- **Line 10: `return x.first;`**
  - Returns the majority number as soon as we find it!

---

## ⏱️ How Fast Is It? (Complexity)

- **Time Complexity: $\mathcal{O}(N)$**  
  We loop through `nums` once to count frequencies, and then loop through the unique keys in `freq`.
- **Space Complexity: $\mathcal{O}(N)$**  
  In the worst case, we store counts for unique elements in the hash map.
