class Solution {
#define ll long long
#define f(i, a, n) for (int i = a; i < n; i++)
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vector<ll>>

    static const ll MOD = 1e9 + 7;
    vvll comb;

    ll dfs(vi& nums) {
        int n = nums.size();
        if (n <= 2)
            return 1;
        int root = nums[0];
        vi left, right;
        f(i,1,n){
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }
        int L = left.size();
        int R = right.size();
        ll ways = comb[L + R][L];
        ways = ways * dfs(left) % MOD;
        ways = ways * dfs(right) % MOD;
        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        comb.assign(n, vll(n, 0));
        f(i, 0, n) {
            comb[i][0] = comb[i][i] = 1;
            f(j, 1, i) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};