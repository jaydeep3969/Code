// MAX Heap Sort

#include <iostream>
using namespace std;

typedef long long int lli;

void heapify(lli a[], lli n, lli i){
    lli largest = i;
    lli l = 2*i +1;
    lli r = 2*i +2;
    
    if(l<n && a[l] > a[largest])
        largest = l;
    
    if(r<n && a[r] > a[largest])
        largest = r;
    
    if(largest != i){
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}

void HS(lli a[], lli n){
    
    for(lli i=n/2-1; i >=0 ; i--)
        heapify(a, n, i);
    
    for(lli i=n-1; i >=0; i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main() {
    
    int t; 
    lli n;
    
    cin >> t;
    
    while(t--){
        cin >> n;
        lli a[n];
        
        for(lli i=0; i<n; i++)
            cin >> a[i];
            
        HS(a,n);
        
        for(lli i=0; i<n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
	return 0;
}
