class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int left=1;
       int right= *max_element(piles.begin(), piles.end());
       int ans=INT_MAX;
       while(left<right){
        int mid=left+(right-left)/2;
        int n=0;
        for(int i=0;i<piles.size();i++){
            n+=(piles[i] + mid - 1) / mid;
        }
        if(n<=h){
            right=mid;
        }
        else{
            left=mid+1;
        }
        
       } 
       return left;
    }
};