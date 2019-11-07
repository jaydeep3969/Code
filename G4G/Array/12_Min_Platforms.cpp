// Using Heap Sort
// https://practice.geeksforgeeks.org/problems/minimum-platforms/0/?track=md-arrays&batchId=144
// Maximum of all subarrays of size k : https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0/?ref=self

#include <iostream>
using namespace std;

void heapify(int a[], int d[], int n, int i){
    int largest = i;
    int l = 2*i +1;
    int r = 2*i +2;
    
    if(l<n && a[l] > a[largest])
        largest = l;
    
    if(r<n && a[r] > a[largest])
        largest = r;
    
    if(largest != i){
        swap(a[largest], a[i]);
        swap(d[largest], d[i]);
        heapify(a,d, n, largest);
    }
}

void HS(int a[], int d[], int n){
    
    for(int i=n/2-1; i >=0 ; i--)
        heapify(a,d, n, i);
    
    for(int i=n-1; i >=0; i--){
        swap(a[0], a[i]);
        swap(d[0], d[i]);
        heapify(a,d, i, 0);
    }
}

int arrange(int a[], int d[], int n){
    int p[n] = {0}; // p stores max dep time on that platform
    int max_ind = 1; //max number of platforms
    
    p[0] = d[0];
    
    for(int j=1; j<n; j++){
        int i;
        for(i=0; i<max_ind; i++){
            if(p[i] < a[j]){
                p[i] = d[j];
                break;
            }
        }    
        
        if(i == max_ind){
            p[max_ind] = d[j];
            max_ind++;
        }
    }
    
    return max_ind;
}

int main() {
    
    int t; 
    int n;
    
    cin >> t;
    
    while(t--){
        cin >> n;
        int a[n] = {0}, d[n] = {0};
        
        for(int i=0; i<n; i++)
            cin >> a[i];
            
        for(int i=0; i<n; i++)
            cin >> d[i];
        
        HS(a,d,n);
        
        cout << arrange(a,d,n) << "\n";
    }
	return 0;
}