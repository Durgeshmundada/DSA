class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int first=0;
        int second=-1;
        for(int i=0;i<colors.size();i++){
            if(colors[i]!=colors[0]){
                second=i;
                break;
            }
        }int result=0;
        for(int i=colors.size()-1;i>=0;i--){
            if(colors[i]==colors[first]){
                result=max(result,abs(i-second));
            }
            else if(colors[i]==colors[second]){
                result=max(result,abs(i-first));
            }
            else{
                result=max(result,abs(i-second));
                result=max(result,abs(i-first));
            }
        }
        return result;
    }
};