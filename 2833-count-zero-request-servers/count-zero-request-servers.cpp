class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        vector<pair<int,int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> res(queries.size());
        vector<int> freq(n + 1, 0);

        int left = 0, right = 0;
        int active = 0;

        for (int i = 0; i < q.size(); i++) {

            int start = q[i].first - x;
            int end = q[i].first;

            while (right < logs.size() && logs[right][1] <= end) {
                int id = logs[right][0];

                if (freq[id] == 0) active++;

                freq[id]++;
                right++;
            }

            while (left < right && logs[left][1] < start) {
                int id = logs[left][0];

                freq[id]--;

                if (freq[id] == 0) active--;

                left++;
            }

            res[q[i].second] = n - active;
        }

        return res;
    }
};