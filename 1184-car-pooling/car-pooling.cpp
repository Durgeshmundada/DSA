class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> dp(1002, 0);

        for(int i=0; i<trips.size(); i++){
            dp[trips[i][1]] += trips[i][0];
            dp[trips[i][2]] -= trips[i][0];
        }

        for(int i=0; i<dp.size(); i++){
            if(i > 0)
                dp[i] += dp[i-1];

            if(dp[i] > capacity)
                return false;
        }

        return true;
    }
};