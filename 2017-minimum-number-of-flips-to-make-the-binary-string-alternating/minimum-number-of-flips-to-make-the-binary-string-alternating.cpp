class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string s2 = s + s;

        int ans = INT_MAX;
        int diff1 = 0, diff2 = 0;

        for(int i = 0; i < 2*n; i++){

            if(s2[i] != (i%2 ? '1' : '0')) diff1++;
            if(s2[i] != (i%2 ? '0' : '1')) diff2++;

            if(i >= n){
                if(s2[i-n] != ((i-n)%2 ? '1' : '0')) diff1--;
                if(s2[i-n] != ((i-n)%2 ? '0' : '1')) diff2--;
            }

            if(i >= n-1){
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};