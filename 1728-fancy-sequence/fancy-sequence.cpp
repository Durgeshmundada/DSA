class Fancy {
public:
    long long mod = 1000000007;

    vector<long long> result;
    long long add=0;
    long long mul=1;  

    Fancy() {}

    void append(int val) {
       val=(val-add+mod)%mod;
       val=(val*modInverse(mul,mod-2))%mod;
       result.push_back(val); 
    }

    void addAll(int inc) {
        add=(add+inc)%mod;
    }

    void multAll(int m) {
       mul=(mul*m)%mod;
       add=(add*m)%mod;
    }
    long long modInverse(long long a, long long b){
        long long res=1;
        a%=mod;
        while(b>0){
            if((b&1)==1) res=(res*a)%mod;
            a=(a*a)%mod;
            b>>=1;
        }
        return res;
    }
    int getIndex(int idx) {

        if(idx >= result.size()) return -1;
        long long r = result[idx];
        return (int)((r*mul+add)%mod);
    }
};