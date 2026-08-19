# Beginner's Guide to Two Sum

Welcome! If you are new to Data Structures and Algorithms (DSA), this guide will walk you through the **Two Sum** problem step-by-step in simple, plain English.

---

## 🎯 What is the Problem Asking?

Imagine you have a list of numbers: `[2, 7, 11, 15]` and a target number: `9`.

Your goal is to find **two numbers from the list that add up to 9**, and return their **position numbers (indices)** in the list.

- Number at index `0` is `2`.
- Number at index `1` is `7`.
- `2 + 7 = 9` (Target reached!)
- Answer: `[0, 1]`

---

## 💡 The Real-Life Analogy: The Party Notebook

Imagine you are at a party looking for a "buddy" whose age + your age = Target (e.g. 9).

### ❌ The Slow Way (Brute Force)
You walk up to every person in the party one by one and ask: *"Will your age plus my age equal 9?"*
- If there are 100 people, you might have to make 10,000 comparisons!
- In programming, this takes $\mathcal{O}(N^2)$ time (very slow).

### ✅ The Smart Way (Hash Map / Notebook)
Instead of asking everyone, there is a **Notebook** placed at the entrance door:

1. When you enter, you calculate: *"I am 7 years old. I need a buddy who is $9 - 7 = 2$ years old."*
2. You look at the notebook to see if anyone aged **2** has already entered:
   - **If YES:** You grab their name/index from the notebook and you're done! 🎉
   - **If NO:** You write down your age (**7**) and your position in the notebook so future guests can find you.

In C++, this "Notebook" is called an `unordered_map`.

---

## 🕵️ Step-by-Step Walkthrough with an Example

Let's trace `nums = [2, 7, 11, 15]` with `target = 9`:

1. **Start at index 0 (Value = 2):**
   - We need: `9 - 2 = 7`.
   - Is `7` in our notebook? **No**, the notebook is empty `{}`.
   - Action: Add `2` with index `0` to notebook $\rightarrow$ Notebook: `{2: 0}`.

2. **Move to index 1 (Value = 7):**
   - We need: `9 - 7 = 2`.
   - Is `2` in our notebook? **YES!** It's stored at index `0`.
   - Action: We found our answer! Return `[0, 1]`.

---

## 💻 Code & Line-by-Line Explanation

Here is the C++ code from `two-sum.cpp`:

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp; // Step 1: Create our empty notebook

        for(int i = 0; i < nums.size(); i++) { // Step 2: Loop through each number
            int needed = target - nums[i];     // Step 3: Calculate the buddy number needed

            // Step 4: Check if the needed buddy is already in the notebook
            if(mp.find(needed) != mp.end()) {
                return {mp[needed], i};        // Found! Return buddy's index and current index
            }

            // Step 5: Buddy not found yet. Write current number & index in notebook
            mp[nums[i]] = i;
        }

        return {}; // Return empty if no solution exists
    }
};
```

### Line-by-Line Breakdown:

- **Line 4: `unordered_map<int,int> mp;`**
  - Creates a hash table (our notebook).
  - The first `int` stores the **number value** (e.g., `2`).
  - The second `int` stores its **index position** (e.g., `0`).

- **Line 5: `for(int i = 0; i < nums.size(); i++)`**
  - A simple loop visiting every element in `nums` one by one, using index `i`.

- **Line 6: `int needed = target - nums[i];`**
  - Figures out what partner number we are searching for.

- **Line 7: `if(mp.find(needed) != mp.end())`**
  - `mp.find(needed)` searches our notebook in ultra-fast $\mathcal{O}(1)$ constant time.
  - `!= mp.end()` means *"We found it! It exists in our map."*

- **Line 8: `return {mp[needed], i};`**
  - Constructs and returns a pair containing `[partner_index, current_index]`.

- **Line 10: `mp[nums[i]] = i;`**
  - Saves the current number into the notebook so that any subsequent number in the loop can pair with it if needed.

---

## ⏱️ How Fast Is It? (Complexity)

- **Time Complexity: $\mathcal{O}(N)$**  
  We only walk through the list once! Searching the notebook takes instantaneous time on average.
- **Space Complexity: $\mathcal{O}(N)$**  
  In the worst case, we store up to $N$ numbers in our notebook.
