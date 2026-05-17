class Solution {
public:

    bool canReach(string s, int minJump, int maxJump) {

        vector<int> dp(s.size(), 0);
        dp[0]=1;
        int r=0;
        for(int i=0;i<s.size();i++){
            if(i-minJump>=0&&dp[i-minJump]) r++;
            if(i-maxJump-1>=0&&dp[i-maxJump-1]) r--;
            if(s[i]=='0' && r) dp[i]=true;
        }
        return dp[s.size()-1];
    }

    
};