class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       unordered_map<int,int> um;
       vector<int> s=arr;
       sort(s.begin(),s.end());
       int rk=1;
       for(int i=0;i<s.size();i++){
          if(um.find(s[i])==um.end()){
            um[s[i]]=rk;
            rk++;
          }
       } 
       vector<int> result(arr.size());
       for(int i=0;i<arr.size();i++){
            result[i]=um[arr[i]];
       }
       return result;
    }
};