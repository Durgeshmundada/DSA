class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<vector<int>> vis;

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        dp.assign(n, vector<vector<int>>(n));
        vis.assign(n, vector<int>(n, 0));

        vector<int> ans;

        for(int i = n - 1; i >= 0; i--) {
            vector<int> zs = check(nums, i - 1, i);
            zs.push_back(nums[i]);      
            if(zs.size() > ans.size())
                ans = zs;
        }

        return ans;
    }

    vector<int> check(vector<int>& nums, int idx, int first) {
        if(idx == -1) return {};

        if(vis[first][idx])
            return dp[first][idx];

        vis[first][idx] = 1;

        vector<int> best = check(nums, idx - 1, first);

       
        if(nums[first] % nums[idx] == 0) {
            vector<int> temp = check(nums, idx - 1, idx);
            temp.push_back(nums[idx]);      

            if(temp.size() > best.size())
                best = temp;
        }

        return dp[first][idx] = best;
    }
};