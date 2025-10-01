class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if (numBottles < numExchange) {
            return numBottles; 
        }
        int newBottles = numBottles / numExchange;       
        int remainder = numBottles % numExchange; 
        return (numBottles - remainder) + numWaterBottles(newBottles + remainder, numExchange);
    }
};