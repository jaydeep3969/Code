//https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0/?track=md-arrays&batchId=144
// Suggestion : Leaders in Array

#include <iostream>
#include <stack>
using namespace std;

typedef long long int lli;

void find_leaders(lli a[], lli n)
{
    stack<int> s;
    
    for(lli i = n-1; i >= 0; i--)
    {
        if(s.empty() || s.top() <= a[i])
        {
            s.push(a[i]);
        }
    }
    
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    
    cout << "\n";
}

int main() {
    
    int t;
    lli n;
    
    cin >> t;
    
    while(t--)
    {
        cin >> n;
        
        lli a[n] = {0};
        
        for(lli i=0; i<n; i++)
        {
            cin >> a[i];
        }
    
        find_leaders(a,n);
    }
	return 0;
}
