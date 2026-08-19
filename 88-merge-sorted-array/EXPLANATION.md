# Beginner's Guide to Merge Sorted Array

Welcome! If you are learning how to combine and sort arrays, this guide explains **Merge Sorted Array** in simple, plain English.

---

## 🎯 What is the Problem Asking?

You are given two lists of numbers, `nums1` and `nums2`. Both lists are **already sorted** from smallest to largest.

Your goal is to **merge `nums2` into `nums1`** so that `nums1` becomes one big sorted list.

### Catch / Twist:
`nums1` has extra blank space (`0`s) added at the end, exactly big enough to fit all elements of `nums2`. You must modify `nums1` **directly in-place** without creating a brand new list!

---

## 💡 The Real-Life Analogy: Merging Two Queues

Imagine two lines of students arranged by height (shortest to tallest).

- `nums1`: `[1, 3, 5, _, _, _]` (3 tall students + 3 empty spots at the back)
- `nums2`: `[2, 4, 6]` (3 students)

### Why merging from FRONT is hard:
If you compare `1` and `2` at the front and try to put `1` at the beginning, you have to shift all other students to the right, which gets messy and slow!

### 💡 The Genius Trick: Merge from the BACK!
Since the back of `nums1` contains empty spots (`_`), we can compare the **tallest** students in both lines and place the tallest one into the **very last empty spot**!

---

## 🕵️ Step-by-Step Walkthrough with an Example

Let's trace `nums1 = [1, 2, 3, 0, 0, 0]` (`m = 3`) and `nums2 = [2, 5, 6]` (`n = 3`):

We set 3 pointers (fingers):
- `i = 2` (points to `3`, the last valid number in `nums1`)
- `j = 2` (points to `6`, the last number in `nums2`)
- `k = 5` (points to the last empty spot in `nums1`)

```text
Step 1: Compare nums1[i] (3) vs nums2[j] (6).
        6 is bigger! Put 6 at nums1[k] (index 5).
        Move j to index 1, move k to index 4.
        nums1 looks like: [1, 2, 3, 0, 0, 6]

Step 2: Compare nums1[i] (3) vs nums2[j] (5).
        5 is bigger! Put 5 at nums1[k] (index 4).
        Move j to index 0, move k to index 3.
        nums1 looks like: [1, 2, 3, 0, 5, 6]

Step 3: Compare nums1[i] (3) vs nums2[j] (2).
        3 is bigger! Put 3 at nums1[k] (index 3).
        Move i to index 1, move k to index 2.
        nums1 looks like: [1, 2, 3, 3, 5, 6]

Step 4: Compare nums1[i] (2) vs nums2[j] (2).
        Equal! Put nums2's 2 at nums1[k] (index 2).
        Move j to index -1 (nums2 is empty!), move k to index 1.
        nums1 looks like: [1, 2, 2, 3, 5, 6]

Done! nums2 is completely placed.
```

---

## 💻 Code & Line-by-Line Explanation

Here is the C++ code from `merge-sorted-array.cpp`:

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;     // Pointer 1: Last valid item in nums1
        int j = n - 1;     // Pointer 2: Last item in nums2
        int k = m + n - 1; // Pointer 3: Last empty slot in nums1

        // Loop as long as BOTH arrays have numbers to compare
        while(i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i]; // Place larger item from nums1
                i--;
            } else {
                nums1[k] = nums2[j]; // Place larger item from nums2
                j--;
            }
            k--; // Move to the next empty spot to the left
        }

        // If there are still numbers left in nums2, copy them over
        while(j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
```

### Line-by-Line Breakdown:

- **Line 5-7: Setting up the 3 Pointers**
  - `i = m - 1` gets the last real number of `nums1`.
  - `j = n - 1` gets the last number of `nums2`.
  - `k = m + n - 1` gets the end position of `nums1`.

- **Line 9: `while(i >= 0 && j >= 0)`**
  - Keeps comparing elements until we reach the beginning of either `nums1` or `nums2`.

- **Lines 10-17: Pick the Larger Value**
  - Whichever number is bigger gets copied into `nums1[k]`.
  - Decrement `i` or `j` to move left in that array, and decrement `k` to move left in the merged array.

- **Lines 20-24: `while(j >= 0)`**
  - If `nums2` still has numbers left after `nums1` numbers run out, we copy them directly into the remaining front slots of `nums1`.

---

## ⏱️ How Fast Is It? (Complexity)

- **Time Complexity: $\mathcal{O}(m + n)$**  
  We examine each element at most once in a single backward pass.
- **Space Complexity: $\mathcal{O}(1)$**  
  We do all changes inside `nums1` directly without using any extra arrays!
