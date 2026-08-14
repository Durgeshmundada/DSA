class Solution {
public:
    int maximumLengthSubstring(string s) {
        int count=0;
        int ans=0;
        int idx=0;
        unordered_map<int,int>um;
        for(int i=0;i<s.size();i++){
            if(um[s[i]]<2){
                um[s[i]]++;
                count++;
            }
            else{
                while(um[s[i]]>=2){
                    um[s[idx]]--;
                    count--;
                    idx++;
                }
                um[s[i]]++;
                count++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};