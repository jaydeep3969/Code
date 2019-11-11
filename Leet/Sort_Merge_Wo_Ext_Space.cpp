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