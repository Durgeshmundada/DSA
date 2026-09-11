class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        unordered_map<int, int> um;

        for(int x : digits)
            um[x]++;

        int E = 0, O = 0;       // distinct even / odd digits
        int E2 = 0, E3 = 0;     // even digits appearing >=2, >=3
        int O2 = 0;             // odd digits appearing >=2

        for(auto x : um) {

            if(x.first % 2 == 0) {
                E++;

                if(x.second >= 2)
                    E2++;

                if(x.second >= 3)
                    E3++;
            }
            else {
                O++;

                if(x.second >= 2)
                    O2++;
            }
        }

        // Number of ordered pairs of even digits.
        // Different digits: E * (E-1)
        // Same digit: E2
        int EE = E * (E - 1) + E2;

        // Number of ordered pairs of odd digits.
        // Different digits: O * (O-1)
        // Same digit: O2
        int OO = O * (O - 1) + O2;


        // -------------------------
        // EEE
        // -------------------------
        //
        // All 3 digits different:
        //      E * (E-1) * (E-2)
        //
        // One digit repeated:
        //      C(E2,1) * (E-1) * 3
        //
        // Same digit 3 times:
        //      E3
        //
        int EEE =
            E * (E - 1) * (E - 2)
            + 3 * E2 * (E - 1)
            + E3;


        // -------------------------
        // EOE
        // -------------------------
        //
        // two even positions + one odd
        //
        int EOE = EE * O;


        // -------------------------
        // OEE
        // -------------------------
        //
        // one odd + two even
        //
        int OEE = O * EE;


        // -------------------------
        // OOE
        // -------------------------
        //
        // two odd + one even
        //
        int OOE = OO * E;


        // --------------------------------
        // Remove numbers starting with 0
        // --------------------------------

        if(um[0] > 0) {

            /*
                EEE starting with 0

                After using one zero, available distinct
                even digits are:

                E-1 non-zero even digits
                + zero again if frequency[0] >= 2
            */

            int availableEven =
                (E - 1) + (um[0] >= 2);

            /*
                Ordered pair after the leading zero.

                Different digits:
                    availableEven * (availableEven - 1)

                Same digit:
                    digits having >= 2 copies remaining
            */

            int repeatedEven =
                E2 - (um[0] >= 2) + (um[0] >= 3);

            int invalidEEE =
                availableEven * (availableEven - 1)
                + repeatedEven;

            EEE -= invalidEEE;


            /*
                EOE starting with 0

                0 _ E

                After consuming one zero, possible
                even digits for the last position:
            */

            int lastEven =
                (E - 1) + (um[0] >= 2);

            int invalidEOE =
                lastEven * O;

            EOE -= invalidEOE;
        }


        return EEE + EOE + OEE + OOE;
    }
};