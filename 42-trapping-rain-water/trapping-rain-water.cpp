class Solution {
public:
    int trap(vector<int>& height) {
        int x=0;
        int h=height[0];
        int count=0;
        int check=0;
        for(int i=1;i<height.size();i++){
            if(h>height[i]){
                check=check+(h-height[i]);
            }
            else{
                h=height[i];
                x=i;
                count=check+count;
                check=0;
            }
            if(i==height.size()-1 && check!=0){
                int maxIdx = x+1;
                for(int j=x+1; j<height.size(); j++){
                    if(height[j] > height[maxIdx]) maxIdx = j;
                }
                int boundary = height[maxIdx];
                for(int j=x+1; j<maxIdx; j++){
                count += max(0, boundary - height[j]);
                }
                h=height[maxIdx];
                x=maxIdx;
                i=x;
                check=0;
            }
        }
        return count;
    }
};