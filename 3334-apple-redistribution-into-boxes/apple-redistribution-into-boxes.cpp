class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int count=0;
        for(int i=0;i<apple.size();i++){
            count+=apple[i];
        }
        sort(capacity.begin(), capacity.end(), greater<int>());
        int cap=0;
        int result=0;
        for(int i=0;i<capacity.size();i++){
            cap+=capacity[i];
            result++;
            if(cap>=count){
                break;
            }
        }
        return result;
    }
};