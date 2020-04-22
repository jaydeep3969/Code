#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;

/*  Check whether given tree is BST
    Complexity: Time O(n)
*/
vi v;

bool checkBST(int i, int min, int max) {
    if(i >= v.size()) 
        return true;

    if(v[i] < min || v[i] > max)
        return false;

    return (checkBST(2*i + 1, min, v[i]) && checkBST(2*i + 2, v[i], max));
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

   int t, n, sum; cin >> t;

    while(t--){
        cin >> n;
        
        int i;
        v.clear();
        while(n--){
            cin >> i; v.pb(i);
        }

        cout << checkBST(0, INT_MIN, INT_MAX) << "\n";
    }   
	return 0;
}


/*
--- Input ---
2
6
10 -10 19 -20 0 17
7
10 0 25 -1 21 16 32
--- Output ---
1
0
*/