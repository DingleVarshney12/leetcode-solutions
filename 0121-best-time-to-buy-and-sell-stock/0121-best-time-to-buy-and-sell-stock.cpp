class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int ans = 0;
        for(auto currPrice:prices){
           minPrice = min(minPrice,currPrice);
           int profit = currPrice - minPrice;
            ans = max(ans,profit);
        }
        return ans;
    }
};