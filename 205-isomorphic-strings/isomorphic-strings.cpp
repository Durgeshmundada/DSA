class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> um;
        unordered_map<char,char> um1;
        for(int i=0;i<s.size();i++){
           if(um.count(s[i]) && um[s[i]]!=t[i] ){
            return false;
           }
           if(um1.count(t[i]) && um1[t[i]]!=s[i] ){
            return false;
           }
            um[s[i]]=t[i];
            um1[t[i]]=s[i];
        }
        return true;
    }
};