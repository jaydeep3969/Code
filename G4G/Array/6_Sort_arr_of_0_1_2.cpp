// Sort an array of 0's, 1's and 2's :- https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0/?ref=self
// Suggestion : Immidiate Smaller Ele  :- https://practice.geeksforgeeks.org/problems/immediate-smaller-element/0/?ref=self
#include <iostream>
using namespace std;

typedef unsigned long long int ulli;

int main() {
    int t;
    
    ulli n,i;
    
    cin >> t;
    
    while(t--){
        cin >> n;
        ulli a[3] = {0};
        
        while(n--){
            cin >> i;
            a[i]++;
        }
        
        for(int j=0; j < 3; j++){
            while(a[j]--)
                cout << j << " ";
        }
        
        cout << "\n";
    }
    
	return 0;
}
