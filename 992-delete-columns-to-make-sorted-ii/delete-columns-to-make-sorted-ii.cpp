class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
    int m=strs.size();
    int n=strs[0].size();
    int count=0;
    vector<bool> b(m-1,false);
    for(int i=0;i<n;i++){
        bool z=false;
        for(int j=0;j<m-1;j++){
            if(!b[j] && strs[j][i]>strs[j+1][i]){
                z=true;
                break;
            }
        }
        if(z){
            count++;
            continue;
        }
        for(int j=0;j<m-1;j++){
            if(!b[j] && strs[j][i]<strs[j+1][i]){
                b[j]=true;
            }
        }
    }
    return count;
    }
};
