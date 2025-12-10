class Solution {
public:
static const int MOD = 1000000007;
    int countPermutations(vector<int>& complexity) {
        int c=complexity[0];
        sort(complexity.begin(),complexity.end());
        if(complexity[0]<c){
            return 0;
        }
        if(complexity[0]==c){
           if(complexity[1]<=c){
            return 0;
        } 
        }
         long long res = 1;
        for (int i = 1; i <=  complexity.size() - 1; i++) {
            res = (res * i) % MOD;
        }
        return (int)res;
    }
    
};