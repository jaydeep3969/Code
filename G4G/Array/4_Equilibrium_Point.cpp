// https://practice.geeksforgeeks.org/problems/equilibrium-point/0/?track=md-arrays&batchId=144
// Suggestion :  Max sum increasing subsequence : https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/?ref=self
#include <iostream>
using namespace std;

typedef long long int lli;

lli find_equi_point(lli a[], lli sum[], lli n)
{
    for(lli i=1; i<n-1; i++)
	{
		if(sum[n-1]-sum[i-1]-a[i] == sum[i-1])
			return i+1;
	}
	
	return -1;
}

int main() {
	int t;
    lli n;
    
    cin >> t;
    
    while(t--)
    {  	
        cin >> n;
        
        if(n == 1)
        {
            lli tmp;
            cin >> tmp;
            cout << 1 << "\n";
            continue;
        }
        
        lli a[n] = {0};
		lli sum[n] = {0};
        
		cin >> a[0];
		sum[0] = a[0];
		
        for(lli i=1; i<n; i++)
        {
            cin >> a[i];
			
			sum[i] = a[i] + sum[i-1];
        }
    
        cout << find_equi_point(a, sum, n) << "\n";
    }
    
	return 0;
}
