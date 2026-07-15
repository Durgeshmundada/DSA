class Solution {
public:
    string frequencySort(string s) {
       priority_queue<pair<int, char>> pq;
       unordered_map<char,int>um;
       for(int i=0;i<s.size();i++){
            um[s[i]]++;
       } 
       for(auto x:um){
            pq.push({x.second,x.first});
       }
       string result="";
       while(!pq.empty()){
        pair<int,char>c=pq.top();
           for(int i=0;i<c.first;i++)
             result+=c.second;
            pq.pop();
       }
       return result;

    }
};