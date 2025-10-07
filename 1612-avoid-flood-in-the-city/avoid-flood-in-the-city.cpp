class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,int> um;
        vector<int> result(rains.size(),1);
        set<int> dryDays; 
        vector<int> result1;
        for(int i=0;i<rains.size();i++){
            if(rains[i]!=0){
               
            if(um.find(rains[i]) != um.end()){
                auto it = dryDays.upper_bound(um[rains[i]]);
                    if(it == dryDays.end()) {
                        return result1; // flood: no dry day available
                    }

                    result[*it] = rains[i]; // dry this lake
                    dryDays.erase(it);
               
                }
                result[i]=-1;
                um[rains[i]]=i;
            }
           else{
                dryDays.insert(i);
                }
    }
         
        return result;
    }
};