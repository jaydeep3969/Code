// MAX Heap Sort

/* G4G
// MAX Heap Sort

#include <iostream>
using namespace std;

typedef long long int lli;

// Merge ar1[] and ar2[] with O(1) extra space 
void merge(lli ar1[], lli ar2[], lli m, lli n) 
{ 
    // Iterate through all elements of ar2[] starting from 
    // the last element 
    for (lli i=n-1; i>=0; i--) 
    { 
        // Find the smallest element greater than ar2[i]. Move all 
         //  elements one position ahead till the smallest greater 
          // element is not found 
        lli j, last = ar1[m-1]; 
        for (j=m-2; j >= 0 && ar1[j] > ar2[i]; j--) 
            ar1[j+1] = ar1[j]; 
  
        // If there was a greater element 
        if (j != m-2 || last > ar2[i]) 
        { 
            ar1[j+1] = ar2[i]; 
            ar2[i] = last; 
        } 
    } 
} 

int main() {
    
    lli t; 
    lli m,n;
    
    cin >> t;
    
    while(t--){
        cin >> m >> n;
        lli a[m] = {0}, b[n] = {0};
		
        for(lli i=0; i<m; i++)
            cin >> a[i];
        
        for(lli i=0; i<n; i++)
            cin >> b[i];
            
        merge(a, b, m, n);
        
        for(lli i=0; i<m; i++)
            cout << a[i] << " ";
            
		for(lli i=0; i<n; i++)
            cout << b[i] << " ";
        cout << "\n";
    }
	return 0;
}
*/

#include <iostream>
using namespace std;

typedef long long int lli;

void swap(lli *a, lli *b){
	lli *tmp;
	*tmp = *a; 
	*a = *b;
	*b = *tmp;
}

lli* actual_value(lli a[], lli b[], lli m, lli ind){
	if(ind < m)
		return &a[ind];
	else 
		return &b[ind-m];
}

void heapify(lli a[], lli b[], lli m, lli size, lli i){
    lli largest = i;
    lli l = 2*i +1;
    lli r = 2*i +2;
    
    if(l<size && *actual_value(a,b,m,l) > *actual_value(a,b,m,largest))
        largest = l;
    
    if(r<size && *actual_value(a,b,m,r) > *actual_value(a,b,m,largest))
        largest = r;
    
    if(largest != i){
        swap(actual_value(a,b,m,largest), actual_value(a,b,m,i));
        heapify(a, b, m, size, largest);
    }
}

void HS(lli a[], lli b[], lli m, lli n){
    
    for(lli i=(m+n)/2-1; i >=0 ; i--)
        heapify(a, b, m, m+n, i);
    
    for(lli i=m+n-1; i >=0; i--){
        swap(&a[0], actual_value(a,b,m,i));
        heapify(a, b, m, i, 0);
    }
}

int main() {
    
    int t; 
    lli m,n;
    
    cin >> t;
    
    while(t--){
        cin >> m >> n;
        lli a[m] = {0}, b[n] = {0};
		
        for(lli i=0; i<m; i++)
            cin >> a[i];
        
        for(lli i=0; i<n; i++)
            cin >> b[i];
            
        HS(a, b, m, n);
        
        for(lli i=0; i<m; i++)
            cout << a[i] << " ";
            
		for(lli i=0; i<n; i++)
            cout << b[i] << " ";
        cout << "\n";
    }
	return 0;
}
