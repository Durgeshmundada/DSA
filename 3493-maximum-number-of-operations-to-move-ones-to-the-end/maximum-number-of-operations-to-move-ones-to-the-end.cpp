class Solution {
public:
    int maxOperations(string s) {
        int count = 0;
        int check = 0;  // size of nearest zero-block

        int i = s.size() - 1;

        while(i >= 0) {

            if (s[i] == '0') {
                while(i >= 0 && s[i] == '0') {
                    i--;
                    
                }
                check ++;   // only nearest zero-block matters
            }

            else {

                if (check == 0) {
                    while(i >= 0 && s[i] == '1') i--;
                }
                else {
                    while(i >= 0 && s[i] == '1') {i--;

                    count += check;  // add only nearest block
                           // block consumed
                }
            
        }}
            }
        return count;
    }
};
