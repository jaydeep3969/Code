// https://leetcode.com/problems/string-to-integer-atoi/submissions/

class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int neg_flag = 0;
        int res = 0;
        
        while(str[i] == ' ')
            i++;
        
        if(str[i] == '-'){
            neg_flag = 1;
            i++;
        }
        else if(str[i] == '+')
            i++;
        
        int digit = str[i]-'0';

        while(digit >= 0 && digit <= 9){
            if( res > INT_MAX/10 || (res == INT_MAX/10 && digit > 7)){
                if(neg_flag)
                    return INT_MIN;
                else 
                    return INT_MAX;
            }
            res = res * 10 + digit;
            i++;
            if(i == str.size())
                break;
            digit = str[i] - '0';
        }
        
        if(neg_flag)
            return res * -1;
        
        return res;
        
    }
};