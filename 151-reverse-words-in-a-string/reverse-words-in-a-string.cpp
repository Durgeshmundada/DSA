class Solution {
public:
    string reverseWords(string s) {
        int r=s.size()-1;
        while(r >= 0 && s[r]==' '){
            r--;
        }
        string result="";
        while(r>=0){
            
               while(r>=0 && s[r]==' '){
                r--;
               }
    
            if (r < 0) break;
            int right=r;
            while(r>=0 && s[r]!=' '){
                r--;
            }
            int start = r + 1;
            int len = right-start + 1;

            if (!result.empty()) result += " ";
            result += s.substr(start, len);
        }
        return result;
    }
};