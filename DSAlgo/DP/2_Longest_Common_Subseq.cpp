#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<vector<int>> vvi;

string s1, s2;
vvi v;

void _solveDPLCS() {
    v.clear();
    int m, n;
    m = s1.length();
    n = s2.length();

    vector<int> v1(n+1, 0);
    v.pb(v1);

    for(int i=1; i<=m; i++) {
        v.pb({0});
        for(int j=1; j<=n; j++) {
            int tmp;
            if(s1[i-1] == s2[j-1])
                tmp = v[i-1][j-1] + 1;
            else
                tmp = max(v[i-1][j], v[i][j-1]);
            v[i].pb(tmp);
        }
    }

    cout << v[m][n] << endl;

    // for(auto it: v) {
    //     for(int i: it)
    //         cout << i << " ";
    //     cout << "\n";
    // }
}

void _printLCS() {

    stack<char> s;
    int j = s2.size(), i =s1.size(), len = v[i][j];

    while(len) {
        if(v[i][j] == v[i-1][j])
            i--;
        else if(v[i][j] == v[i][j-1])
            j--;
        else {
            s.push(s1[i-1]);
            i--;j--;len--;
        }
    }

    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << "\n";
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
        cin >> s1 >> s2;
        _solveDPLCS();
        _printLCS();
    }

    return 0;
}

/*
--- Input --- 
2
AGGTAB
GXTXAYB
abcdaf
acbcf

--- output ---
4
GTAB
4
abcf
*/