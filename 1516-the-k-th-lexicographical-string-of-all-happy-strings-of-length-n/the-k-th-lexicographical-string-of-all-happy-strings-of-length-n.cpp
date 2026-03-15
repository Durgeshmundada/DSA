class Solution {
public:
    vector<string> result;
    vector<char> add = {'a','b','c'};

    void solve(int n, string curr) {

        if(curr.size() == n) {
            result.push_back(curr);
            return;
        }

        for(char c : add) {
            if(curr.empty() || curr.back() != c) {
                solve(n, curr + c);
            }
        }
    }

    string getHappyString(int n, int k) {

        solve(n, "");

        if(result.size() < k) return "";

        return result[k-1];
    }
};