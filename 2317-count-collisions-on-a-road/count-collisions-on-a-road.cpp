class Solution {
public:
    int countCollisions(string d) {
        int n = d.size();
        if (n == 0) return 0;

        int start = 0;
        int end = n - 1;
        while (start < n && d[start] == 'L') ++start;
        while (end >= 0 && d[end] == 'R') --end;

        if (start > end) return 0; 
        int count=0;
        for(int i=start;i<=end;i++){
          if(d[i]!='S'){
            ++count;
          }
        }
        return count;
    }
};