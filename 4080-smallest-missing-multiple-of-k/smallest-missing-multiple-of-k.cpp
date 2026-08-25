class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>um;
        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
        }
        int i=1;
        while(true){
            if(um.find(k*i)==um.end()){
                return k*i;
            }
            i++;
        }
        return -1;
    }
};