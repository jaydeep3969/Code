//https://leetcode.com/problems/regular-expression-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        if(!s.size()){
            if(!p.size())
                return true;
            else
                return false;
        }
        
        int is=0, ip = 0;
        
        while(is < s.size() && ip < p.size()){
            if(p[ip] == '*'){
                cout << "*\n";
                if(s[is] == p[ip-1] || p[ip-1] == '.')
                    is++;
                else 
                    ip++;
            }
            
            if(s[is] == p[ip] || p[ip] == '.'){
                cout << "Same or .\n";
                is++;
                ip++;
            }
        }
        
        if(is == s.size())
            return true;
        return false;
    }
};