class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        return solv(nums, nums.size() - 2, 0);
    }

    int spf(int x) {
        for(int i = 2; i * i <= x; i++) {
            if(x % i == 0) return i;
        }
        return x;
    }

    int solv(vector<int>& nums, int idx, int sum) {
        if(idx == -1) return sum;

        if(nums[idx] <= nums[idx + 1]) {
            return solv(nums, idx - 1, sum);
        }

        nums[idx] = spf(nums[idx]);
        
        if(nums[idx] > nums[idx + 1]) {
            return -1;
        }

        return solv(nums, idx - 1, sum + 1);
    }
};