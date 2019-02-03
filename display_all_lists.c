#include<stdio.h>
#include "process_option.h"
#include "main_list_functions.h"

void display_all_lists () {
	for (int i = 0; i < list_count; i++) {
		int start_index = lists_index_no[i];
		if (start_index != -2) {
			printf("\n\nElements of list-%d are:\n", i+1);
			printf("key\tnext\tprev\n");
			int curr_index = start_index;
			while (curr_index != -1) {
				int key = get_key(curr_index);
				printf("%d\t", key);

				int next_index = get_next_index(curr_index);
				if (next_index == -1) printf("NIL\t");
				else printf("%d\t", next_index);

				int prev_index = get_prev_index(curr_index);
				if (prev_index == -1) printf("NIL\n");
				else printf("%d\n", prev_index);

				curr_index = next_index;
			}
		}
	}
}
