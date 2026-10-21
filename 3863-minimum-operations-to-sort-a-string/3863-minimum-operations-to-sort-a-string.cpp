class Solution {
#define beg_end(s) begin(s), end(s)
public:
    int minOperations(string s) {
        int n = s.size();
        if (is_sorted(beg_end(s))) return 0;
        if (n == 2) return -1;
        int mn = *min_element(beg_end(s));
        int mx = *max_element(beg_end(s));
        if (s[0] == mn || s[n - 1] == mx) return 1;
        for (int i = 1; i < n - 1; i++) if (s[i] == mn || s[i] == mx) return 2;
        return 3;
    }
};