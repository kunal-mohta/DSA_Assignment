#include<stdio.h>
#include "process_option.h"
#include "defrag_helpers.h"

void defrag () {
	int free_index_arr[main_list_len], free_index_arr_len;
	index_arr_free_list(free_index_arr, &free_index_arr_len);

	for (int k = 0; k < list_count; k++) {
		if (lists_index_no[k] != -2 && lists_index_no[k] != -1) {
			int list_index_arr[main_list_len], list_index_arr_len;
			index_arr_list(k, list_index_arr, &list_index_arr_len);

			mergeSort(free_index_arr, 0, free_index_arr_len-1);

			int combined_arr_len = free_index_arr_len + list_index_arr_len;
			int combined_arr[combined_arr_len];

			int c = 0;
			for (int i = 0; i < free_index_arr_len; i++, c++)
				combined_arr[c] = free_index_arr[i];

			for (int j = 0; j < list_index_arr_len; j++, c++)
				combined_arr[c] = list_index_arr[j];

			mergeSort(combined_arr, 0, combined_arr_len-1);

			for (int m = 0; m < free_index_arr_len; m++) {
				if (free_index_arr[m] != combined_arr[m]) {
					int fl_index = free_index_arr[m];
					int cl_index = combined_arr[m];
					exchange_nodes(fl_index, cl_index, &free_index, &lists_index_no[k]);
					free_index_arr[m] = combined_arr[m]; // update for the next list
				}
			}
		}
	}

	printf("\nSUCCESS");
}
