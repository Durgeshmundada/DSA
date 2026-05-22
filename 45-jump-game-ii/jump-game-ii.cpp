class Solution {
public:

    int jump(vector<int>& nums) {

        vector<int> dp(nums.size(), -1);

        return canj(nums, dp, 0);
    }

    int canj(vector<int>& nums, vector<int>& dp, int idx) {

        if(idx >= nums.size()-1)
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int ans = INT_MAX;

        int farthest = min((int)nums.size()-1, idx + nums[idx]);

        for(int i = idx + 1; i <= farthest; i++) {

            int jumps = canj(nums, dp, i);

            if(jumps != INT_MAX)
                ans = min(ans, 1 + jumps);
        }

        return dp[idx] = ans;
    }
};