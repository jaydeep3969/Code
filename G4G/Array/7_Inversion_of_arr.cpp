// https://practice.geeksforgeeks.org/problems/inversion-of-array/0/?track=md-arrays&batchId=144
// Kadane's Algorithm : https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0/?ref=self

#include <iostream>
using namespace std;

typedef unsigned long long int ulli;

void merge(ulli a[], ulli l, ulli mid, ulli r, ulli* count){
    ulli size_l = mid - l + 1;
    ulli size_r = r- mid;
    ulli arr_l[size_l], arr_r[size_r];
    
    for(ulli i=0; i<size_l; i++)
        arr_l[i] = a[l+i];
        
    for(ulli i=0; i<size_r; i++)
        arr_r[i] = a[mid+1+i];
        
    ulli i = 0, j = 0, k = l;
    
    while(i < size_l && j < size_r){
        if(arr_l[i] <= arr_r[j]){
            a[k] = arr_l[i];
            i++;
        }
        else{
            *count += size_l - i;
            a[k] = arr_r[j];
            j++;
        }
        
        k++;
    }
    
    while(i < size_l){
        a[k] = arr_l[i];
        i++; k++;
    }
    
    while(j < size_r){
        a[k] = arr_r[j];
        j++; k++;
    }
}


void ms(ulli a[], ulli l, ulli r, ulli *count){
    if(l<r) {
        ulli mid = (l + r) / 2;
        
        ms(a, l, mid, count);
        ms(a, mid+1, r, count);
        merge(a, l, mid, r, count);
    }
}

int main() {
    int t;
    ulli n;
    
    cin >> t;
    
    while(t--){
        cin >> n;
        ulli a[n] = {0};
        
        for(ulli i=0; i<n; i++)
            cin >> a[i];
        
        ulli count =0;
        ms(a, 0, n, &count);
        
        cout << count << "\n";
    }   
	return 0;
}
