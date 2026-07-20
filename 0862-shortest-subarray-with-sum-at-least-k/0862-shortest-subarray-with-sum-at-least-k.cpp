class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<long long> prefix(n+1,0);
        int ans=INT_MAX;
        prefix[0] = 0;
        for(int idx = 0; idx < n; idx++){
            prefix[idx+1]=prefix[idx] + nums[idx];
        }
        for(int i = 0 ; i < prefix.size();i++){
            while(!dq.empty() && prefix[i] - prefix[dq.front()] >= k){
                ans = min(ans,i-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && prefix[dq.back()] >=prefix[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        if(ans == INT_MAX)return -1;
        return ans;
    }
};