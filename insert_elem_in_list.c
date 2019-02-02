#include<stdio.h>
#include "process_option.h"
#include "main_list_functions.h"
#include "free_list_functions.h"

void insert_elem_in_list (int seq_no, int key) {
	// TODO: validity check for seq_no
	int next_free_index = pop_free_list();
	if (next_free_index != -1) {
		set_key(next_free_index, key);

		int seq_no_index = seq_no - 1;
		int list_start_index = lists_index_no[seq_no_index];

		int curr_index = list_start_index;
		int next_index = get_next_index(curr_index);
		int prev_index = get_prev_index(curr_index);

		while (key <= get_key(curr_index)) {
			prev_index = curr_index;
			curr_index = next_index;
			if (curr_index == -1) break;
			else next_index = get_next_index(curr_index);
		}

		// insert in the beginning
		if (prev_index == -1) {
			set_prev_index(next_free_index, -1);
			set_next_index(next_free_index, curr_index);
			set_prev_index(curr_index, next_free_index);
			lists_index_no[seq_no_index] = next_free_index;
		}
		// insert in the end
		else if (curr_index == -1) {
			set_next_index(next_free_index, -1);
			set_prev_index(next_free_index, prev_index);
			set_next_index(prev_index, next_free_index);
		}
		// insert in between
		else {
			set_next_index(next_free_index, curr_index);
			set_prev_index(next_free_index, prev_index);
			set_next_index(prev_index, next_free_index);
			set_prev_index(curr_index, next_free_index);
		}

		printf("\nSUCCESS\n");
	}
}
