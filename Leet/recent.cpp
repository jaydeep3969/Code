// https://leetcode.com/problems/regular-expression-matching/submissions/
class Solution {
public:
    bool isMatch(string s, string p) {
        if(!s.size()){
            if(!p.size())
                return true;
            else
                return false;
        }
        
        int is=0, ip = 0, count=1;
        char last_ele;
        
        while(is < s.size() && ip < p.size()){
            if(p[ip] == '*'){
                // cout << "*\n";
                if(s[is] == p[ip-1] || p[ip-1] == '.'){
                    last_ele = s[is];
                    count++;
                    is++;
                }
                else {
                    count = 1;
                    ip++;
                }
            }
            else if(s[is] == p[ip] || p[ip] == '.'){
                // cout << "Same or .\n";
                is++;
                ip++;
            }
            else
                ip++;
        }
        
        if(is == s.size() && ip == p.size())
            return true;
        else if(ip != p.size()){
            if(p[ip] != '*' && p[ip+1] == '*'){
                ip++;
                
                while(ip+1 < p.size() && p[ip+1] == '*'){
                    ip += 2;
                }
                
                if(ip == p.size())
                    return true;
                else{
                    if(p[ip] == last_ele || last_ele == '.'){
                        ip++;   
                        count
                    }
                }
            }
        }
        return false;
    }
};