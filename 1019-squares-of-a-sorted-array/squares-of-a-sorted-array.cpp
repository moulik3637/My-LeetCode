class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();

        vector<int> positive;
        vector<int> negative;

        for (int i = 0; i < size; i++) {
            if (nums[i] < 0) {
                negative.push_back(nums[i]);
            } else {
                positive.push_back(nums[i]);
            }
        }

        for (int i = 0; i < positive.size(); i++) {
            positive[i] = positive[i] * positive[i];
        }

        for (int i = 0; i < negative.size(); i++) {
            negative[i] = negative[i] * negative[i];
        }
        reverse(negative.begin(), negative.end());
        int i = 0, j = 0;
        vector<int> res;

        while (i < negative.size() && j < positive.size()) {
            if (negative[i] <= positive[j]) {
                res.push_back(negative[i]);
                i++;
            } else {
                res.push_back(positive[j]);
                j++;
            }
        }
        while (i < negative.size()) {
            res.push_back(negative[i]);
            i++;
        }
        while (j < positive.size()) {
            res.push_back(positive[j]);
            j++;
        }

        return res;
    }
};