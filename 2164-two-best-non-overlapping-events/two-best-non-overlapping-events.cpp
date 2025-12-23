class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        int result=0;
        vector<int> suf(n);
        suf[n-1] = events[n-1][2];
        for(int i = n-2; i >= 0; i--) {
            suf[i] = max(suf[i+1], events[i][2]);
        }
        for(int i=0;i<events.size();i++){
            int val=events[i][2];
            int start=i+1;
            int last=events.size()-1;
           
             int idx = -1;
            while(start<=last){
               int mid=(start+last)/2;
                if(events[mid][0]>events[i][1]){
                    idx=mid;
                    last=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            if(idx!=-1){
                val+=suf[idx];
            }
            
           result=max(result,val);
        }
        return result;
    }
};