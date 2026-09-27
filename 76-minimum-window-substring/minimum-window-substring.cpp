class Solution {
public:

    string minWindow(string s, string t) {

        string res = "";
        unordered_map<char,int> um;

        for(int i = 0; i < t.size(); i++){
            um[t[i]]++;
        }

        string ch = "";
        int count = 0;

        for(int i = 0; i < s.size(); i++){

            ch += s[i];

            if(um.find(s[i]) != um.end()){
                if(um[s[i]] > 0)
                    count++;

                um[s[i]]--;
            }

            while(count == t.size()){

                if(res == "" || ch.size() < res.size()){
                    res = ch;
                }

                if(um.find(ch[0]) != um.end()){

                    um[ch[0]]++;

                    if(um[ch[0]] > 0)
                        count--;
                }

                ch.erase(0,1);
            }
        }

        return res;
    }
};