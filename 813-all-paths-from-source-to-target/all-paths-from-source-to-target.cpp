class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        vector<int>s;
        s.push_back(0);
        check(graph,res,s,0);
        return res;
    }
    void check(vector<vector<int>>& graph,vector<vector<int>>& res,vector<int>&s,int k){
        for(int i=0;i<graph[k].size();i++){
            s.push_back(graph[k][i]);
            check(graph,res,s,graph[k][i]);
            if(s[s.size()-1]==graph.size()-1){
            res.push_back(s);
            }
            s.pop_back();
        }
    }
};