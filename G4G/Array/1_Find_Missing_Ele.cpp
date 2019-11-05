//https://practice.geeksforgeeks.org/problems/missing-number-in-array/0/?track=md-arrays&batchId=144

#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

long long int find_missing(long long int a[], long long int l, long long int r)
{
    int mid =  l + ((r-l)/2);
        
    if (mid - l == 0)
    {
        if(a[l] == l+1)
            return l+2;
        return mid+1;
    }
        
        
    if(a[mid] == mid+1)
        find_missing(a, mid+1, r);
    else
        find_missing(a, l, mid);
    
}

int main() {
	int t;
	long long int n;
	
	cin >> t;
	
	while(t--)
	{
	    cin >> n;
	    n--;
	    long long int a[n] = {0};
    
        for(int i=0; i<n; i++)
            cin >> a[i];
            
        sort(a, a+n);
	    cout << find_missing(a,0,n) << "\n";
	}
	return 0;
}