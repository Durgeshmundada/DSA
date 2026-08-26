class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
       vector<string> res;
       int count=INT_MAX;
       int c=0;
       int left=0;
       for(int i=0;i<s.size();i++){
          while(i<s.size() && s[i]=='0' && c==0){
                        i++;
                        left=i;
            }
            if(i==s.size()){
                continue;
            }    
            if(s[i]=='1'){
                c++;
            }
            
                if(c==k){
                    while(left<=i && s[left]=='0'){
                        
                        left++;
                    }
                    res.push_back(s.substr(left, i - left + 1));
                    count=min(count,i-left+1);
               
                if (s[left] == '1') {
                    c--;
                }

                left++;
                }
                
       }
        for(int i=0;i<res.size();i++){
            if(res[i].size()>count){
                res.erase(res.begin() + i);
                i--;
            }
       }
        sort(res.begin(),res.end());
       if(res.size()==0) return {};
       return res[0];
    }
};