// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int i = 0;

        while(1) {
            bool first = true;
            char c;

            for (std::string &s : strs) {
                if( i < s.length()){
                    if(first){
                        c = s[i];
                        first = false;
                    }
                    else if(s[i] != c) {
                        return res;
                    }
                }
                else {
                    return res;
                }
            }

            res += c;
            i++;
        }

        return res;
    }
};