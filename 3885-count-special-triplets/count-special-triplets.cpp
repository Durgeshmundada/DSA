class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,long long> um,um1;
        const int mod = 1000000007;
        int count=0;
        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
        }
        for(auto x:nums){
            um[x]--;
            
            long long target = 2LL * x;
            long long leftCount = um1[target];
            long long rightCount = um[target];
            
            count = (count + (leftCount * rightCount) % mod) % mod;
            um1[x]++;
        }
        return count;
    }
};