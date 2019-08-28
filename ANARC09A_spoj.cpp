//https://www.spoj.com/problems/ANARC09A/
//count var No use of Stack

#include <iostream>
using namespace std;

int go(string str){

    int count =0, st_count =0;
    
    for(std::string::size_type i=0; i < str.size(); i++)
    {
        if(str[i] == '{')
            st_count++;
        else if(str[i] == '}'){
            if(st_count != 0)
                st_count--;
            else{
                count++;
                st_count++;
            } 
        }
    }
    
    if(st_count != 0)
        count += st_count / 2;
        
    return count;
}

int main() {

	string str;
	int count = 0;
	while(1)
	{
	    getline(cin, str);
	    count++;
	    
	    if(str[0] == '-')
	        return 0;
	        
	    cout << count << ". " << go(str) << endl;
	    go(str);
	}
    return 0; 
}
