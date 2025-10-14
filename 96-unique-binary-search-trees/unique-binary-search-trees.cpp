class Solution {
public:
    int numTrees(int n) {
       unordered_map<int,int> um;
       return non(n,um);
    }
    int non(int n,unordered_map<int,int>& um){
        if(n<=1){
        return 1;
       }
       if(um[n]!=0){
        return um[n];
       }
       int count=0;
       for(int i=0;i<n;i++){
        count+= non(i,um)*non(n-i-1,um);
       }
       um[n]=count;
       return count;
    }
};