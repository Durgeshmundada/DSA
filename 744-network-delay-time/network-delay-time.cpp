
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> res(n+1);

        for(int i=0;i<times.size();i++){
            res[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        vector<int> vis(n+1,INT_MAX);
        vis[k]=0;

        check(res,vis,k);

        int ans=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==INT_MAX) return -1;
            ans=max(ans,vis[i]);
        }

        return ans;
    }

    void check(vector<vector<pair<int,int>>>& res, vector<int>& vis, int k){
        for(int i=0;i<res[k].size();i++){
            int node=res[k][i].first;
            int wt=res[k][i].second;

            if(vis[k]+wt<vis[node]){
                vis[node]=vis[k]+wt;
                check(res,vis,node);
            }
        }
    }
};
