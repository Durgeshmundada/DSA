class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int result=0;
        int flag=0;
        sort(cost.begin(),cost.end());
        for(int i=cost.size()-1;i>=0;i--){
            if(flag==2){
                flag=0;
            }
            else{
                result+=cost[i];
                flag++;
            }
        }
        return result;
    }
};