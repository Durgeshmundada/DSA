class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int>um;
        vector<vector<string>> res;
        int x=0;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            if(um.find(s)==um.end()){
                um[s]=x;
                x++;
                res.push_back({strs[i]});
            }
            else{
                res[um[s]].push_back(strs[i]);
            }
        } 
        
       return res;
    }
};