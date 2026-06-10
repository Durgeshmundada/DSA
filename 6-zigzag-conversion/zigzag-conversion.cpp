class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        int x = numRows - 1 + numRows - 2 + 1; // cycle
        string result = "";

        for(int i = 0; i < numRows; i++) {
            int y = i;

            int jump1 = x - 2 * i;
            int jump2 = 2 * i;

            bool flag = true;

            while(y < s.size()) {
                result += s[y];

                if(i == 0 || i == numRows - 1) {
                    y += x;
                }
                else {
                    if(flag) {
                        y += jump1;
                    }
                    else {
                        y += jump2;
                    }

                    flag = !flag;
                }
            }
        }

        return result;
    }
};