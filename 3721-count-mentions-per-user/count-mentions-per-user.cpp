class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
       sort(events.begin(), events.end(),
     [](const vector<string>& a, const vector<string>& b) {
         int ta = stoi(a[1]);
         int tb = stoi(b[1]);

         // primary: time ascending
         if (ta != tb) return ta < tb;

         // secondary: OFFLINE before MESSAGE
         if (a[0] != b[0])
             return a[0] == "OFFLINE";

         return false; // keep original order otherwise
     });

    vector<int> time(numberOfUsers,0);
    vector<int> result(numberOfUsers,0);
    for(int i=0;i<events.size();i++){
        int t=stoi(events[i][1]);
        if(events[i][0]=="MESSAGE"){
            if(events[i][2]=="HERE"){
                
                for(int j=0;j<numberOfUsers;j++){
                    if(time[j]<=t){
                        result[j]++;
                    }
                }
            }
            else if(events[i][2]=="ALL"){
                for(int j=0;j<result.size();j++){
                    result[j]++;
                }
            }
            else {
                
                for (int j = 0; j < events[i][2].size(); j++) {
                        if (events[i][2][j] == 'i' && events[i][2][j+1] == 'd') {
                            j += 2;
                            int x = 0;
                     while (j < events[i][2].size() && isdigit(events[i][2][j])){
                                x = x * 10 + (events[i][2][j] - '0');
                                j++;
                            }
                            result[x]++;   
                        }
                    }
            }
        }
        else{
               int id = stoi(events[i][2]);
                time[id] = t + 60;

        }
    }
        return result;
    }
    
};