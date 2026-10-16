class Solution {
    using ll = long long;
    static const ll MOD = 1e9 + 7;

    vector<ll> sum, sumSq, lazy;

    void apply(int node, int l, int r, ll k = 1) {
        ll len = r - l + 1;

        sumSq[node] = (
            sumSq[node] + 2LL * k * sum[node] % MOD
            + k * k % MOD * len % MOD
        ) % MOD;

        sum[node] = (sum[node] + k * len) % MOD;
        lazy[node] += k;
    }

    void push(int node, int l, int r) {
        if (lazy[node] == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;
        ll k = lazy[node];

        apply(node * 2, l, mid, k);
        apply(node * 2 + 1, mid + 1, r, k);

        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            apply(node, l, r);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        if (ql <= mid)
            update(node * 2, l, mid, ql, qr);

        if (qr > mid)
            update(node * 2 + 1, mid + 1, r, ql, qr);

        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
        sumSq[node] = (sumSq[node * 2] + sumSq[node * 2 + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        sum.assign(4 * n, 0);
        sumSq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> lastSeen;
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            int l = lastSeen.count(nums[i]) ? lastSeen[nums[i]] + 1 : 0;
            update(1, 0, n - 1, l, i);
            ans = (ans + sumSq[1]) % MOD;
            lastSeen[nums[i]] = i;
        }

        return (int)ans;
    }
};