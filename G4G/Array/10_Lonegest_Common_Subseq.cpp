#include <iostream>
#include <cstring>
using namespace std;

int max(int a, int b, int c)
{
    if(a > b && a > c)
        return a;
    else if (b>a && b>c)
        return b;
    else
        return c;
}

int main() {
    int t;
    int n, i, j;
    
    cin >> t;
    
    while(t--){
        cin >> i;
        cin >> j;
        
        char s1[i], s2[j];
        int a[i+1][j+1];
        
        memset(a, 0, sizeof(a));
        
        cin >> s1;
        cin >> s2;
        
        for(int k = 1; k<i+1; k++)
        {
            for(int l = 1; l < j+1; l++){
                a[k][l] = max(a[k-1][l-1], a[k][l-1], a[k-1][l]);
                
                if(s1[k-1] == s2[l-1])
                    a[k][l]++;
            }
        }
        
        cout << a[i][j] << "\n";
    }   
	return 0;
}
