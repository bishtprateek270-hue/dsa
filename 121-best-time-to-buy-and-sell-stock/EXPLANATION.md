# Beginner's Guide to Best Time to Buy and Sell Stock

Welcome! This guide explains the **Best Time to Buy and Sell Stock** problem step-by-step in simple, plain English.

---

## 🎯 What is the Problem Asking?

Given an array `prices` where `prices[i]` is the price of a stock on day `i`, find the **maximum profit** you can make by:
1. Buying on one single day.
2. Selling on a **future** day.

- Return the maximum profit.
- If no profit can be made (prices only decrease), return `0`.

### Examples:
- `prices = [7, 1, 5, 3, 6, 4]` $\rightarrow$ `5` (Buy on day 2 at price `1`, sell on day 5 at price `6`. Profit = $6 - 1 = 5$).
- `prices = [7, 6, 4, 3, 1]` $\rightarrow$ `0` (Prices keep going down, so no profitable transaction can be made).

---

## 💡 The Real-Life Analogy: The Bargain Hunter

Imagine you are tracking price tags of an item over a week:

1. As days pass, you always remember the **cheapest price seen so far** (`minprofit` / lowest buying price).
2. For today's price, you calculate: *"If I bought at the absolute lowest price seen before and sell today, how much profit would I make?"*
3. You keep track of the **highest profit** encountered (`maxprofit`).
4. Update your record for the lowest buying price if today's price is even cheaper!

---

## 🕵️ Step-by-Step Walkthrough with an Example

Let's trace `prices = [7, 1, 5, 3, 6, 4]`:

- **Initial State:**
  - `minprofit = prices[0] = 7` (Cheapest price so far)
  - `maxprofit = 0` (Highest profit so far)

1. **Day 1 (`i = 1`, Price = `1`):**
   - Current profit if sold today: `1 - 7 = -6`
   - Update `maxprofit = max(0, -6) = 0`
   - Update `minprofit = min(7, 1) = 1` (New lowest price found!)

2. **Day 2 (`i = 2`, Price = `5`):**
   - Current profit if sold today: `5 - 1 = 4`
   - Update `maxprofit = max(0, 4) = 4`
   - `minprofit = min(1, 5) = 1`

3. **Day 3 (`i = 3`, Price = `3`):**
   - Current profit if sold today: `3 - 1 = 2`
   - Update `maxprofit = max(4, 2) = 4`
   - `minprofit = min(1, 3) = 1`

4. **Day 4 (`i = 4`, Price = `6`):**
   - Current profit if sold today: `6 - 1 = 5`
   - Update `maxprofit = max(4, 5) = 5` (New max profit!)
   - `minprofit = min(1, 6) = 1`

5. **Day 5 (`i = 5`, Price = `4`):**
   - Current profit if sold today: `4 - 1 = 3`
   - Update `maxprofit = max(5, 3) = 5`
   - `minprofit = min(1, 4) = 1`

- **Final Result:** `maxprofit = 5`.

---

## 💻 Code & Line-by-Line Explanation

Here is the C++ code from `best-time-to-buy-and-sell-stock.cpp`:

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprofit = prices[0];
        int maxprofit = 0;
        for(int i = 1; i < prices.size(); i++){
            int profit = prices[i] - minprofit;
            maxprofit = max(maxprofit, profit);
            minprofit = min(minprofit, prices[i]);
        }
        return maxprofit;
    }
};
```

### Line-by-Line Breakdown:

- **Line 4: `int minprofit = prices[0];`**
  - Initializes `minprofit` to the stock price on the very first day (day 0).

- **Line 5: `int maxprofit = 0;`**
  - Initializes `maxprofit` to `0` (since we cannot make negative profit; if no transaction yields profit, we return 0).

- **Line 6: `for(int i = 1; i < prices.size(); i++)`**
  - Iterates through the stock prices starting from day 1 to the last day.

- **Line 7: `int profit = prices[i] - minprofit;`**
  - Calculates the profit if we were to sell on day `i` after buying at the lowest price seen so far (`minprofit`).

- **Line 8: `maxprofit = max(maxprofit, profit);`**
  - Updates `maxprofit` if the current `profit` is greater than our previous recorded maximum profit.

- **Line 9: `minprofit = min(minprofit, prices[i]);`**
  - Updates `minprofit` if today's stock price `prices[i]` is lower than any price we've seen previously.

- **Line 11: `return maxprofit;`**
  - Returns the maximum profit possible.

---

## ⏱️ How Fast Is It? (Complexity)

- **Time Complexity: $\mathcal{O}(N)$**  
  We iterate through the array `prices` of size $N$ exactly once in a single pass.
- **Space Complexity: $\mathcal{O}(1)$**  
  We only use two integer variables (`minprofit` and `maxprofit`), so space usage is constant.
