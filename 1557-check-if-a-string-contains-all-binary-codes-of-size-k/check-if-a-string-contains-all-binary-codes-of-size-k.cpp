class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k){
            return false;
        }
        unordered_map<int,int> um;
        for(int i=0;i<=s.size()-k;i++){
            string b=s.substr(i,k);
            um[stoi(b, nullptr, 2)]=1;
        }
        for(int i=0;i<=pow(2,k)-1;i++){
            if(um[i]!=1){
                return false;
            }
        }
        return true;
    }
};