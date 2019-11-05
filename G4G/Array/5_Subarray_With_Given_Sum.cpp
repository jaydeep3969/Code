//https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0/?track=md-arrays&batchId=144

#include <iostream>
#include <queue>
using namespace std;

typedef unsigned long long int ulli;

int main() {
    
    int t;
    ulli n, s, i, start, end, sum;
    queue <int> q;
    
    cin >> t;
    
    while(t--){
        cin >> n;
        cin >> s;
        
        sum = 0;
        start = 1;
        
        while(n--){
            cin >> i;
            
            if(sum == s)
                continue;
            
            sum += i;
            q.push(i);
            
            while(sum > s){
                sum -= q.front();
                q.pop();
                start++;
            }
        }
        
        if(sum != s)
            cout << -1 << "\n";
        else
            cout << start << " " << (q.size() + start - 1) << "\n";
        
        while(!q.empty()){
            q.pop();
        }
    }
    
	return 0;
}
