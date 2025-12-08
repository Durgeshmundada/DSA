class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        
        for (int a = 1; a <= n; a++) {
            for (int b = a; b <= n; b++) {
                int c2 = a * a + b * b;
                int c = sqrt(c2);
                if (c > n) break;
                if (c * c == c2) {
                    if (a == b) {
                      
                        count += 1;
                    } else {
                        
                        count += 2;
                    }
                }
            }
        }

        return count;
    }
};
