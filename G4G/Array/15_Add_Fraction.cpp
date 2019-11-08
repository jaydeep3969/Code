// https://practice.geeksforgeeks.org/problems/add-two-fractions/1/?ref=self

#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b > a)
        swap(a,b);
    
    if(!b)
        return a;
    else
        gcd(b, a%b);
}

int lcm(int a, int b){
    if(a==b)
        return a;
    return a*b/gcd(a,b);
}

void addFraction(int n1, int d1, int n2, int d2){
    int dX = lcm(d1,d2);
    int nX;
    
    nX = n1 * (dX/d1) + n2 * (dX/d2);
    
    int common = gcd(nX,dX);
    
    if(common != 1){
        nX /= common;
        dX /= common;
    }
    
    cout << nX << "/" << dX << "\n";
}

int main() {
    int t;
    int n1, d1, n2, d2;
    
    cin >> t;
    
    while(t--){
      cin  >> n1 >> d1 >> n2 >> d2;
      addFraction(n1,d1,n2,d2);
    }	
    
	return 0;
}