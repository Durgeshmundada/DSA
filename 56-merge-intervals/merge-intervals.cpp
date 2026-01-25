class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            int x=intervals[i][0];
            int y=intervals[i][1];
            while(i<intervals.size()-1 && (y>=intervals[i+1][0])){
                i++;
                y=max(y,intervals[i][1]);
            }
            result.push_back({x,y});
        }
        return result;
    }
};