/**
 * TOPIC: FENWICK TREE
 * Prefix Sum + Point Update in O(log n)
 */

 
class NumArray {
    vector<int> BIT;
    vector<int> arr;
    int n;
    int prefixSum(int index) {
        index++;

        int ans = 0;

        while (index > 0) {
            ans += BIT[index];
            index -= index & (-index);
        }

        return ans;
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        BIT.resize(n + 1, 0);
        arr = nums;
        for (int i = 0; i < n; i++) {
            int index = i + 1;

            while (index <= n) {
                BIT[index] += nums[i];
                index += index & (-index);
            }
        }
    }

    void update(int index, int val) {
        int delta = val - arr[index];
        arr[index] = val;

        index++;

        while (index <= n) {
            BIT[index] += delta;
            index += index & (-index);
        }
    }

    int sumRange(int left, int right) {
        return prefixSum(right) - prefixSum(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */