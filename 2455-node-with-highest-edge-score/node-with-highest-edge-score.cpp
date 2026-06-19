class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> score(n, 0); 
        for(int i = 0; i < n; i++){
            score[edges[i]] += i;
        }
        int best_node = 0;
        for(int i = 1; i < n; i++) {
            if(score[i] > score[best_node]) {
                best_node = i;
            }
        }
        
        return best_node;
    }
};