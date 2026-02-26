class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        vector<pair<int,int>> v;

        // directly insert (NO skipping, duplicates preserved)
        for (int i = 0; i < arr.size(); i++) {
            v.push_back({arr[i], no(arr[i])});
        }

        // same sorting logic: value asc, tie -> key asc
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second < b.second;
        });

        // store back
        arr.clear();
        for (auto &p : v) {
            arr.push_back(p.first);
        }

        return arr;
    }

    // same recursive style, fixed logic
    int no(int n){
        if (n == 0) return 0;
        if (n % 2 == 0)
            return no(n >> 1);
        return 1 + no(n >> 1);
    }
};