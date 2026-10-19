class Solution {
public:
    int minSwaps(vector<int>& nums) {
       vector<pair<int,int>> res(nums.size());
       for(int i=0;i<nums.size();i++){
        int x=0;
        int y=nums[i];
        while(y){
            x+=y%10;
            y/=10;
        }
        res[i]={x,i};
       }
       sort(res.begin(),res.end(),[&](pair<int,int> a, pair<int,int> b){
            if(a.first==b.first){
                return nums[a.second]<nums[b.second];
            }
            return a.first<b.first;
       });
       vector<int>vis(nums.size(),0);
       int x=0;
       for(int i=0;i<nums.size();i++){
           if(vis[i]==1) continue;

            int count=0;
            int j=i;

            while(vis[j]!=1){
                vis[j]=1;
                j=res[j].second;
                count++;
            }

            if(count>1){
                x+=count-1;
            }
       }
       return x;
    }
};