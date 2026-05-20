class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>uma;
        unordered_map<int,int>umb;
        vector<int> result(A.size());
        for(int i=0;i<A.size();i++){
               int y=0;
                uma[A[i]]++;
                umb[B[i]]++;
            for(auto x:umb){
                if(uma.find(x.first)!=uma.end()){
                    uma[x.first]--;
                    umb[x.first]--;
                    y++;
                }
            }
            result[i]=y;
        }
        return result;
    }
};