class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> on(n+1);
        unordered_map<int,int>um;
        for(int i=0;i<trust.size();i++){
            on[trust[i][1]].push_back(trust[i][0]);
            um[trust[i][0]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(n-1==on[i].size()){
               if(um.find(i)==um.end()) return i; 
            } 
        }
        
    return -1;
    }
};