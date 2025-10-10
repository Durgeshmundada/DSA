class Solution {
public:
int count=0;
    string getPermutation(int n, int k) {
       vector<int> v(n);
        iota(v.begin(), v.end(), 1); 
       string s="";
       int i = 0;
        int blockSize = fact(n - 1);
        while (k > blockSize) {
            k -= blockSize;
            i++;
        }

        s += to_string(v[i]);
        v[i] = -1;

        return check(v, s, k);
    }
    int fact(int n){
        if(n<2){
            return 1;
        }
        return n*fact(n-1);
    }
    string check(vector<int> r,string s,int k){
        
        if(s.size()==r.size()){  
            count++;
            if (count == k) return s;  
            return "";
        }
        for(int i=0;i<r.size();i++){
            if (r[i] == -1) continue;  // skip used numbers

            int temp = r[i];
            r[i] = -1;                 // mark as used
            string result = check(r, s + to_string(temp), k);
            r[i] = temp;  
            if (result != "") return result;
        }
        return "";
    }
};