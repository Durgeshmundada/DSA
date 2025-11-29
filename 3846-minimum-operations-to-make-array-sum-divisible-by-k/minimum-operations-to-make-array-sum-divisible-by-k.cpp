class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int result=0;
        while(sum%k!=0){
            result++;
            sum--;
        }
        return result;
    }
};