
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            if(graph[i].size()==0){
                mp[i]=1;
            }
        }

        bool flag = true;

        while(flag){
            flag = false;

            for(int i=0;i<n;i++){
                if(mp.find(i)!=mp.end()) continue;

                bool check = true;

                for(int j=0;j<graph[i].size();j++){
                    if(mp.find(graph[i][j])==mp.end()){
                        check = false;
                        break;
                    }
                }

                if(check){
                    mp[i]=1;
                    flag = true;
                }
            }
        }

        vector<int> ans;

        for(auto it:mp){
            ans.push_back(it.first);
        }

        return ans;
    }
};
