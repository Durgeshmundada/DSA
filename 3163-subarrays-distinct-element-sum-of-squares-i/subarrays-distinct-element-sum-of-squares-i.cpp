class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            set<int> x;
            for(int j=i;j<nums.size();j++){
                x.insert(nums[j]);
                res+=pow(x.size(),2);
            }
        }
        return res;
    }
};