// Kadane's Algo


// 0.24
#include <iostream>
using namespace std;

typedef long long int lli;

int main() {
    int t;
    lli n;
    
    cin >> t;
    
    while(t--){
        cin >> n;
        
        lli max_sum =0, max_neg = 0, cur_sum = 0;
        lli a;
        
        while(n--){
            cin >> a;
            
            if(a<0 && !max_sum)
            {
                if(!max_neg){
                    max_neg = a;
                }
                else if(max_neg < a)
                    max_neg = a;
            }
            
            cur_sum += a;
            
            if(cur_sum > max_sum)
                max_sum = cur_sum;
            else if(cur_sum < 0)
                cur_sum = 0;
        }
        
        if(!max_sum)
            cout << max_neg << "\n";
        else
            cout << max_sum << "\n";
    }   
	return 0;
}

// 0.3 ----------------------------------------------------------------------------------------------------------------------------------------------------

/*

// Kadane's Algo

#include <iostream>
#include <climits>
using namespace std;

typedef long long int lli;

int main() {
    int t;
    lli n;
    
    cin >> t;
    
    while(t--){
        cin >> n;
        
        lli max_sum = INT_MIN, cur_sum = 0;
        lli a;
        
        while(n--){
            cin >> a;
            
            cur_sum += a;
            
            if(cur_sum > max_sum)
                max_sum = cur_sum;
            
            if(cur_sum < 0)
                cur_sum = 0;
        }
        
        cout << max_sum << "\n";
    }   
	return 0;
}

*/

// ----------------------------------------------------------------------------------------------------------------------------------------------------
// Indexes of that subarray which have max sum 
/*
#include <iostream>
using namespace std;

typedef long long int lli;

int main() {
    int t;
    lli n;
    
    cin >> t;
    
    while(t--){
        cin >> n;
        
        lli max_sum =0, max_neg = 0, cur_sum = 0;
        lli max_start=0, max_end, cur_start=0, cur_end, count = -1;
        lli a;
        
        while(n--){
            cin >> a;
            count++;
            
            if(a<0 && !max_sum)
            {
                if(!max_neg){
                    max_neg = a;
                    max_start = max_end = cur_start = count;
                } 
                else if(max_neg < a){
                    max_neg = a;
                    max_start = max_end = cur_start = count;
                }
                    
            }
            
            cur_sum += a;
            cur_end = count;
            
            if(cur_sum > max_sum){
                max_sum = cur_sum;
                max_start = cur_start;
                max_end = cur_end;
            }  
            else if(cur_sum < 0){
                cur_sum = 0;
                cur_start = count + 1;
            }
                
        }
        
        if(!max_sum)
            cout << max_neg << "\n";
        else
            cout << max_sum << "\n";
            
        cout << "Start : " << max_start << " End : " << max_end << "\n";
    }   
	return 0;
}
*/