class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
      vector<int> freq(121, 0);
        for (int a : ages) freq[a]++;
        
        int count = 0;
        for (int a = 1; a <= 120; a++) {
            for (int b = 1; b <= 120; b++) {
                if (freq[a] == 0 || freq[b] == 0) continue;
                if (!(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100))) {
                    count += freq[a] * freq[b];
                    if (a == b) count -= freq[a]; // remove self-requests
                }
            }
        }
        return count;
    }
};