class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> um;
        for(int i=0;i<nums.size();i++){
            um[nums[i]].push_back(i);
        }
        vector<int> result(queries.size());
        int n = nums.size();

        for (int i = 0; i < queries.size(); i++) {
            int idx = queries[i];
            vector<int> &v = um[nums[idx]];

            if (v.size() == 1) {
                result[i] = -1;
                continue;
            }
            auto it=lower_bound(v.begin(),v.end(),idx);
            int pos=it-v.begin();
            int m=v.size();
            int prev=v[(pos-1+m)%m];
            int next=v[(pos+1)%m];
            int d1 = abs(idx - prev);
            d1 = min(d1, n - d1);
            int d2 = abs(idx - next);
            d2 = min(d2, n - d2);

            result[i] = min(d1, d2);
        }
        return result;
    }
};