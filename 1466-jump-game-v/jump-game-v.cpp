class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {

        vector<int> idx(arr.size());

        for(int i = 0; i < arr.size(); i++) {
            idx[i] = i;
        }

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return arr[a] < arr[b];
        });

        vector<int> dp(arr.size(), 1);

        int result = 1;

        for(int i = 0; i < idx.size(); i++) {

            for(int j = 0; j < i; j++) {

                int x = idx[i];
                int y = idx[j];

                if(abs(x - y) <= d && arr[x] > arr[y]) {

                    bool blocked = false;

                    for(int k = min(x, y) + 1; k < max(x, y); k++) {

                        if(arr[k] >= arr[x]) {
                            blocked = true;
                            break;
                        }
                    }

                    if(!blocked) {
                        dp[x] = max(dp[x], dp[y] + 1);
                    }
                }
            }

            result = max(result, dp[idx[i]]);
        }

        return result;
    }
};