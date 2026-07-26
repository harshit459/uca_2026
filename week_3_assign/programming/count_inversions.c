#include <stdio.h>
#include <stdlib.h>

int merge (int* nums, int low, int mid, int high) {
	int * temp = (int*)malloc((high - low + 1) * sizeof(int));
	int i=low, j=mid+1, k=0;
	int count = 0;

	while (i <= mid && j <= high) {
		if(nums[i] <= nums[j]) {
			temp[k++] = nums[i++];
		}
		else {
			count += mid - i +1;
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

int countInversions(int* nums, int numSize) {
	
	return mergeSort(nums, 0, numSize-1);
}

int main() {
	int nums[] = {1, 2, 4, 1, 3 ,5};
	int numSize = sizeof(nums)/sizeof(nums[0]);

	int ans = countInversions(nums, numSize);

	printf("No. of inversion counts = %d\n", ans);

        return 0;
}

