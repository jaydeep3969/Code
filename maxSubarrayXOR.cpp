//http://codeforces.com/problemset/problem/281/D
//https://www.geeksforgeeks.org/find-the-maximum-subarray-xor-in-a-given-array/  //reference
//tree

#include <iostream>
#define INT_SIZE 32;
using namespace std;


struct Trienode{
    int value;
    Trienode *arr[2];
};

Trienode *newNode()
{
    Trienode *tmp = new Trienode();
    tmp->value=0;
    tmp -> arr[0] = tmp -> arr[1] = NULL;
    return tmp;
}

void insert(Trienode *root, int pre_xor){
    Trienode *tmp = root;
    
    for(int i = 31; i>=0; i--){
        
        bool val = pre_xor & (1 << i);
        
        if(tmp -> arr[val] == NULL)
            tmp -> arr[val] = newNode();
            
        tmp = tmp -> arr[val];
    }
    
    tmp -> value = pre_xor;
}

int query(Trienode *root, int pre_xor){
    Trienode *tmp = root;
    
    for(int i=31; i>=0; i--){
        bool val = pre_xor & (1 << i);
        
        if(tmp -> arr[1-val] !=  NULL)
            tmp = tmp -> arr[1-val];
        else if(tmp -> arr[val] !=  NULL)
            tmp = tmp -> arr[val];
        
    }
    
    return pre_xor ^ (tmp -> value);
}

void disp(Trienode *root){
    cout << root -> value << ' ';
    
    if(root -> arr[0] != NULL)
        disp(root -> arr[0]);
    else if(root -> arr[1] != NULL)
        disp(root -> arr[1]);
}

int maxSubarrayXor(int arr[], int n){
    Trienode *root = newNode();
    insert(root, 0);
    
    int pre_xor = 0, result = -1;
    
    for(int i=0; i<n; i++){
        pre_xor = pre_xor ^arr[i];
        insert(root, pre_xor);
        
        cout << "Displaying" << endl;
        disp(root);
        cout << endl;
        
        result = max(result, query(root, pre_xor)); 
        
        cout << "Result :" +  result<< endl;
    }
    return result;
}

int main() {
    
    // long long int n;
    // while(n--){
            
    // }
    
//     bool val = (12 & (1 << 4));
//     std::cout <<  val << std::endl;
    
// 	return 0;

    int arr[] = {8, 1, 2, 12}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Max subarray XOR is " << maxSubarrayXor(arr, n); 
    return 0; 
}
