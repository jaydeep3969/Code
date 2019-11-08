// https://practice.geeksforgeeks.org/problems/boolean-matrix-problem/0/?track=md-arrays&batchId=144

#include <iostream>
using namespace std;

int main() {
    int t, r,c;
    
    cin >> t;
    
    while(t--){
        cin >> r;
        cin >> c;
        int a[r] = {0};
        int j[r] = {0};
        int in;
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin >> in;
                if(in){
                    a[i] = 1;
                    b[j] = 1;
                }
            }
        }
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(a[i] || b[j])
                    cout << 1 << " ";
                else
                    cout << 0 << " ";
            }
            cout << "\n";
        }
    }	
    
	return 0;
}
