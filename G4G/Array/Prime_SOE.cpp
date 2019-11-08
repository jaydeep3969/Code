// Sieve of Eratosthenes

#include <iostream>
using namespace std;

int main() {
    int t,n;
    
    cin >> t;
    
    while(t--){
       cin >> n;
       
       int prime[n+1] = {0};
       
       for(int i=2; i*i<=n; i++){
           if(!prime[i]){
               for(int j=i*i; j <= n; j+=i)
                prime[j] = 1;
           }
       }
       
       for(int i=2; i <= n; i++)
            if(!prime[i])
                cout << i << " ";
        cout << "\n";
    }	
    
	return 0;
}