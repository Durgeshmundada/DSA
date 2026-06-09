class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        if(nums.size()==1) return 0;
        long long result=0;
        sort(nums.begin(),nums.end());
        result=(long long)(nums[nums.size()-1]-nums[0])*(long long)k;
        return result;
    }
};