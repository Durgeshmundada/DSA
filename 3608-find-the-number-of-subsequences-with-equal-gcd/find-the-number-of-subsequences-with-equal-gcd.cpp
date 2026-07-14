class Solution {
public:
vector<vector<vector<int>>>dp;
int mod=1000000007;
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
         dp.resize(n + 1,vector<vector<int>>(201,vector<int>(201, -1)));
        return subp(nums, 0, 0, 0);
    }
    int subp(vector<int>& nums,int s1,int s2,int idx){
        if (idx == nums.size()) {
            return (s1!=0 && s2!=0 && s1==s2);
        }
        if(dp[idx][s1][s2]!=-1)
            return dp[idx][s1][s2];
      long long ans = 0;
        
        ans += subp(nums, gcd(s1,nums[idx])%mod, s2, idx + 1);
    
        ans=ans%mod;
        ans += subp(nums, s1, gcd(s2,nums[idx])%mod, idx + 1);
       ans=ans%mod;
        ans += subp(nums, s1, s2, idx + 1);
        return dp[idx][s1][s2]=ans%mod;
    }
    int gcd(int x,int y) {
        int g;
        g = __gcd(x, y);
    return g%mod;
}
};