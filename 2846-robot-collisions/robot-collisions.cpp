class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<vector<int>> check;
        for(int i = 0; i < n; i++){
            check.push_back({positions[i], healths[i], directions[i]=='L'?0:1, i});
        }

        sort(check.begin(), check.end());

        stack<int> s;

        for(int i = 0; i < n; i++){
            if(check[i][2] == 1){
                s.push(i); 
            }
            else{
                while(!s.empty() && check[i][1] > 0){
                    int j = s.top();

                    if(check[j][1] < check[i][1]){
                        check[i][1]--;
                        check[j][1] = 0;
                        s.pop();
                    }
                    else if(check[j][1] == check[i][1]){
                        check[j][1] = 0;
                        check[i][1] = 0;
                        s.pop();
                        break;
                    }
                    else{
                        check[j][1]--;
                        check[i][1] = 0;
                        break;
                    }
                }
            }
        }

        vector<pair<int,int>> survivors;

        for(auto &x : check){
            if(x[1] > 0){
                survivors.push_back({x[3], x[1]});
            }
        }

        sort(survivors.begin(), survivors.end());

        vector<int> result;
        for(auto &p : survivors){
            result.push_back(p.second);
        }

        return result;
    }
};