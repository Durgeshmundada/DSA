class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] = abs(nums[i]);
        }

        multiset<int> s1;
        multiset<int> s2;
        unordered_map<int,int> um;

        int n = nums.size();

        for(int i = 0; i < n; i++){
            um[nums[i]]++;
        }

        for(int i = 0; i + 1 < n; i += 2){
            int big = max(nums[i], nums[i+1]);
            int small = min(nums[i], nums[i+1]);

            s1.insert(big);
            s2.insert(small);
        }

        if(n % 2 != 0){
            s1.insert(nums[n-1]);
        }

        while(!s1.empty() && !s2.empty()){
            auto it1 = s1.begin();
            auto it2 = prev(s2.end());

            if(*it2 > *it1){
                int a = *it1;
                int b = *it2;

                s1.erase(it1);
                s2.erase(it2);

                s1.insert(b);
                s2.insert(a);
            }
            else{
                break;
            }
        }

        long long ans = 0;

        for(auto x : s1){
            ans += 1LL * x * x;
        }

        for(auto x : s2){
            ans -= 1LL * x * x;
        }

        return ans;
    }
};
