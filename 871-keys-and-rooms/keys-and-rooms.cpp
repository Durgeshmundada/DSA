
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),0);
        unordered_map<int,int> um;

        um[0]=1;
        check(rooms,vis,um,0);

        for(int i=0;i<rooms.size();i++){
            if(um.find(i)==um.end()) return false;
        }

        return true;
    }

    void check(vector<vector<int>>& rooms, vector<int>& vis,unordered_map<int,int>& um, int k) {
        if(vis[k]==1) return;

        vis[k]=1;
        um[k]=1;

        for(int i=0;i<rooms[k].size();i++){
            int node=rooms[k][i];

            if(vis[node]==0){
                um[node]=1;
                check(rooms,vis,um,node);
            }
        }
    }
};
