class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,long long>um;
        long long result=1;
        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            long long x=nums[i];
            long long count=0;
            if (nums[i] == 1) {
                  result = max(result, um[1] % 2 ? um[1] : um[1] - 1);
                  continue;
                }
            while(um[x] >= 2 && um.count(x * x)){
                count+=2;
                x=x*x;
            }
            if(um[x]>0)
             result=max(result,count+1);
            else 
             result=max(result,count);
        }
        return result;
    }
};