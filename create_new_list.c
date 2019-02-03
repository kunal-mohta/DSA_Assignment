#include<stdio.h>
#include "free_list_functions.h"
#include "main_list_functions.h"
#include "process_option.h"

void create_new_list (int seq_no_index, int key) {
	int new_list_start_index = pop_free_list();
	if (new_list_start_index != -1) {
		lists_index_no[seq_no_index] = new_list_start_index;
		set_prev_index(new_list_start_index, -1);
		set_next_index(new_list_start_index, -1);
		set_key(new_list_start_index, key);
		total_list_count++;
		printf("\nSUCCESS\n");
	}
	else {
		printf("\nFAILURE: MEMORY NOT AVAILABLE\n");
	}
}
