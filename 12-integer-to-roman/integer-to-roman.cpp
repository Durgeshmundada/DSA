class Solution {
public:
    string intToRoman(int num) {

        unordered_map<int,int> um1;

        um1[1] = 0;
        um1[5] = 1;
        um1[10] = 2;
        um1[50] = 3;
        um1[100] = 4;
        um1[500] = 5;
        um1[1000] = 6;

        um1[4] = 7;
        um1[9] = 8;
        um1[40] = 9;
        um1[90] = 10;
        um1[400] = 11;
        um1[900] = 12;

        vector<string> um(13);

        um[0] = "I";
        um[1] = "V";
        um[2] = "X";
        um[3] = "L";
        um[4] = "C";
        um[5] = "D";
        um[6] = "M";

        um[7] = "IV";
        um[8] = "IX";
        um[9] = "XL";
        um[10] = "XC";
        um[11] = "CD";
        um[12] = "CM";

        vector<int> val = {
            1000, 900, 500, 400,
            100, 90, 50, 40,
            10, 9, 5, 4, 1
        };

        string res = "";

        for(int i = 0; i < val.size(); i++) {

            while(num >= val[i]) {
                res += um[um1[val[i]]];
                num -= val[i];
            }
        }

        return res;
    }
};