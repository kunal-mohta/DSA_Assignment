#include<stdio.h>
#include "process_option.h"
#include "main_list_functions.h"
#include "free_list_functions.h"

// TODO: seq_no validity
void delete_elem_in_list (int seq_no, int key) {
	int seq_no_index = seq_no - 1;
	int list_start_index = lists_index_no[seq_no_index];

	int curr_index = list_start_index;

	while (curr_index != -1 && key != get_key(curr_index)) {
		int x = get_next_index(curr_index);
		curr_index = x;
	}

	// key not found
	if (curr_index == -1) {
		printf("\nFAILURE: ELEMENT NOT THERE / LIST EMPTY\n");
	}
	// key found
	else {
		//1 element list
		if (get_prev_index(curr_index) == -1 && get_next_index(curr_index) == -1) {
			lists_index_no[seq_no_index] = get_next_index(curr_index);
		}
		// delete from beginning
		else if (get_prev_index(curr_index) == -1) {
			set_prev_index(get_next_index(curr_index), get_prev_index(curr_index));
			lists_index_no[seq_no_index] = get_next_index(curr_index);
		}
		// delete from end
		else if (get_next_index(curr_index) == -1) {
			set_next_index(get_prev_index(curr_index), get_next_index(curr_index));
		}
		// delete from between
		else {
			set_prev_index(get_next_index(curr_index), get_prev_index(curr_index));
			set_next_index(get_prev_index(curr_index), get_next_index(curr_index));
		}
		push_free_list(curr_index);
		printf("\nSUCCESS\n");
	}
}
