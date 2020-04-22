#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

/*
Given an array find longest increasing subseq (Not Subarray)
Ex. 3 4 -1 0 6 2 3 => (-1 0 2 3):4

Complexity: 
    Time : O(n^2)
    Space: O(n)
*/

vi v;

void _findLongestIncrSubseq() {
    vi mat(v.size(), 1);
    int res = 0;
    for(int i=1; i < v.size(); i++) {
        for(int j=0; j < i; j++) {
            if(v[i] > v[j]) {
                mat[i] = max(mat[i], mat[j]+1);
                res = max(res, mat[i]);
            }
        }
    }
    
    for(int i: mat)
        cout << i <<" ";
    cout << "\n";
    
    cout << res << "\n";
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t,n; cin >> t;
    
    while(t--) {
        cin >> n;
        
        int in;
        v.clear();
        while(n--) {
            cin>>in; v.push_back(in);
        }
        
        _findLongestIncrSubseq();
    }
	return 0;
}


/*
--- Input ---
3
7
3 4 -1 0 6 2 3
1
5
0
--- Output ---
1 2 1 2 3 3 4 
4
1
-1
*/