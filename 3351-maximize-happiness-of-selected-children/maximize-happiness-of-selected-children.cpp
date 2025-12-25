class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long dek=0;
        long long result=0;
        sort(happiness.begin(),happiness.end(),greater<int>());
        for(int i=0;i<k;i++){
            if(happiness[i]-dek>0){
                result+=happiness[i]-dek;
                
            }
            dek++;
        }
        return result;
    }
};