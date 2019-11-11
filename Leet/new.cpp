
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
        vector<char> v;
        
        while(is < s.size() && ip < p.size()){
            while(ip+1 < p.size() && p[ip+1] == '*'){
                  v.push_back(p[ip]);
                  ip += 2;
            }
            
            
            if(ip < p.size() && (p[ip] == s[is] || p[ip]=='.')){
                ip++; is++;
            }
            else{
                while(!v.empty() && is < s.size()){
                    if(v[0] == s[is] || v[0] == '.')
                        is++;
                    else{
                        v.erase(v.begin());
                    }
                }

                if(is < s.size()){
                    if(s[is] == p[ip]){
                        is++;
                        ip++;
                    }
                    else{
                        return false;
                    }    
                }
            }
        } 
        
        if(p[ip-1] == '*' || p[ip-1] == s[is]){
            while(!v.empty() && is < s.size()){
                if(v[0] == s[is] || v[0] == '.')
                    is++;
                else{
                    v.erase(v.begin());
                }
            }
        }
        
        if(is == s.size() && ip == p.size())
            return true;
        return false;
    }
};