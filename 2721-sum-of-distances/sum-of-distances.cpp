class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> result(n);

        unordered_map<int, long long> count, sum;

        // Left pass
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            result[i] += count[x] * i - sum[x];

            count[x]++;
            sum[x] += i;
        }

       
        count.clear();
        sum.clear();

        for (int i = n - 1; i >= 0; i--) {
            int x = nums[i];
            result[i] += sum[x] - count[x] * i;

            count[x]++;
            sum[x] += i;
        }

        return result;
    }
};