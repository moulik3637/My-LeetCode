class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minodd = INT_MAX;
        int odd = 0;

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % 2 != 0) {
                odd++;
                minodd = min(minodd, nums1[i]);
            }
        }

        if (odd == 0) {
            return true;
        }

        for (int x : nums1) {
            if (x % 2 == 0 && x < minodd) {
                return false;
            }
        }

        return true;
    }
};
