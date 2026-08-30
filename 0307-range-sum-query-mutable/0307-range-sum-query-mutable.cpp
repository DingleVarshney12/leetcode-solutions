class NumArray {

    vector<int> tree;
    int n;

    void updateHelper(int node, int l, int r, int index, int value) {
        if (l == r) {
            tree[node] = value;
            return;
        }

        int mid = l + (r - l) / 2;

        if (index <= mid) {
            updateHelper(2 * node, l, mid, index, value);
        } else {
            updateHelper(2 * node + 1, mid + 1, r, index, value);
        }

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    int queryHelper(int node, int l, int r, int ql, int qr) {
        // No overlap
        if (qr < l || ql > r)
            return 0;

        // Complete overlap
        if (ql <= l && r <= qr)
            return tree[node];

        // Partial overlap
        int mid = l + (r - l) / 2;

        int leftAns = queryHelper(2 * node, l, mid, ql, qr);

        int rightAns = queryHelper(2 * node + 1, mid + 1, r, ql, qr);

        return leftAns + rightAns;
    }
    void build(int node, int l, int r, vector<int>& arr) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * node, l, mid, arr);
        build(2 * node + 1, mid + 1, r, arr);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, nums);
    }

    void update(int index, int val) { updateHelper(1, 0, n - 1, index, val); }

    int sumRange(int left, int right) {
        return queryHelper(1, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */