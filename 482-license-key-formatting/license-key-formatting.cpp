class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result="";
        string temp="";
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '-') continue;
           temp += toupper(s[i]);
        }
        int count=0;
        for(int i=0;i<temp.size();i++){
            if(count==k){
                result+="-";
                count=0;
            }
            result+=temp[i];
            count++;
        }
         reverse(result.begin(), result.end());
        return result;
     }
};