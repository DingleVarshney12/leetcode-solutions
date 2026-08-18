class Solution {
    
    /*
    //Recursive Method
    //Time Complexity: O(2^n)
    //Recursive Space: O(n)
    pair<int,int> solve(int i, vector<int>& nums){
        int bestLength = 1,ways = 1;
        for(int j = 0;j < i;j++){
            if(nums[j] < nums[i]){
                auto[ length,count] = solve(j,nums);
                int newLength = length +1;
                if(newLength > bestLength){
                    bestLength = newLength;
                    ways = count;
                }else if(newLength ==bestLength){
                    ways +=count;
                }
            }
        }
        return {bestLength,ways};
    }
    //Main function
    int maxLength = 0;
        int answer = 0;

        for(int i = 0; i < nums.size(); i++){
            auto [length, count] = solve(i, nums);
            if(length > maxLength){
                maxLength = length;
                answer = count;
            }else if(length ==maxLength){
                answer +=count;
            }
        }
        return answer;
    */

/*

    //Memorization Method
    //Time Complexity: O(n^2)
    //Space Complexity: O(n^2)
    //Recursive Space: O(n)

    pair<int,int> solve(int i , int prev, vector<int>&nums,vector<vector<pair<int,int>>>& dp){
        if(i == nums.size()) return {0,1};
        if(dp[i][prev+1].first != -1) return dp[i][prev+1];
        pair<int,int> take = {-1,0};
        auto nottake = solve(i+1,prev,nums,dp);
        if(prev == -1 || nums[i] > nums[prev]){
            take = solve(i+1,i,nums,dp);
            take.first++;
        }

        if(take.first > nottake.first){
            return dp[i][prev+1] = take;
        }else if(take.first < nottake.first){
            return dp[i][prev+1] = nottake;
        }else{
            return dp[i][prev+1] = {take.first,take.second + nottake.second};
        }

        //Main Function
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n+1,{-1,-1}));
        return solve(0,-1,nums,dp).second;
    }*/
public:
    int findNumberOfLIS(vector<int>& nums) {
        //Tabulation Method :
        // Time Complexity : O(n^2)
        // Space complexity: O(n)
        int n = nums.size();
        vector<int> length(n,1);
        vector<int> count(n,1);
        for(int i = 0;i < n;i++){
            for(int prev = 0; prev<i;prev++){
                if(nums[i] > nums[prev]){
                    if(length[prev] +1 > length[i]){
                        length[i] =  length[prev]  + 1;
                        count[i] = count[prev];
                    }else if(length[prev] +1 == length[i]){
                        count[i]+=count[prev];
                    }
                }
            }
        }
        int maximum = *max_element(length.begin(),length.end());
        int ans = 0;
        for(int i = 0;i <n;i++){
            if(length[i] == maximum){
                ans += count[i];
            }
        }
        return ans;
    }
};