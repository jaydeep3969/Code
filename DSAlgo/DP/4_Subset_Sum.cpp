#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vii;

/*
Find a subset of a set having sum as a target SUM
Subset ~ Subsequence != Contiguous Subseq

2 3 7 8 10 Target-9 => Subset -- (2,7)

Complexity
    Time - O(n*sum)
    Space - O(n*sum)

Finding a continuous_subseq ~ Subarray can be done in O(n)
Keeping trace of prefix sum and these sums in a map
*/

vi v;
vii mat;

void _printSubset(int sum) {
    int j = sum;
    int i;
    for(i=v.size()-2; i >=0 && j > 0; i--) {
        if(mat[i][j] != mat[i+1][j]) {
            cout << v[i+1] << " ";
            j -= v[i+1];
        }
    }

    if (i == -1 && j)
        cout << v[0] << " ";

    cout << "\n";
}

void _findSubsetSum(int sum) {
    vi res;
    mat.clear();
    for(int i=0; i<v.size(); i++) {
        mat.pb({1});
        for(int j=1; j<=sum; j++) {
            if(!i) {
                if(v[i] == j)
                    mat[i].pb(1);
                else
                    mat[i].pb(0);
            } else if(j < v[i]) {
                mat[i].pb(mat[i-1][j]);
            } else if (mat[i-1][j]) {
                mat[i].pb(1);
            } else {
                mat[i].pb(mat[i-1][j-v[i]]);
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
        v.clear();
        while(n--) {
            cin >> i; v.pb(i);
        }

        _findSubsetSum(sum);
        _printSubset(sum);
    }

    return 0;
}

/*
--- Input ---
1
5 9
2 3 7 8 10

--- Output ---
1 0 1 0 0 0 0 0 0 0 
1 0 1 1 0 1 0 0 0 0 
1 0 1 1 0 1 0 1 0 1 
1 0 1 1 0 1 0 1 1 1 
1 0 1 1 0 1 0 1 1 1 
7 2 
*/