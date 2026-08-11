class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();    
        int prev1 = cost[1];
        int prev2 = cost[0];
        for(int i = 2; i<n;i++){
            int curr = cost[i] + min(prev1,prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1,prev2);

    }
};