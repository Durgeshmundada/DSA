class Solution {
public:
    vector<int> maxTree;
    vector<int> minTree;
    int n;

    long long getKey(int l, int r) {
        return ((long long)l << 32) | r;
    }

    void insert(int node, int lo, int hi, int idx, int val) {
        if(lo == hi) {
            maxTree[node] = val;
            minTree[node] = val;
            return;
        }

        int mid = lo + (hi - lo) / 2;

        if(idx <= mid) {
            insert(2 * node, lo, mid, idx, val);
        } else {
            insert(2 * node + 1, mid + 1, hi, idx, val);
        }

        maxTree[node] = max(maxTree[2 * node], maxTree[2 * node + 1]);
        minTree[node] = min(minTree[2 * node], minTree[2 * node + 1]);
    }

    pair<int,int> cal(int node, int lo, int hi, int l, int r) {
        // no overlap
        if(r < lo || hi < l) {
            return {INT_MAX, INT_MIN};
        }

        // full overlap
        if(l <= lo && hi <= r) {
            return {minTree[node], maxTree[node]};
        }

        int mid = lo + (hi - lo) / 2;

        pair<int,int> left = cal(2 * node, lo, mid, l, r);
        pair<int,int> right = cal(2 * node + 1, mid + 1, hi, l, r);

        int mini = min(left.first, right.first);
        int maxi = max(left.second, right.second);

        return {mini, maxi};
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        n = nums.size();

        maxTree.resize(4 * n);
        minTree.resize(4 * n);

        for(int i = 0; i < n; i++) {
            insert(1, 0, n - 1, i, nums[i]);
        }

        priority_queue<vector<long long>> pq;
        unordered_set<long long> visited;

        pair<int,int> val = cal(1, 0, n - 1, 0, n - 1);

        long long x = val.second; // max
        long long y = val.first;  // min

        pq.push({x - y, 0, n - 1});
        visited.insert(getKey(0, n - 1));

        long long ans = 0;

        while(k > 0 && !pq.empty()) {
            vector<long long> temp = pq.top();
            pq.pop();

            long long value = temp[0];
            int l = temp[1];
            int r = temp[2];

            ans += value;
            k--;

            // remove left
            if(l + 1 <= r && visited.find(getKey(l + 1, r)) == visited.end()) {
                pair<int,int> leftVal = cal(1, 0, n - 1, l + 1, r);

                long long maxi = leftVal.second;
                long long mini = leftVal.first;

                pq.push({maxi - mini, l + 1, r});
                visited.insert(getKey(l + 1, r));
            }

            // remove right
            if(l <= r - 1 && visited.find(getKey(l, r - 1)) == visited.end()) {
                pair<int,int> rightVal = cal(1, 0, n - 1, l, r - 1);

                long long maxi = rightVal.second;
                long long mini = rightVal.first;

                pq.push({maxi - mini, l, r - 1});
                visited.insert(getKey(l, r - 1));
            }
        }

        return ans;
    }
};