/**
* Brute Force Approach
* Time complexity : O(n^2)
* Space Complexity : O(n)
int n = nums.size();
        vector<int> ans(n,0);
        for(int i = 0 ; i < n - 1;i++){
            int count= 0;
            for(int j = i + 1; j < n ;j++){
                if(nums[j] < nums[i]){
                    count++;
                }
            }
            ans[i] = count;
        }
        return ans;

*/
class Solution {

    void merge(vector<pair<int, int>>& arr, int low, int mid, int high,
               vector<int>& ans) {

        int i = low;
        int j = mid + 1;
        int rightSmaller = 0;

        vector<pair<int, int>> temp;

        while (i <= mid && j <= high) {

            if (arr[j].first < arr[i].first) {

                rightSmaller++;

                temp.push_back(arr[j]);
                j++;
            } else {

                ans[arr[i].second] += rightSmaller;

                temp.push_back(arr[i]);
                i++;
            }
        }

        while (i <= mid) {

            ans[arr[i].second] += rightSmaller;

            temp.push_back(arr[i]);
            i++;
        }

        while (j <= high) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = low; k <= high; k++) {
            arr[k] = temp[k - low];
        }
    }

    void mergeSort(vector<pair<int, int>>& arr, int low, int high,
                   vector<int>& ans) {

        if (low < high) {

            int mid = low + (high - low) / 2;

            mergeSort(arr, low, mid, ans);
            mergeSort(arr, mid + 1, high, ans);

            merge(arr, low, mid, high, ans);
        }
    }

public:
    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        vector<int> ans(n, 0);

        mergeSort(arr, 0, n - 1, ans);

        return ans;
    }
};