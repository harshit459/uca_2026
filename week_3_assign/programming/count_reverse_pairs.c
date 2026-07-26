#include <stdio.h>
#include <stdlib.h>

int merge (int* nums, int low, int mid, int high) {
	int * temp = (int*)malloc((high - low + 1) * sizeof(int));
	int i=low, j=mid+1, k=0;
	int count = 0;

	for (i=low; i<=mid; i++) {
		while (j <= high && nums[i] > 2LL * nums[j]) {
			 j++;
		}

		count += j - (mid+1);
	}		

	i = low;
        j = mid + 1;

	while (i <= mid && j <= high) {
		if(nums[i] <= nums[j]) {
			temp[k++] = nums[i++];
		}
		else {
			temp[k++] = nums[j++];
		}
	}

	while (i <= mid) {
		temp[k++] = nums[i++];
	}
	while (j <= high) {
		temp[k++] = nums[j++];
	}

	for (i=0; i<k; i++) {
		nums[low + i] = temp[i];
	}	

	free(temp);

	return count;
}

int mergeSort (int* nums, int low, int high) {
	if (low >= high ) {
		return 0;
	}
	
	int mid = low + ( high-low )/2;
	int count = 0;

	count += mergeSort(nums, low, mid);
	count += mergeSort(nums, mid+1, high);
	count += merge(nums, low, mid, high);

	return count;
}

int reversePairs(int* nums, int numSize) {
	
	return mergeSort(nums, 0, numSize-1);
}

int main() {
	int nums[] = {2, 4, 3, 5, 1};
	int numSize = sizeof(nums)/sizeof(nums[0]);

	int ans = reversePairs(nums, numSize);

	printf("Reverse Pairs = %d\n", ans);

        return 0;
}

