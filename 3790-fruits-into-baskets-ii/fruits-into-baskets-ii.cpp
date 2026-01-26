class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        for(int i=0;i<fruits.size();i++){
            for(int j=0;j<baskets.size();j++){
                if(baskets[j]>=fruits[i] ){
                    fruits[i]=0;
                    baskets[j]=0;
                    break;
                }
            }
        }
        int result=0;
        for(int i=0;i<fruits.size();i++){
            if(fruits[i]!=0){
                result++;
            }
        }
        return result;
    }
};