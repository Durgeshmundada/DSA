class Solution {
public:
    int minOperations(vector<int>& nums, int z) {
        unordered_map<int,int>um1;
        unordered_map<int,int>um2;
        int x=0;
        int y=0;
        for(int i=0;i<nums.size();i++){
            x+=nums[i];
            y+=nums[nums.size()-1-i];
            um1[x]=i+1;
            um2[y]=i+1;
        }
        um1[0] = 0;
        um2[0] = 0;
        int ans=INT_MAX;
        for(auto a : um1) {
            if(um2.find(z - a.first) != um2.end()) {

                int left = a.second;
                int right = um2[z - a.first];

                if(left + right <= nums.size()) {
                    ans = min(ans, left + right);
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};