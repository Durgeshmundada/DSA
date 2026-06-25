class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int prefix=0;
        int result=0;
        for(int i=0;i<nums.size();i++){
            if (nums[i] == target)
                prefix++;

            int check = prefix;
        for (int j = i; j >= 0; j--) {
           if (nums[j] == target)
            check--;

            int len = i - j + 1;
            int cnt = prefix - check;

            if (2 * cnt > len)
            result++;
        }
    }
        return result;
    }
};