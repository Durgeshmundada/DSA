class Solution {
public: vector<int> result;
    vector<int> lexicalOrder(int n) {
        int x=1;
        while(n/10>=x){
            x*=10;
        }
        for(int i=1;i<=9;i++){
            dfs(n,i);
        }
        return result;
    }
    void dfs(int n,int i){
        if(i>n){
            return;
        }
        result.push_back(i);
        int base=i*10;
        if(base<=n){
            dfs(n,base);
        }
        for(int j=1;j<10;j++){
            if((base+j)>n){
                return;
            }
            dfs(n,base+j);
        }
    }
};