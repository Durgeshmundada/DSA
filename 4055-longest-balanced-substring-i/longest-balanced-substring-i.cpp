class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int mn = INT_MAX, mx = 0;
                for (int c = 0; c < 26; c++) {
                    if (freq[c] > 0) {
                        mn = min(mn, freq[c]);
                        mx = max(mx, freq[c]);
                    }
                }

                if (mn == mx) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
