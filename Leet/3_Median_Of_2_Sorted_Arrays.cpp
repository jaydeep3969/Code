// https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/

class Solution {
public :
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int mid = (m+n)/2;

        if(!m || !n){
            vector <int> tmp;

            if(!m && n>0)
                tmp = nums2;
            else if (m>0 && !n)
                tmp = nums1;
            else
                return 0.0;

            if((m+n) % 2 == 0){
                return ((double)tmp[mid-1] + (double)tmp[mid])/2;
            }
            else 
                return (double)tmp[mid];   
        }
        
        merge(nums1, nums2);
        
        if((m+n) % 2 == 0)
            return (actual_value(nums1, nums2, mid-1) + actual_value(nums1, nums2, mid))/2;
        else
            return actual_value(nums1, nums2, mid);
    }
    
       
    double actual_value(vector<int>& nums1, vector<int>& nums2, int i){
        int m = nums1.size();
        
        if(i >= m)
            return (double)nums2[i-m];
        else 
            return (double)nums1[i];
    }

    void merge(vector<int>& nums1, vector<int>& nums2){
        int m = nums1.size();
        int n = nums2.size();

        for(int i=n-1; i >= 0; i--){
            int j, last = nums1[m-1];
            for(j = m-2; j >= 0 && nums1[j] > nums2[i]; j--){
                nums1[j+1] = nums1[j];
            }

            if(j != m-2 || last > nums2[i]){
                nums1[j+1] = nums2[i];
                nums2[i] = last;
            }
        }
    }
};