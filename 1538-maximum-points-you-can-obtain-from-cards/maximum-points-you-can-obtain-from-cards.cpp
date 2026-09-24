class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i = n - k;
        int sum = 0;

        for(int j = i; j < n; j++) {
            sum += nums[j];
        }

        int res = sum;

        for(int j = 0; j < k; j++) {
            sum -= nums[n - k + j];
            sum += nums[j];
            res = max(sum, res);
        }

        return res;
    }
};