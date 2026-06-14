class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long long mod = 1e9 + 7;

        sort(arr.begin(), arr.end());

        vector<long long> dp(arr.size(), 1);

        unordered_map<int,int> um;
        for(int i = 0; i < arr.size(); i++){
            um[arr[i]] = i;
        }

        long long result = 0;

        for(int i = 0; i < arr.size(); i++){
            long long sum = 1;

            int j = 0;
            while(j < i){
                if(arr[i] % arr[j] == 0){
                    int other = arr[i] / arr[j];

                    if(um.find(other) != um.end()){
                        sum = (sum + dp[j] * dp[um[other]]) % mod;
                    }
                }
                j++;
            }

            dp[i] = sum;
            result = (result + dp[i]) % mod;
        }

        return result;
    }
};