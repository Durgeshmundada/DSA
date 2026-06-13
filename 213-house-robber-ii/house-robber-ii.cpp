class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        auto first = sol(nums, 0, n - 2);
        auto second = sol(nums, 1, n - 1);

        return max(
            max(first.first, first.second),
            max(second.first, second.second)
        );
    }

    pair<int,int> sol(vector<int>& nums, int idx, int end) {
        if(idx > end) return {0,0};

        auto next = sol(nums, idx + 1, end);

        int with = nums[idx] + next.second;
        int without = max(next.first, next.second);

        return {with, without};
    }
};