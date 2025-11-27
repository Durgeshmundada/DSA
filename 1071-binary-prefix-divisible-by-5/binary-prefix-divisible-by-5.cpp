class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int x=0;
        for(int i=0;i<nums.size();i++){
           x = (x * 2 + nums[i]) % 5;

            if(x%5==0){
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        }
        return result;
    }
};