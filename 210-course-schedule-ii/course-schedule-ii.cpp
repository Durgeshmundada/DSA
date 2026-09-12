class Solution {
public:
bool dfs(int i, vector<int>& vis, stack<int>& st,
             vector<vector<int>>& adj) {

        vis[i] = 1;

        for (auto it : adj[i]) {

            if (vis[it] == 1) {
                return false;
            }

            if (vis[it] == 0) {
                if (!dfs(it, vis, st, adj))
                    return false;
            }
        }

        vis[i] = 2;
        st.push(i);

        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> vis(numCourses, 0);

        stack<int> st;

        for (int i = 0; i < numCourses; i++) {

            if (vis[i] == 0) {

                if (!dfs(i, vis, st, adj))
                    return {};
            }
        }
        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};