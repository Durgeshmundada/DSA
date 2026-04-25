class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
       vector<string> result;
       for(int i=0;i<queries.size();i++){
        for(int j=0;j<dictionary.size();j++){
            if(ok(queries[i],dictionary[j])){
                result.push_back(queries[i]);
                queries.erase(queries.begin()+i);
                i--;
                break;
            }
        }
       } 
       return result;
    }
    bool ok(string &a, string &b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            diff++;
            if (diff > 2) return false;
        }
    }
    return true;
}
};