class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx=INT_MIN;
        vector<int>pg(nums.size());
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
            pg[i]=__gcd(mx,nums[i]);
        }
        long long res=0;
        sort(pg.begin(),pg.end());
        for(int i=0;i<pg.size()/2;i++){
            res+=__gcd(pg[i],pg[pg.size()-i-1]);
        }
        return res;
    }
};