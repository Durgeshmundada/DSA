class Solution {
public:
    vector<int> result;
   int find(int x){
        if(result[x]!=x){
            result[x]=find(result[x]);
        }
        return result[x];
    }
    bool check(int a, int b){
       int r1=find(a);
       int r2= find(b);
       if(r1==r2) return false;
       result[r2]=r1;
       return true;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        result.resize(n);
        for(int i=0;i<n;i++){
         result[i] = i;
        }
        int extra=0;
        for(int i=0;i<connections.size();i++){
           if(!check(connections[i][0],connections[i][1])){
            extra++;
           }
        }
        int result=extra;
        int m=find(0);
        for(int i=0;i<n;i++){

           if(check(m,i)){
            if(extra==0) return -1;
            extra--;
            
           }
        }
        return result-extra;
    }
};