class Solution {
public:

    int longestValidParentheses(string s) {
       int max1=0;
       int count=0;
       stack<int> a;
       a.push(-1);
       for(int i=0;i<s.size();i++){
        
        if(s[i]=='('){
            
            a.push(i);
            
        }
        else{
            a.pop();
            if(a.empty()){
                
                a.push(i);

            }
            else{
                
                max1=max(max1,i-a.top());
                
            }
        }
       }
      
       return max1;
    }
};