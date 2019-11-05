// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0/?ref=self
// Ref :  https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

// n*logn 
#include <iostream>
using namespace std;

int main() {
    int t;
    int n;
    
    cin >> t;
    
    while(t--){
        cin >> n;
        
        int i, a[n] = {0}, max = 0;
        
        cin >> i;
        n--;
        a[0] = i;
        
        while(n--){
            cin >> i;
        
            int j;
            for(j=0; j<=max; j++){
                if(a[j] == i)
                    break;
                    
                if(a[j] > i){
                    a[j] = i;
                    break;
                }
            }      
            
            if(j > max)
                a[++max] = i;
                
            // cout << i << " : ";
            // for(j=0; j<=max; j++)
            //     cout << a[j] << " ";
            // cout << "\n";
        }
        
        cout << max+1 << "\n";
    }   
	return 0;
}
