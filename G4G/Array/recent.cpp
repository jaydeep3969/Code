
#include<bits/stdc++.h>
using namespace std;



int trappingWater(int arr[], int n){
    int count = 0;
    int ind = 0;
    while(a[ind] == 0){
        ind++;
    }
    
    int max = arr[ind], start=0, min=0, min_ind = 0;
    
    
    for(int i=ind+1; i<n; i++){
        if(arr[i] > max){
            for(int j=start+1; j<i; j++){
                count += arr[start] - arr[j];
            }
            start = i;
            max = arr[i];
        }
        else if(arr[i] > min){
            min = arr[i];
            min_ind = i;
        }
    }
    
    
    if(arr[n-1] != arr[max]){
        int tmp;
        
        if(min_ind != 0){
            for(int j=start+1; j < min_ind; j++)
                count += arr[min_ind] - arr[j];
        }
        else
            min_ind = start;
            
        for(int j=min_ind+1; j<n-1; j++){
            tmp  = arr[j] - arr[n-1];
            if(tmp < 0)
                tmp *= -1;
                
            count += tmp;
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

10
0
10
33
4