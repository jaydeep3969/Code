#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back

/* Segment Tree for Minimum Range Query */

/*
    Complexity:
        Time to create and Store SegT : O(n)
        Time to search: O(log n)

    Size of seg T can be max 4*n
        If n is power of 2 => size = 2*n - 1
            e.g n=4 => size = 2*4 - 1
        O/W => next greater 2's power of n * 2 - 1
                e.g. n = 10 => size = 2*16 - 1
*/

vi v;

int rangeMinQuery(vi &segT, int l, int r, int low, int high, int pos) {
    if(l <= low && r >= high) // total overlap
        return segT[pos];
    
    if(l > high || r < low) // no overlap
        return INT_MAX;
    
    int mid = (low + high) / 2;

    return min(rangeMinQuery(segT, l, r, low, mid, 2*pos+1), rangeMinQuery(segT, l, r, mid+1, high, 2*pos+2));
}

void buildSegT(vi &segT, int low, int high, int pos) {
    if(low == high) {
        segT[pos] = v[low];
        return;
    }

    int mid = (low + high) / 2;

    buildSegT(segT, low, mid, 2*pos + 1);
    buildSegT(segT, mid + 1, high, 2*pos + 2);

    segT[pos] = min(segT[2*pos+1], segT[2*pos+2]);
}

vi createSegT(){
    int size = (int)(ceil(log2(v.size())));
    size = 2*(int)pow(2, size) - 1;

    vi segT(size, INT_MAX);

    buildSegT(segT, 0, v.size()-1, 0);

    return segT;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, n, in; cin >> t;

    while(t--) {
        cin >> n;
        v.clear();

        while(n--) {
            cin >> in;
            v.pb(in);
        }

        vi segT = createSegT();

        cout << "SegTree : \n";
        for(int i: segT)
            cout << i << " ";
        cout << "\n";

        // querying
        int l, r;
        cin >> n;

        while(n--) {
            cin >> l >> r;
            cout << rangeMinQuery(segT, l, r, 0, v.size()-1, 0) << "\n";
        }
    }

	return 0;
}

/*
--- Input ---
1
4
-1 2 4 0
4
1 3
0 1
2 3
1 1
--- Output ---
SegTree : 
-1 -1 0 -1 2 4 0 
0
-1
0
2
*/