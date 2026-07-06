class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });

        int right = intervals[0][1];
        int result = 0;

        for(int i=1;i<intervals.size();i++){

            if(intervals[i][0] <= right){

                if(intervals[i][1] <= right){
                    result++;
                }
                else{
                    right = intervals[i][1];
                }

            }
            else{
                right = intervals[i][1];
            }
        }

        return intervals.size()-result;
    }
};