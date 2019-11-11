class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(!s.size())
            return 0;
        
        int flag[128] = {0};
        int si=0;
        int max_len=1;
        
        for(int i=0; i<s.size(); i++){
            
            if(!flag[int(s[i])]){
                // First Occurance
                flag[int(s[i])] = 1;
            }
            else{
                if(i-si > max_len)
                    max_len = i-si;
                while(s[si] != s[i]){
                    flag[int(s[si])] = 0;
                    si++;
                }  
                si++;
            }
        }
        
        if(s.size()-si > max_len)
            max_len = s.size()-si;
        
        return max_len;
    }
};