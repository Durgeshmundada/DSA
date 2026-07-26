class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        vector<long long> pre(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {

            int low = i + 1;
            int high = n;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (pre[mid] - pre[i] >= target) {
                    ans = min(ans, mid - i);
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
