#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;
/*
    Matrix Chain Multiplication
    - It decides in which order matrices should be multiplied, 
      So that the cost of multiplication would be minimum.

    E.x. 3 matrices : [1,2] [2,3] [3,4]  -- [row, column]
            - the cost of multiplication depends on order of choosing two matrices for Mul
            e.g. : If we do mul in order : (1,2)3
                    Cost = 1*2*3 + 1*3*4 = 18
                 : If we do mul in order : (1)(2,3)
                    Cost  = 2*3*4 + 1*2*4 = 32

    Below Solution : 
        Time : O(n^3)
        Space : O(n^2)
        -- Accepts abover order in Input as : [1,2,3,4] --> n = 4
*/

vi v;

void _getMinCostDP() {
    int len = v.size();

    vvi mat(len, vi (len,0));

    for(int end=2; end<len; end++) {
        for(int i=0; i<len-end; i++) {
            int j = i + end;
            mat[i][j] = INT_MAX;
            for(int k=i+1; k<j; k++)
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j] + v[i]*v[k]*v[j]);
        }
    }

    for(auto it: mat) {
        for(int i: it)
            cout << i << " ";
        cout << "\n";
    }

    cout << "Cost : " << mat[0][len-1] << "\n";
}

void _printOrder() {
    return;
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

        int tmp;
        v.clear();

        while(n--) {
            cin >> tmp;
            v.pb(tmp);
        }

        _getMinCostDP();
        _printOrder();
    }

    return 0;
}

/*
--- Input ---
2
4
1 2 3 4
5
2 3 6 4 5
--- Output ---
0 0 6 18 
0 0 0 24 
0 0 0 0 
0 0 0 0 
Cost : 18
0 0 36 84 124 
0 0 0 72 132 
0 0 0 0 120 
0 0 0 0 0 
0 0 0 0 0 
Cost : 124
*/