class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> u;
        sort(arr.begin(),arr.end());
        int f=-1;
        for(int i=0;i<arr.size();i++){
            u[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(u[arr[i]]==arr[i]){
              f=arr[i];
            }
        }
        return f;
    }
};