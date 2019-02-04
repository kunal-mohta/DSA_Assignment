#include<stdio.h>
#include "process_option.h"
#include "main_list_functions.h"
#include "free_list_functions.h"

void delete_elem_in_list (int seq_no, int key) {
	int seq_no_index = seq_no - 1;
	int list_start_index = lists_index_no[seq_no_index];

	int curr_index = list_start_index;
	int deleted_count = 0;

	if (list_start_index != -1) {
		while (curr_index != -1) {
			int x = get_next_index(curr_index);
			if (key == get_key(curr_index)) {
				deleted_count++;
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
			}
			curr_index = x;
		}

		// key not found
		if (deleted_count == 0) {
			printf("\nFAILURE: ELEMENT NOT THERE\n");
		}
		// key found
		else {
			printf("\nSUCCESS\n");
		}
	}
	else {
		printf("\nFAILURE: LIST EMPTY\n");
	}
}
