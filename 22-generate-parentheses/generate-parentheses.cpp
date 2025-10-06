class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        vector<char> s;
        back(0,0,n,s,res);
        return res;
    }
    void back(int open,int close,int n,vector<char>& s,vector<string>& res ){
        if(open==n && close==n){
            res.push_back(string(s.begin(), s.end()));
            return;
        }
        if(open<n){
            s.push_back('(');
             back(open+1,close,n,s,res);
            s.pop_back();
        }
        if(close<open){
            s.push_back(')');
             back(open,close+1,n,s,res);
            s.pop_back();
        }
    }
};