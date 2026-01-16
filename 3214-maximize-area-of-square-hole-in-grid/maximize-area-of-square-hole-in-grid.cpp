class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int h=1;
        int h1=1;
        int v=1;
        int v1=1;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        for(int i=1;i<hBars.size();i++){
            h=max(h,h1-h);
            if(hBars[i-1]+1==hBars[i]){
                h1++;
            }
            else{
                h1=1;
            }
            h=max(h,h1);
        }
        for(int i=1;i<vBars.size();i++){
            
            if(vBars[i-1]+1==vBars[i]){
                v1++;
            }
            else{
                v1=1;
               
            }
            v=max(v,v1);
        }
        v=min(v+1,h+1);
        return v*v;
    }
};