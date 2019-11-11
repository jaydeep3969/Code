//  https://leetcode.com/problems/palindrome-number/solution/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        
        int tmp = x, len =0;
        
        while(tmp != 0){
            len++;
            tmp /= 10;
        }
        
        while(x != 0){
            if(len == 1 || !len)
                return true;
            
            int last  = x % 10;
            int first = x / pow(10,len-1);
            
            if(first != last)
                return false;
            
            len -= 2;
            
            x /= 10;
            int t = pow(10, len);
            x = x % t;
            
        }
        
        return true;
    }
};