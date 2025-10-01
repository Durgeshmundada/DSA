class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
       int count=numBottles;
        while(numBottles >=numExchange) {
         int total=(numBottles)/numExchange;
         int r=(numBottles)%numExchange;
         count=count+total;
         numBottles=total+r;
        }
        
        return count;
    }
};
 