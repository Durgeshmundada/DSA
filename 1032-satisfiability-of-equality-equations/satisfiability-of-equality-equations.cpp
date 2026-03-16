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
       return true;
    }
    void unio(int a, int b){
        int r1=find(a);
       int r2= find(b);
       if(r1==r2) return;
       result[r2]=r1;
       return; 
    }
    bool equationsPossible(vector<string>& equations) {
        result.resize(26);
        for(int i=0;i<26;i++){
            result[i]=i;
        }
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='='){
                unio(equations[i][0]-'a',equations[i][3]-'a');
            }
        }
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='!'){
               if(!check(equations[i][0]-'a',equations[i][3]-'a')){
                return false;
               }
            }
        }
        return true;
    }
};