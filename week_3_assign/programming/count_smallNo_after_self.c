#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int val;
	int idx;
} Pair;

int* ans;

void merge (Pair arr[], int low, int mid, int high) {
	Pair temp[high - low + 1];

	int i=low, j=mid+1, k=0;

	int rightCount = 0;

	while(i <= low && j <= high) {
		if(arr[i].val > arr[j].val) {
			rightCount++;
			temp[k++] = arr[j++];
		}
		else {
			ans[arr[i].idx] += rightCount;
			temp[k++] = arr[i++];
		}
	}

	while(i <= mid) {
		ans[arr[i].idx] += rightCount;
	        temp[k++] = arr[i++];
	}

	while (j <= high) {
       		temp[k++] = arr[j++];
    	}

	for (int p = 0; p < k; p++) {
       		arr[low + p] = temp[p];
   	}
}

void mergeSort (Pair arr[], int low, int high) {
	if(low >= high) {
		return ;
	}

	int mid = low + (high-low)/2;

	mergeSort(arr, low, mid);
	mergeSort(arr, mid+1, high);

	merge(arr, low, mid, high);
}

void countSmallNoAfterSelf (Pair arr[], int numSize) {
	mergeSort(arr, 0, numSize-1);
}

int main() {
	int nums[] = {5, 2, 6, 1};

	int numSize = sizeof(nums)/sizeof(nums[0]);
	
	Pair arr[numSize];

	ans = (int*)calloc(numSize, sizeof(int));

	for (int i=0; i<numSize; i++) {
		arr[i].val = nums[i];
		arr[i].idx = i;
	}

	countSmallNoAfterSelf (arr, numSize);
	
	for(int i=0; i<numSize; i++) {
		printf("%d ",ans[i]);
	}
	printf("\n");
	
	free(ans);

	return 0;

}
