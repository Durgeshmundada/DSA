class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        int profit=0;
      
        
        
        int max1 = *max_element(prices.begin(), prices.end());
        for(int i=0;i<size;i++){
            if(max1<prices[i]){
               int profit1 =prices[i]-max1;
                profit=max(profit,profit1);
            }
            else{
                max1=prices[i];
            }
        }
        
       
        return profit;
    }
};