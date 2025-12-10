class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int n = s.size();
        int wlen = words[0].size();     // length of each word
        int wcnt = words.size();        // number of words
        int f = wlen * wcnt;            // total length of concatenation

        if (n < f) return result;

        unordered_map<string,int> um;   // target freq
        for (auto &w : words) um[w]++;

        // try all alignments mod wlen
        for (int off = 0; off < wlen; off++) {
            unordered_map<string,int> cur;  // current window freq
            int left = off;                 // left index of window
            int used = 0;                   // number of words currently in window

            // move right in steps of wlen
            for (int right = off; right + wlen <= n; right += wlen) {
                string z = s.substr(right, wlen);

                if (um.count(z)) {
                    cur[z]++;
                    used++;

                    // too many of this word → shrink from left
                    while (cur[z] > um[z]) {
                        string zl = s.substr(left, wlen);
                        cur[zl]--;
                        left += wlen;
                        used--;
                    }

                    // if window has exactly wcnt words → valid start
                    if (used == wcnt) {
                        result.push_back(left);

                        // pop one word from left and continue sliding
                        string zl = s.substr(left, wlen);
                        cur[zl]--;
                        left += wlen;
                        used--;
                    }
                } else {
                    // this word not in target → reset window
                    cur.clear();
                    used = 0;
                    left = right + wlen;
                }
            }
        }

        return result;
    }
};
