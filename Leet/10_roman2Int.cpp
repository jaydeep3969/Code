//https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> dict;
        
        dict.insert(pair<char,int>('I',1));
        dict.insert(pair<char,int>('V',5));
        dict.insert(pair<char,int>('X',10));
        dict.insert(pair<char,int>('L',50));
        dict.insert(pair<char,int>('C',100));
        dict.insert(pair<char,int>('D',500));
        dict.insert(pair<char,int>('M',1000));
        dict.insert(pair<char,int>('G',5000));
        dict.insert(pair<char,int>('H',10000));

        int res = 0;
        
        for(int i=0; i < s.length(); i++) {
            int s1 = dict.find(s[i]) -> second;
            
            if(i+1 < s.length()){
                int s2 = dict.find(s[i+1]) -> second;
                
                if(s1 >= s2) {
                    res += s1;
                }
                else {
                    res += s2 - s1;
                    i++;
                }
            }
            else {
                res += s1;
            }
        }
        
        return res;
    }
};