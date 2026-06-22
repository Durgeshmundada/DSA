class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int result=0;
        unordered_map<char,int> um;

        for(int i=0;i<text.size();i++){
            um[text[i]]++;
        }
        string check="balloon";
        while(true){
        for(int i=0;i<check.size();i++){
            if(um[check[i]]==0) return result;
            um[check[i]]--;
        }
        result++;
        }
        return result;
    }
};