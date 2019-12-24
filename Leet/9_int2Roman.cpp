//https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int num) {
        map<int,char> dict;
        
        dict.insert(pair<int,char>(1,'I'));
        dict.insert(pair<int,char>(5,'V'));
        dict.insert(pair<int,char>(10,'X'));
        dict.insert(pair<int,char>(50,'L'));
        dict.insert(pair<int,char>(100,'C'));
        dict.insert(pair<int,char>(500,'D'));
        dict.insert(pair<int,char>(1000,'M'));

        int divisor = 1;
        int tmp = num;
        
        while(tmp >= divisor){
            divisor *= 10;
        }

        divisor /= 10;
        
        string res = "";
        
        while(num) {
            int sig_digit = num/divisor;
        
            if(sig_digit <= 3) {
                res.append(sig_digit, dict.find(divisor) -> second);
            }
            else if(sig_digit == 4) {
                res.append(1, dict.find(divisor) -> second);
                res.append(1, dict.find(divisor*5) -> second);
            }
            else if(sig_digit <= 8) {
                res.append(1, dict.find(divisor*5) -> second);
                res.append(sig_digit-5, dict.find(divisor) -> second);
            }
            else {
                res.append(1, dict.find(divisor) -> second);
                res.append(1, dict.find(divisor*10) -> second);
            }
            
            num = num % divisor;
            divisor /= 10;
        }
        
        return res;
    }
};