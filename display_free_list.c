#include<stdio.h>
#include "process_option.h"
#include "main_list_functions.h"

void display_free_list () {
	int curr_index = free_index;
	printf("\n[");
	while (1) {
		printf("%d", curr_index);
		int next_index = get_next_index(curr_index);
		if (next_index == -1) break;
		else printf(",");
		curr_index = next_index;
	}
	printf("]");
}
