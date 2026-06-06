class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int result=INT_MAX; 
        for(int i=0;i<landStartTime.size();i++){
            int time=landStartTime[i]+landDuration[i];
            for(int j=0;j<waterStartTime.size();j++){
                result=min(result,max(time,waterStartTime[j])+waterDuration[j]);
            }
        }
        for(int i=0;i<waterStartTime.size();i++){
            int time=waterStartTime[i]+waterDuration[i];
            for(int j=0;j<landStartTime.size();j++){
                result=min(result,max(time,landStartTime[j])+landDuration[j]);
            }
        }

        return result;
    }
};