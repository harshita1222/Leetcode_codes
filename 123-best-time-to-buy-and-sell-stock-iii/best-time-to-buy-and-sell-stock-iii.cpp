class Solution {
public:
    int market(vector<int>& prices, int ind, int buy, int cap, int n, vector<vector<vector<int>>>& memo) {
        if (ind == n || cap == 0) return 0;
        if (memo[ind][buy][cap] != -1) return memo[ind][buy][cap];
        if (buy) 
            return memo[ind][buy][cap] = max(-prices[ind] + market(prices, ind + 1, 0, cap, n, memo),
                                             market(prices, ind + 1, 1, cap, n, memo));
        return memo[ind][buy][cap] = max(prices[ind] + market(prices, ind + 1, 1, cap - 1, n, memo),
                                         market(prices, ind + 1, 0, cap, n, memo));
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return market(prices, 0, 1, 2, n, memo);
    }
};