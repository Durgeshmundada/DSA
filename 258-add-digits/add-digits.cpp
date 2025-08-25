class Solution {
public:
    int addDigits(int num) {
       int sum=0;
       if(num<10){
        return num;
       }
        while(num>=10){
            sum=sum+num%10;
            num=num/10;
            if(num<10 ){
             sum=sum+num;
             num=sum; 
             if(num>=10){
                sum=0;
             }  
            }
        }

        
        return sum;
    }
};