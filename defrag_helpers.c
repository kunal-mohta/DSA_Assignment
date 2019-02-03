#include<stdio.h>
#include "main_list_functions.h"
#include "process_option.h"

void index_arr_free_list (int *arr, int *total_elems) {
	int curr_index = free_index;
	int arr_index = 0;
	while (curr_index != -1) {
		arr[arr_index] = curr_index;
		int x = get_next_index(curr_index);
		curr_index = x;
		arr_index++;
	}
	*total_elems = arr_index;
}

void index_arr_list(int seq_no_index, int *arr, int *total_elems) {
	int curr_index = lists_index_no[seq_no_index];
    int arr_index = 0;
    while (curr_index != -1) {
        arr[arr_index] = curr_index;
        int x = get_next_index(curr_index);
        curr_index = x;
        arr_index++;
    }
    *total_elems = arr_index;
}

void merge (int arr[], int startIndex, int midIndex, int endIndex) {
	int lArrSize = midIndex - startIndex + 1;
	int rArrSize = endIndex - midIndex;

	int lArray[lArrSize];
	int rArray[rArrSize];
	int finalArray[lArrSize + rArrSize];

	int i;
	for (i = startIndex; i <= midIndex; i++) lArray[i - startIndex] = arr[i];
	for (i = midIndex + 1; i <= endIndex; i++) rArray[i - midIndex - 1] = arr[i];

	int lArrPointer = startIndex;
	int rArrPointer = midIndex + 1;

	int finalArrayIndex = 0;

	int lArrDone = 0;
	int rArrDone = 0;

	while (1) {
		if (lArrPointer == startIndex + lArrSize) {
			lArrDone = 1;
			break;
		}
		else if (rArrPointer == midIndex + rArrSize + 1) {
			rArrDone = 1;
			break;
		}

		if (arr[lArrPointer] >= arr[rArrPointer]) {
			finalArray[finalArrayIndex] = arr[lArrPointer];
			lArrPointer++;
		}
		else {
			finalArray[finalArrayIndex] = arr[rArrPointer];
			rArrPointer++;
		}
		finalArrayIndex++;
	}

	if (lArrDone) {
		while (rArrPointer < midIndex + rArrSize + 1) {
			finalArray[finalArrayIndex] = arr[rArrPointer];
			rArrPointer++;
			finalArrayIndex++;
		}
	}
	else if (rArrDone) {
		while (lArrPointer < startIndex + lArrSize) {
			finalArray[finalArrayIndex] = arr[lArrPointer];
			lArrPointer++;
			finalArrayIndex++;
		}
	}

	for (int j = startIndex; j <= endIndex; j++) arr[j] = finalArray[j - startIndex];
}

void mergeSort (int arr[], int startIndex, int endIndex) {
	if (startIndex < endIndex) {
		int midIndex = (startIndex + endIndex) / 2;
		mergeSort(arr, startIndex, midIndex);
		mergeSort(arr, midIndex + 1, endIndex);
		merge(arr, startIndex, midIndex, endIndex);
	}
}

// nodes should be of different list
// index1 = free list index; index2 = list index
void exchange_nodes (int index1, int index2, int *start_index1, int *start_index2) {
	int key1 = get_key(index1);
	int next_index1 = get_next_index(index1);
	int prev_index1 = get_prev_index(index1);

	int key2 = get_key(index2);
	int next_index2 = get_next_index(index2);
	int prev_index2 = get_prev_index(index2);

	set_key(index1, key2);
	set_key(index2, key1);

	set_next_index(index1, next_index2);
	set_next_index(index2, next_index1);
	set_prev_index(index1, prev_index2);
	set_prev_index(index2, prev_index1);

	if (prev_index1 == -1)
		*start_index1 = index2;
	else
		set_next_index(prev_index1, index2);

	if (prev_index2 == -1)
		*start_index2 = index1;
	else
		set_next_index(prev_index2, index1);

	if (next_index1 != -1)
		set_prev_index(next_index1, index2);

	if (next_index2 != -1)
		set_prev_index(next_index2, index1);
}
