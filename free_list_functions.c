#include<stdio.h>

#include "process_option.h"
#include "main_list_functions.h"

int pop_free_list () {
	if (free_index != -1) {
		int return_index = free_index;
		free_index = get_next_index(return_index);
		return return_index;
	}
	else
		return -1;
}

void push_free_list (int insert_index) {
	if (insert_index % 3 ==0) {
		set_next_index(insert_index, free_index);
		free_index = insert_index;
	}
	else
		printf("\nFAILUR: INVALID INDEX\n");
}
