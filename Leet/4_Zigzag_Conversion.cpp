// https://leetcode.com/problems/zigzag-conversion/submissions/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        
        int step = 2 * numRows - 2;
        string res = s;
        int count = 0;
        
        for(int i=0; i<numRows; i++){
            if(i==0 || i == numRows-1){
                for(int j=i; j < s.size(); j+=step){
                    res[count] = s[j];
                    count++;
                }
            }
            else{
                int flag = 1;
                int j =i;
                while(j<s.size()){
                    res[count] = s[j];
                    count++;
                    
                    if(flag){
                        j += (numRows - i -1)*2;
                        flag = 0;
                    }
                    else{
                        j += 2*i;
                        flag = 1;
                    }
                }
            }
        }
        return res;
    }
};