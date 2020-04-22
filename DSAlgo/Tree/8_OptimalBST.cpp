#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vii;

/*
Given an array of integers with each number's search frequency
You have to make BST such that the cost of search becomes min
Find an element from the array which will be the root of such BST

Ex. Ele : [10, 12, 20] -> Freq : [34, 8, 50]
    Cost can be counted as 
        If 10 is root then,
            10 (34)
             \
              12 (8)
               \
                20 (50)
            Cost of search  = 34 + 8*2 + 50*3 = 200
        If 12 is root
            12(8)
            /\
      (34)10  20(50)
            Cost = 8 + 34*2 + 50*2 = 176
        If 20 is root
                20(50)
                /
            12(8)
              /
         10(34)
        Cost = 50 + 8*2 + 34*3 = 168

        Answer : 
                20
                /
               10
                \
                12  ==> 50 + 34*2 + 8*3 = 142


Cost(i,j)  = E(k=i to j) f.k + min(r=i to j) [Cost(i_to_r-1) + Cost(r+1_to_j)]

--> Making Tree of length L = 1_to_n(Total Ele.s)
For Each Tree,
--> E(k=i to j) f.k = Sum of frequency of Ele. i_to_j
--> min(r=i to j) [Cost(i_to_r-1) + Cost(r+1_to_j)] 
    = Making root to all ele one by one in range of i_to_j and Getting Mimimum Cost out of them
    => Adding Optimal/Minimum cost of Left SubTree and Right SubTree



Similar to matrix chain mul,

Complexity: 
    Time : O(n^3)
    Space: O(n^2)
*/

vi v;
vi f;


int _getRangeSum(int l, int r) {
    int sum = 0;
    for(int i=l; i <= r; i++)
        sum += f[i];
    return sum;
}

int _getOptimalBinSearchTree() {
    int root = -1;
    int n = v.size();

    // vi BST(n,-1);
    vii cost(n, vi (n, 0));

    // BST of Length L = 1 
    /*
        Storing value diagonally Bcoz In BST of one element, the element itself is root 
        => The cost of that tree is The freq of that element
    */
    for(int i=0; i<n; i++)
        cost[i][i] = f[i];
    
    //BST of Length L = 2 to n
    for(int L=2; L <= n; L++) {
        /*Genrating range of Length L in 0_to_n
          And filling [i,i+1]-Line Above Diag, [i, i+2]-2nd Line above Diag,.....*/
        for(int i=0; i < n-L+1; i++) {
            int j = i + L - 1; //Getting Col i+1, i+2, i+3, .....
            int freqSum = _getRangeSum(i,j);
            cost[i][j] = INT_MAX;

            /* Making each ele. bet.n i & j as root OneByOne */
            for(int r=i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r-1] : 0) + 
                           ((r < j) ? cost[r+1][j] : 0);

                if(cost[i][j] > c){
                    cost[i][j] = c;
                    root = r;
                    // BST[i] = v[root];
                }
            }

            // cout << v[root] << "\n";


            cost[i][j] += freqSum;
        }
    }

    for(vi it: cost)    {
        for(int i: it)
            cout << i << " ";
        cout << "\n";
    }

    cout << "Cost: " << cost[0][n-1] << "\n";

    // cout << "--BST--\n";
    // for(int i: BST)
    //     cout << i << " ";
    // cout << "\n--\n";
    return root;
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
        
        int e,freq;
        v.clear();
        f.clear();
        while(n--) {
            cin >> e >> freq;
            v.pb(e);
            f.pb(freq);
        }
        
        cout << v[_getOptimalBinSearchTree()] << "\n";
    }
	return 0;
}


/*
--- Input ---
2
3
10 34
12 8
20 50
4
10 4
12 2
16 6
21 3
--- Output ---
34 50 142 
0 8 66 
0 0 50 
Cost: 142
20
4 8 20 26 
0 2 10 16 
0 0 6 12 
0 0 0 3 
Cost: 26
16
*/