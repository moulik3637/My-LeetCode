class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete = arr[0];
        int ans = arr[0];
        int onedelete = INT_MIN;
        int v2 = 0;

        for (int i = 1; i < arr.size(); i++) {
            int preonedelete = onedelete;
            int prenodelete = nodelete;

            nodelete = max(nodelete + arr[i], arr[i]);

            if (preonedelete == INT_MIN) {
                v2 = arr[i];
            } else {
                v2 = preonedelete + arr[i];
            }

            onedelete = max(v2, prenodelete);
            ans = max(ans, max(onedelete, nodelete));
        }

        return ans;
    }
};