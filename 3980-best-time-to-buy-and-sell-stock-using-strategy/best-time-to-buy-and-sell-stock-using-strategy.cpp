class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
       int n = prices.size();

        long long result = LLONG_MIN;
        long long check = 0;
        for (int i = 0; i < n; i++) {
            check += 1LL * prices[i] * strategy[i];
        }

        result = check;
        for (int i = 0; i < k; i++) {
            if (i < k / 2) {
                check -= 1LL * prices[i] * strategy[i];
            } else {
                check += 1LL * prices[i] - 1LL * prices[i] * strategy[i];
            }
        }

        result = max(result, check);

        for(int i=1;i+k<=n;i++){
            int out = i - 1;
            int in  = i + k - 1;
            int mid= i+k/2-1;
            if (out < i - 1 + k / 2) {
                check += 1LL * prices[out] * strategy[out];
            } else {
                check -= 1LL * prices[out] - 1LL * prices[out] * strategy[out];
            }
            check-=1LL * prices[mid];
            if (in < i + k / 2) {
                check -= 1LL * prices[in] * strategy[in];
            } else {
                check += 1LL * prices[in] - 1LL * prices[in] * strategy[in];
            }

            result = max(result, check);
        }
        return result;
    }
};