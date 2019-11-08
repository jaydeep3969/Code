// https://practice.geeksforgeeks.org/problems/trapping-rain-water/1/?track=md-arrays&batchId=144
// Stock Buy and Sell : https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/1/?ref=self NOT OPENING

#include<bits/stdc++.h>
using namespace std;



int trappingWater(int arr[], int n){
    int count = 0;
    int ind = 0;
    while(arr[ind] == 0){
        ind++;
    }
    
    int max = arr[ind], last_ind=ind;
    
    
    for(int i=ind+1; i<n; i++){
        if(arr[i] > max){
            for(int j=last_ind+1; j<i; j++){
                count += arr[last_ind] - arr[j];
            }
            last_ind = i;
            max = arr[i];
        }
    }
    
    
    // END
    // cout << "last_ind : " << last_ind << "\n";
    n--;
    if(n != last_ind){
        
        while(arr[n] == 0)
            n--;
        
        int end = n;            
        for(int i=n-1; i >= last_ind; i--){
            if(arr[i] > arr[end]){
                for(int j=i+1; j<end; j++)
                    count += arr[end]-arr[j];
                end = i;
            }
        }
    }
    
    return count;
}

//Position this line where user code will be pasted.
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        
        cin >> n;
        
        int a[n];
        
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}

/*
5
4
7 4 0 9
3
6 9 9
6
3 0 0 2 0 4
16
3 0 0 2 0 4 0 3 2 0 0 5 0 1 0 3
7
8 8 2 4 5 5 1
19
3 0 4 0 1 8 2 4 0 2 0 8 0 0 4 3 2 0 1

10
0
10
33
4
51
*/