class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res = "";

        if( sum > 9*num) return "";

        check(num, sum, res, 0);

        return res;
    }

    void check(int num, int sum, string& res, int pos) {
        if(num == 0) return;

        for(int i = 9; i >= 0; i--) {
            if(sum >= i && sum-i <= 9*(num-1) && sum-i >= 0) {
                res += ('0' + i);
                check(num-1, sum-i, res, pos+1);
                return;
            }
        }
    }
};