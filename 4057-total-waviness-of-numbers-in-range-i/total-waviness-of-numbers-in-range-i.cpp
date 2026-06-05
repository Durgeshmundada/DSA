class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int result=0;
        for(int i=max(100,num1);i<=max(100,num2);i++){
            string s=to_string(i);
            int j=1;
            while(j+1<s.size()){
                if((s[j]>s[j-1] && s[j]>s[j+1])||(s[j]<s[j-1] && s[j]<s[j+1])) result++;
                j++;
            }
        }
        return result;
    }
};