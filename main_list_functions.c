#include<stdio.h>

#include "process_option.h"

int get_next_index (int curr_index) {
	if (curr_index % 3 == 0)
		return main_list[curr_index + 1];
	else {
		printf("\nFAILURE: INVALID CURRENT INDEX");
		return -2;
	}
}

void set_next_index (int curr_index, int next_index) {
	if (curr_index % 3 == 0)
		main_list[curr_index + 1] = next_index;
    else {
        printf("\nFAILURE: INVALID CURRENT INDEX");
    }
}

int get_prev_index (int curr_index) {
	if (curr_index % 3 == 0)
		return main_list[curr_index + 2];
    else {
        printf("\nFAILURE: INVALID CURRENT INDEX");
        return -2;
    }
}

void set_prev_index (int curr_index, int prev_index) {
	if (curr_index % 3 == 0)
		main_list[curr_index + 2] = prev_index;
    else {
        printf("\nFAILURE: INVALID CURRENT INDEX");
    }
}

int get_key (int index) {
	if (index % 3 == 0)
		return main_list[index];
    else {
        printf("\nFAILURE: INVALID CURRENT INDEX");
//        return -1;
    }
}

void set_key (int index, int key) {
	if (index % 3 == 0)
		main_list[index] = key;
    else {
        printf("\nFAILURE: INVALID CURRENT INDEX");
    }
}
