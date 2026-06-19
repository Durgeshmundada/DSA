class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        vector<vector<long long>> memo(n, vector<long long>(2, -1));
        return maxt(nums, s, 0, 1, memo);
    }
    
    long long maxt(vector<int>& nums, string &s, int idx, int left_covered, vector<vector<long long>>& memo) {
        if (idx >= nums.size()) {
            return 0;
        }
        
        if (memo[idx][left_covered] != -1) {
            return memo[idx][left_covered];
        }
        
        long long with = 0;
        long long without = 0;
        
        if (s[idx] == '1') {
            long long gain_left = (!left_covered && idx > 0) ? nums[idx - 1] : 0;
            with = gain_left + maxt(nums, s, idx + 1, 0, memo);
            without = nums[idx] + maxt(nums, s, idx + 1, 1, memo);
        } else {
            without = maxt(nums, s, idx + 1, 0, memo);
        }
        
        return memo[idx][left_covered] = max(with, without);
    }
};