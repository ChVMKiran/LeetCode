class SegmentTree {
public:
    vector<int> nums, tree;
    int n;
    SegmentTree(vector<int>& arr) {
        nums = arr;
        n = arr.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }
    void build(int node, int start, int end) {
        if(start == end) {
            tree[node] = nums[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(node * 2 + 1, start, mid);
        build(node * 2 + 2, mid + 1, end);
        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }
    int query(int node, int start, int end, int l, int r) {
        if(r < start || l > end) return 0;
        if(l <= start && end <= r) return tree[node];
        int mid = start + (end - start) / 2;
        int leftSum = query(node * 2 + 1, start, mid, l, r);
        int rightSum = query(node * 2 + 2, mid + 1, end, l, r);
        return leftSum + rightSum;
    }
    void update(int node, int start, int end, int ind, int val) {
        if(start == end) {
            nums[ind] = val;
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if(ind <= mid) update(node * 2 + 1, start, mid, ind, val);
        else update(node * 2 + 2, mid + 1, end, ind, val);
        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }
};
class NumArray {
public:
    SegmentTree st;
    int n;
    NumArray(vector<int>& nums) : st(nums) {
        st = SegmentTree(nums);
        n = nums.size();
    }
    
    void update(int index, int val) {
        st.update(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return st.query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */