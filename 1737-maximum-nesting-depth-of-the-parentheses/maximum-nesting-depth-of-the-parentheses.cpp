class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int res=0;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                res++;
            }
            else if(s[i]==')'){
                res--;
            }
            ans=max(res,ans);
        }
        return ans;
    }
};