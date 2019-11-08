#include <iostream>
using namespace std;

int bin_search(int a[], int l, int r, int k){
    if(l <= r){
        int mid = (l+r)/2;
        if(a[mid] == k)
            return mid;
        else if(a[mid] > k)
            bin_search(a,l,mid-1,k);
        else
            bin_search(a,mid+1,r,k);
    }
    else
        return -1;
}

int main() {
    int t;
    int n,k;
    
    cin >> t;
    
    while(t--){
        cin >> n;
        int a[n];
        
        for(int i=0; i<n; i++)
            cin >> a[i];
            
        cin >> k;
        
        cout << bin_search(a, 0, n-1, k) << "\n";
    }	    
    
	return 0;
}