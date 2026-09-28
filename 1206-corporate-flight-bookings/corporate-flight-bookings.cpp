class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n+2,0);
        for(int i=0;i<bookings.size();i++){
           
                res[bookings[i][0]]+=bookings[i][2];
                res[bookings[i][1]+1]-=bookings[i][2];
            
        }
        for(int i=1;i<n+2;i++){
            res[i]+=res[i-1];
        }
        vector<int>ans;
        for(int i=1;i<=n;i++)ans.push_back(res[i]);
        return ans;
    }
};