// https://practice.geeksforgeeks.org/problems/pairs-of-prime-number/0/?ref=self
// Pair Cube Count :  https://practice.geeksforgeeks.org/problems/pair-cube-count/0/?ref=self

#include <iostream>
using namespace std;

void soe(int prime[], int n){
    for(int i=2; i*i<=n; i++){
       if(!prime[i]){
           for(int j=i*i; j <= n; j+=i)
                prime[j] = 1;
        }
    }
}

int main() {
    int t;
    int n;
    
    cin >> t;
    
    while(t--){
        cin >> n;
        
        int size = n/2+1;
        int a[size] = {0}; //array of prime numbers
        
        soe(a,size); //Sieve of Eratosthenes 0-Prime 1-NotPrime
        
        for(int i=2; i < size; i++){
            if(!a[i]){
                for(int j=2; j < size; j++)    
                    if(!a[j] && i*j <= n)
                        cout << i << " " << j << " ";
            }
        }
        
        cout << "\n";
    }	
    
	return 0;
}