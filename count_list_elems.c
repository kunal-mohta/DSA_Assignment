#include<stdio.h>
#include "process_option.h"
#include "main_list_functions.h"

int count_list_elems (int seq_no) {
	int seq_no_index = seq_no - 1;
	int curr_index = lists_index_no[seq_no_index];
	int total = 0;

	while (curr_index != -1) {
		int x = get_next_index(curr_index);
		curr_index = x;
		total++;
	}
	return total;
}

