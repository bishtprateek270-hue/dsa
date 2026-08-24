class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprofit = prices[0];
        int maxprofit = 0;
        for(int i =1; i<prices.size();i++){
            int profit = prices[i] - minprofit;
            maxprofit = max(maxprofit,profit);
            minprofit = min(minprofit,prices[i]);
        }
        return maxprofit;
    }
};