class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int diff = 0;
        int qdiff = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                qdiff++;
            else
                diff += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                qdiff--;
            else
                diff -= num[i] - '0';
        }

        if (qdiff == 0)
            return diff != 0;

       
        if (abs(qdiff) % 2 == 1)
            return true;


        int required = 9 * abs(qdiff) / 2;

        if (qdiff > 0)
            return diff != -required;
        else
            return diff != required;
    }
};