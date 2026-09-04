class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxnum = INT_MIN;
        int minnum = INT_MAX;
        int n = nums.size();
        int stable = 0;

        for(int i = 0 ; i < n ; i++){
            maxnum = *max_element(nums.begin(), nums.begin() + i + 1);
            minnum = *min_element(nums.begin() + i, nums.end());

            stable = maxnum - minnum ;
            if (maxnum - minnum <= k)
                return i;

        }
        return -1;
    }
};