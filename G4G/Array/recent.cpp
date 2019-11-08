// https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1/?track=md-arrays&batchId=144

#include <iostream>
using namespace std;

int maxLen(int a[], int n){
    
    for(int i=0; i<n; i++)
        if(!a[i])
            a[i] = -1;
    
    int presum[n] = {0}, max_sum, min_sum;
    
    presum[0] = min_sum = max_sum = a[0];
    
    for(int i=1; i<n; i++){
        presum[i] += presum[i-1] + a[i];
        if(presum[i] > max_sum)
            max_sum = presum[i];
        else if(presum[i] < min_sum)
            min_sum = presum[i];
    }
    
    if(presum[n-1]==0)
        return n;
    
    cout << "Min Sum : " << min_sum << " Max Sum : " << max_sum << "\n";
    
    int max_sum_ind[max_sum - min_sum+1] = {0};
    int min_sum_ind[max_sum - min_sum+1] = {0};
    int max_len = -1;
    
    for(int i=0; i<max_sum-min_sum+1; i++)
        min_sum_ind[i] = n;
    
    cout << "Presum : ";
    
    for(int i=0; i<n; i++){
        cout << presum[i] << " ";
        if(max_sum_ind[presum[i] - min_sum] < i)
            max_sum_ind[presum[i] - min_sum] = i;
        
        if(min_sum_ind[presum[i] - min_sum] > i)
            min_sum_ind[presum[i] - min_sum] = i;
    }
    
    cout << "\n max_sum_ind\tmin_sum_ind\n";
    
    for(int i=0; i<max_sum-min_sum+1; i++){
        cout << max_sum_ind[i] << "\t" << min_sum_ind[i] << "\n";
        if(max_sum_ind[i] - min_sum_ind[i] > max_len){
            max_len = max_sum_ind[i] - min_sum_ind[i];
            if(-1*min_sum-i == 0){
                max_len += min_sum_ind[i] + 1;
            }
        }
            
    }
    
    return max_len;
    
}

int main() {
    int t,n;
    
    cin >> t;
    
    while(t--){
        cin >> n;
        int a[n] = {0};
        
        for(int i=0; i<n; i++)
            cin >> a[i];
        
        cout << maxLen(a,n) << "\n";
    }
	return 0;
}


51
1 1 0 0 0 0 0 1 1 1 1 0 0 0 1 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 1 1 1 1 0 0 0 0 0 0 0 1 1 0 0 1