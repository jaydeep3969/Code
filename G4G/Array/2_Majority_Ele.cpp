//https://practice.geeksforgeeks.org/problems/majority-element/0/?track=md-arrays&batchId=144
#include <iostream>
#include <map>
using namespace std;

typedef std::map<int, int> BasePairMap;

long long int find_majority(long long int n)
{
    int max = -1;
	long long int max_ele = -1, i;
	long long int size = n;
	BasePairMap m;
	
	while(n--)
    {
        cin >> i;
        
        if(m.find(i) != m.end())
            m[i]++;
        else
            m[i] = 1;
            
        if(max < m[i])
        {
            max = m[i];
            max_ele = i;
        }
    }
    
    if(max > size/2)
        return max_ele;
    return -1;
}

int main() {
	
	int t;
	long long int n;
	
	cin >> t;
	
	while(t--)
	{
	    cin >> n;
	    cout << find_majority(n) << "\n";
	}
	
	return 0;
}
