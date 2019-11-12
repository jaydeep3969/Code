// https://leetcode.com/problems/regular-expression-matching/submissions/		

class Solution {
    
public:
    
    
    bool isMatch(string s, string p) {
        if(!p.size())
            return (s.size() == 0);
        
        bool first_match  = s.size() && (s[0] == p[0] || p[0] == '.');
        
        if(p.size() >= 2 && p[1] == '*'){
            return ( isMatch(s, p.substr(2, p.size()-2))  /* Ignoring the star */ 
                     || 
                     ( first_match && isMatch(s.substr(1, s.size()-1), p)) /* continue while loop w/ star*/
                   );
        }
        else{
            return first_match && isMatch(s.substr(1, s.size()-1), p.substr(1, p.size()-1)); /* is++, ip++ */
        }
    }
};