class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>um;
        for (int i = 0; i < arr1.size(); i++) {
          int num = arr1[i];
           while (num > 0) {
            um[num] = 1;
            num /= 10;
    }
}
int ans=0;
for (int i = 0; i < arr2.size(); i++) {
    int num = arr2[i];
    while (num > 0) {
        if (um.count(num)) {
            ans = max(ans, (int)to_string(num).size());
            break;
        }
        num /= 10;
    }
}
return ans;
    }
};