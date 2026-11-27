class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> copies(n,0);
        int minPrice = INT_MAX;
        for(int i = 0; i < n; i++){
            minPrice = min(minPrice,items[i][1]);
            int copy = 0;
            for(int j = 0; j < n; j++){
                if(i != j && items[j][0] % items[i][0] == 0) copy++;
            }
            copies[i] = copy;
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(budget + 1, 0));
        for(int i = 0; i <= budget; i++) dp[0][i] = i/minPrice;
        for(int i = 1; i <= n; i++){
            int price = items[i-1][1];
            for(int j = 0; j <= budget; j++){
                int take = 0;
                if( price <= j) {
                    take =  copies[i-1] + dp[i-1][j - price] + 1;
                    if(j >= 2 * price)
                        take = max(take, 1 + dp[i][j-price]);
                }
                int skip = dp[i-1][j];
                dp[i][j] = max(take,skip);
            }
        }
        return dp[n][budget];

    }
};