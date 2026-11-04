//understand from  Codestorywithmik yt
class Solution {
    int n, x, k;
    long long minOps[100001];
    long long memo[16][100001];
    long long solve(int count, int i){
        if(count == k) return 0;

        int subArrayNeeded = k - count;
        int elementsNeeded = subArrayNeeded * x;
        int lastIndex = i + elementsNeeded - 1;

        if(lastIndex >= n) return 1e15;
        if(memo[count][i] != -1) return memo[count][i];
        long long result = minOps[i] + solve(count + 1,i + x);

        result = min(result,solve(count,i+1));

        return memo[count][i] =  result;
    }
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        this->n = nums.size();
        this->x = x;
        this->k = k;
        memset(memo, -1, sizeof(memo));
        multiset<int> l,r;
        long long lSum = 0, rSum = 0;
        int i = 0, j = 0;
        while(j < n){
            if(l.size() <= r.size()){
                l.insert(nums[j]);
                lSum += nums[j];
            }else{
                r.insert(nums[j]);
                rSum+=nums[j];
            }
            if(!l.empty()&&!r.empty()){
                int maxLeft = *l.rbegin();
                int minRight = *r.begin();
                if(maxLeft > minRight){
                    l.erase(l.find(maxLeft));
                    r.erase(r.find(minRight));
                    l.insert(minRight);
                    r.insert(maxLeft);
                    lSum += minRight - maxLeft;
                    rSum += maxLeft - minRight;
                }

            }
            if(j - i + 1 == x){
                long long median = *l.rbegin();
                long long lSize = l.size();
                long long rSize = r.size();
                minOps[i] = (lSize * median - lSum) + (rSum - rSize * median);

                if(l.find(nums[i]) != l.end()){
                    l.erase(l.find(nums[i]));
                    lSum -= nums[i];
                }else {
                    r.erase(r.find(nums[i]));
                    rSum -= nums[i];
                }
                i++;
            }
            j++;
        }
        return solve(0,0);
    }
};