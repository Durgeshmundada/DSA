class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
        }
        vector<int> result;
        priority_queue<pair<int,int>> pq;
        for(auto i:um){
            pq.push({i.second,i.first});
        }
        for(int i=0;i<k;i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};