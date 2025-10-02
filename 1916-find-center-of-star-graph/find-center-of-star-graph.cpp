class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> um;
        for(int i=0;i<edges.size();i++){
            um[edges[i][0]]++;
            um[edges[i][1]]++;
        }
        int result=INT_MIN;
        int key;
        for(int i=0;i<edges.size();i++){
            if(um[edges[i][0]]>result){
                result=um[edges[i][0]];
                key=edges[i][0];
            }
           if( um[edges[i][1]]>result){
            result=um[edges[i][1]];
            key=edges[i][1];
           };
        }
    return key;
    }
};