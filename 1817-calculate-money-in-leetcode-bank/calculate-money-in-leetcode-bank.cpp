class Solution {
public:
    int totalMoney(int n) {
      int result=0;
      int day=0;
      int week=0;
      for(int i=1;i<=n;i++){
        result=result+week+day+1;
        day++;
        if(day==7){
            day=0;
            week++;
        }
      }
      return result;  
    }
};