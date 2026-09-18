class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        vector<int> best(n, INT_MAX);

        unordered_map<int, int> mp;
        mp[0] = -1;

        int sum = 0;
        int ans = INT_MAX;

        for(int i = 0; i < n; i++){

            sum += arr[i];

            // previous best
            if(i > 0)
                best[i] = best[i-1];

            if(mp.count(sum - target)){

                int start = mp[sum - target] + 1;

                int len = i - start + 1;

                // previous subarray must end before start
                if(start > 0 && best[start - 1] != INT_MAX){

                    ans = min(ans, len + best[start - 1]);
                }

                // current subarray
                best[i] = min(best[i], len);
            }

            // earliest prefix position
            if(!mp.count(sum))
                mp[sum] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};