#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vii;

/*
Given 2 strings, make both strings Identical with minimum number of actions
Actions Allowed :
Add, Delete, Update

Complexity : 
    Time & Space: O(m*n); m=len(s1) n=len(s2)
*/

string s1, s2;
vi v;
vii mat;

void _printActions() {
    /* Left + 1 -> Deleted from S2 (j)
       Top + 1 -> Deleted from S1 (i)
       Diagonal + 1 -> Update 
       Diagonal = -> No Action */
    int i = s1.length();
    int j = s2.length();

    cout << "--- Actions ---\n";
    while(i > 0 && j > 0) {
        if(mat[i][j] == mat[i][j-1] + 1) {
            cout << "Deleted " << s2[j-1] << " from S2 @pos: " << j << "\n";
            j--;
        } else if(mat[i][j] == mat[i-1][j] + 1) {
            cout << "Deleted " << s1[i-1] << " from S1 @pos: " << i << "\n";
            i--;
        } else if(mat[i][j] == mat[i-1][j-1] + 1) {
            cout << "Updated " << s1[i-1] << " of S1 (@pos: " << i << ") with " << s2[j-1] << " of S2 (@pos: " << j << ")\n";
            i--; j--;
        } else {
            i--; j--;
        }
    }
}

void _countMinEditDist() {
    vi v;
    mat.clear();
    int m, n;
    m = s1.length()+1;
    n = s2.length()+1;

    for(int i=0; i<n; i++)
        v.pb(i);

    mat.pb(v);

    for(int i=1; i < m; i++) {
        mat.pb({i});
        for(int j=1; j < n; j++) {
            if(s1[i-1] == s2[j-1])
                mat[i].pb(mat[i-1][j-1]);
            else
                mat[i].pb(min(min(mat[i-1][j], mat[i][j-1]), mat[i-1][j-1])+1);
        }
    }

    for(vi it: mat) {
        for(int i: it)
            cout << i << " ";
        cout << "\n";
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >>t;

    while(t--) {
        cin >> s1 >> s2;
        cout  << s1  << " " << s2 << "\n";
        _countMinEditDist();
        _printActions();
    }

    return 0;
}

/*
--- Input ---
1
abcdef agced
--- output ---
abcdef agced
0 1 2 3 4 5 
1 0 1 2 3 4 
2 1 1 2 3 4 
3 2 2 1 2 3 
4 3 3 2 2 2 
5 4 4 3 2 3 
6 5 5 4 3 3 
--- Actions ---
Updated f of S1 (@pos: 6) with d of S2 (@pos: 5)
Deleted d from S1 @pos: 4
Updated b of S1 (@pos: 2) with g of S2 (@pos: 2)
*/