#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vii;

/*
Given a set of distict coins with each coin in infinite numbers
Ex. 5 6 8 1 -- Each coin has infinite numbers of units
Given a target value - Make the sum of coins with min coins required

Complexity
    Time & Space : O(n*sum)
*/

vi v;
vii mat;

void _printCoins(int sum) {
    int j = sum;
    int i = v.size()-1;
    vi res;

    while(i > 0 && j > 0) {
        if(mat[i][j] != mat[i-1][j]) {
            res.pb(v[i]);
            sum -= v[i];
            j -= v[i];
        } else {
            i--;
        }
    }

    if(!i && j) {
        if(sum % v[i] == 0) {
            while(j > 0) {
                res.pb(v[i]);
                j -= v[i];
            }
        } else {
           res.clear(); res.pb(-1);
        }
    }

    cout << "--Coins--" << "\n";
    for(int c: res)
        cout << c << " ";
    cout << "\n";
}

void _changeMinCoins(int sum) {
    mat.clear();
    // vi zeros(sum+1, 0);
    // mat.pb(zeros);
    for(int i=0; i<v.size(); i++) {
        mat.pb({0});
        for(int j=1; j<=sum; j++) {
            if(j < v[i]) {
                if(!i)
                    mat[i].pb(0);
                else
                    mat[i].pb(mat[i-1][j]);
            }
            else {
                if(!i)
                    mat[i].pb(mat[i][j-v[i]]+1);
                else
                    mat[i].pb(min(mat[i-1][j], mat[i][j-v[i]]+1));
            }
                
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

    int t, n, sum; cin >>t;

    while(t--) {
        cin >> n >> sum;
        int i;
        int min = INT_MAX;
        v.clear();

        while(n--) {
            cin >> i; v.pb(i);
            min = (min > i) ? i : min;
        }

        if(sum < min)
            cout << "--Coins--\n" << -1 << "\n";
        else {
            sort(v.begin(), v.end());
            _changeMinCoins(sum);
            _printCoins(sum);
        }
    }

    return 0;
}

/*
--- Input ---
5
4 21
5 6 8 1
4 3
4 5 6 7
2 22
1 5
1 6
5
2 6
5 7
--- Output ---
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 
0 1 2 3 4 1 2 3 4 5 2 3 4 5 6 3 4 5 6 7 4 5 
0 1 2 3 4 1 1 2 3 4 2 2 2 3 4 3 3 3 3 4 4 4 
0 1 2 3 4 1 1 2 1 2 2 2 2 2 2 3 2 3 3 3 3 3 
--Coins--
8 8 5 
--Coins--
-1
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 
0 1 2 3 4 1 2 3 4 5 2 3 4 5 6 3 4 5 6 7 4 5 6 
--Coins--
5 5 5 5 1 1 
0 0 0 0 0 1 1 
--Coins--
-1 
0 0 0 0 0 1 1 
0 0 0 0 0 1 1 
--Coins--
-1 
*/