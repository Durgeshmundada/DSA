class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int count=numBottles;
       
        while(numBottles>=numExchange){
            if(numBottles>=numExchange){
                count++;

            }
            numBottles=numBottles-numExchange+1;
            numExchange++;
        }
        return count;
    }
};