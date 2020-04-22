#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define wt first
#define val second

typedef vector<pair<int, int>> vpii;

vpii v;
int max_wt;
vector<vector<int>> mat;

int _solveKnapsack() {
    mat.clear();

    for(int i=0; i<v.size(); i++) {
        mat.pb({0});
        for(int j=1; j<max_wt+1; j++) {
            int tmp;
            if(j < v[i].wt) {
                tmp = !i ? 0 : mat[i-1][j]; // Item's wt is more than the available size
            } else {
                tmp = !i ? v[i].val : max(v[i].val+mat[i-1][j-v[i].wt], mat[i-1][j]); // Max(val_when_item_is_taken, item_isn't_taken)
            }
            mat[i].pb(tmp);
        }
    }

    return mat[v.size()-1][max_wt];
}

void _printItems() {
    int j = max_wt;

    for(int i = v.size()-2; i >=0 && j >= 0; i--) {
        if(mat[i][j] != mat[i+1][j]) {
            cout << "Wt : " << v[i+1].wt  << " Val : " << v[i+1].val << "\n";
            j -= v[i+1].wt;
        }
    }
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
        cin >> n >> max_wt;

        int w, vl;
        
        v.clear();

        while(n--) {
            cin >> w >> vl;
            v.pb(mp(w, vl));
        }


        cout << _solveKnapsack() << "\n";
        _printItems();
    }

    return 0;
}