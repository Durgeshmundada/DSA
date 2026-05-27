class Solution {
public:
    int numberOfSpecialChars(string word) {

        unordered_map<char,int> upper;
        for(int i = 0; i < word.size(); i++) {

            char ch = word[i];

            if(isupper(ch)) {

                char lower = tolower(ch);

                if(upper.find(lower) == upper.end()) {
                    upper[lower] = i;
                }
            }
        }

        int count = 0;
        for(int i = word.size() - 1; i >= 0; i--) {

            if(islower(word[i])) {

                char ch = word[i];

                if(upper.find(ch) != upper.end() && upper[ch] != -1) {

                    if(i < upper[ch]) {
                        count++;
                    }

                    upper[ch] = -1;
                }
            }
        }

        return count;
    }
};