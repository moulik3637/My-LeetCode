class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();
        
        int bothLeft  = max(minIdx, maxIdx) + 1;
        int bothRight = n - min(minIdx, maxIdx);
        int split     = min(minIdx, maxIdx) + 1 + n - max(minIdx, maxIdx);
        
        return min({bothLeft, bothRight, split});
    }
};