class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(begin(arr2), end(arr2));
        int n = arr2.size();
        int disVal = 0;
        for (int x : arr1) {
            int j = lower_bound(begin(arr2), end(arr2), x) - begin(arr2);
            if ((j == n || arr2[j] - x > d) && (j == 0 || x - arr2[j - 1] > d))
                disVal++;
        }
        return disVal;
    }
};