# Beginner's Guide to Valid Anagram

Welcome! This guide explains the **Valid Anagram** problem step-by-step in simple, plain English.

---

## 🎯 What is the Problem Asking?

You are given two words (strings): `s` and `t`.

Your goal is to check if `t` is an **anagram** of `s`.

### What is an Anagram?
An anagram means both words contain **the exact same letters**, with **the exact same frequencies**, just rearranged in a different order.

### Examples:
- `s = "anagram"`, `t = "nagaram"` $\rightarrow$ **`true`** (Both have 3 'a's, 1 'n', 1 'g', 1 'r', 1 'm').
- `s = "rat"`, `t = "car"` $\rightarrow$ **`false`** ('rat' has 't', 'car' has 'c').

---

## 💡 The Real-Life Analogy: Grocery Inventory Balance

Imagine you manage inventory for two fruit baskets:

1. **Basket S:** You count every fruit added.
   - For string `"anagram"`, you record: `+3 apples ('a')`, `+1 banana ('n')`, `+1 grape ('g')`, `+1 raisin ('r')`, `+1 mango ('m')`.
2. **Basket T:** You subtract every fruit taken out.
   - For string `"nagaram"`, you record: `-1 banana ('n')`, `-3 apples ('a')`, `-1 grape ('g')`, `-1 raisin ('r')`, `-1 mango ('m')`.
3. **Final Audit:** If all fruit inventory counts end up at **exactly 0**, the two baskets matched perfectly!

---

## 🕵️ Step-by-Step Walkthrough with an Example

Let's trace `s = "rat"`, `t = "car"`:

1. **Check Length:**
   - Length of `s` = 3, Length of `t` = 3. Equal length $\rightarrow$ proceed!

2. **Count characters in `s = "rat"`:**
   - Map: `{'r': 1, 'a': 1, 't': 1}`

3. **Subtract characters in `t = "car"`:**
   - Process `'c'`: `c` wasn't in map, count for `'c'` becomes `-1`.
   - Process `'a'`: `count('a') = 1 - 1 = 0`.
   - Process `'r'`: `count('r') = 1 - 1 = 0`.
   - Map now looks like: `{'r': 0, 'a': 0, 't': 1, 'c': -1}`

4. **Audit Map:**
   - Count for `'t'` is `1` ($\neq 0$) and `'c'` is `-1` ($\neq 0$).
   - Return **`false`**!

---

## 💻 Code & Line-by-Line Explanation

Here is the C++ code from `valid-anagram.cpp`:

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        // Step 1: Anagrams MUST have equal lengths!
        if(s.length() != t.length()) {
            return false;
        }

        unordered_map<char,int> mp; // Step 2: Create our character inventory map

        // Step 3: Add counts for string s
        for (char c : s) {
            mp[c]++;
        }

        // Step 4: Subtract counts for string t
        for(char c : t) {
            mp[c]--;
        }

        // Step 5: Check if every single character count returned back to zero
        for(auto x : mp) {
            if(x.second != 0) {
                return false;
            }
        }

        return true; // All counts are 0! Valid anagram.
    }
};
```

### Line-by-Line Breakdown:

- **Line 4-6: Length Guard**
  - If `s` has 5 letters and `t` has 4 letters, they can't be anagrams. Return `false` immediately.

- **Line 8: `unordered_map<char,int> mp;`**
  - Creates a map storing `char` (letter) as key and `int` (frequency count) as value.

- **Lines 10-12: Increment Loop**
  - For each character `c` in string `s`, increment `mp[c]`.

- **Lines 14-16: Decrement Loop**
  - For each character `c` in string `t`, decrement `mp[c]`.

- **Lines 18-22: Audit Loop**
  - Iterate over map `mp`. If any character count `x.second` is not zero, return `false`.

---

## ⏱️ How Fast Is It? (Complexity)

- **Time Complexity: $\mathcal{O}(N)$**  
  We process each character in `s` and `t` once.
- **Space Complexity: $\mathcal{O}(K)$**  
  Where $K$ is the number of unique characters (at most 26 for English lowercase letters).
