class Solution {
    
//This solution is based on https://leetcode.com/problems/minimum-cost-for-tickets/discuss/226659/Two-DP-solutions-with-pictures
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travel(begin(days), end(days));
        int dp[366] = {};
        for(int i = 1; i < 366; i++) {
            if(travel.find(i) == travel.end()) {
                dp[i] = dp[i - 1];
            } else {
                // cumulative cost is recorded for every day to dp[i]
                // i's day cost will be min of cost of i - 1 + costs[0], cost of i - 7 + costs[1], cost of i - 30 + costs[2]
                dp[i] = min({ dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]});
            }
        }
        return dp[365];
    }
};
