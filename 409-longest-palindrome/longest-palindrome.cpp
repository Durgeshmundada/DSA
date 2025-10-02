class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> um;
        for(int i=0;i<s.size();i++){
            um[s[i]]++;
        }
        int count=0;
        bool flag=false;
        for(auto i:um){
            if(i.second%2==0){
                count=count+i.second;
               
            }
            else{
                if(i.second>1){
                count=count+i.second -1;
                
                
                }
                flag=true;
            }

        }
        if(flag){
            count++;
        }
        return count;
    }
};