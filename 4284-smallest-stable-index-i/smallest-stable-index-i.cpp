class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> minFromIndex(n);
        int minnum = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {
            minnum = min(minnum, nums[i]);
            minFromIndex[i] = minnum;
        }

        int maxnum = INT_MIN;

        for (int i = 0; i < n; i++) {
            maxnum = max(maxnum, nums[i]);

            if (maxnum - minFromIndex[i] <= k)
                return i;
        }

        return -1;
    }
};