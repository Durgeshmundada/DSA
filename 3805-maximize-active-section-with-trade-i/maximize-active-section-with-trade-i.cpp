class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> zero;
        int start=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                while(i<s.size() && s[i]=='0'){
                    start++;
                    i++;
                }
                zero.push_back(start); 
                start=0;
                i--;
            }
            else count++;
        }
        if(zero.size()==0) return s.size();
        if(zero.size()==1) {
            if(zero[0]==s.size()) return 0;
            else return s.size()-zero[0];
        }
        int p=INT_MIN;
        for(int i=0;i<zero.size()-1;i++){
            if(zero[i]+zero[i+1]>p){
                p=zero[i]+zero[i+1];

            }
        }
        return count+p;

    }
};