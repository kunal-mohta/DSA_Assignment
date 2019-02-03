#include<stdio.h>
#include "process_option.h"
#include "main_list_functions.h"

int count_total_elems () {
	int total = 0;
	for (int i = 0; i < list_count; i++) {
		int start_index = lists_index_no[i];
		if (start_index != -2 && start_index != -1) {
			int curr_index = start_index;
			while (curr_index != -1) {
				int x = get_next_index(curr_index);
				curr_index = x;
				total++;
			}
		}
	}
	return total;
}
