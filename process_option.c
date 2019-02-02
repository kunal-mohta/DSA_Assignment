#include<stdio.h>
#include "execution_functions.h"
#include "free_list_functions.h"

#define MAIN_LIST_LEN 90
#define LIST_COUNT 5

int free_index = 0;
int main_list[MAIN_LIST_LEN];
int lists_seq_no[LIST_COUNT];

void initialize_main_list () {
	int i;
	for (i = 0; i < MAIN_LIST_LEN - 3; i += 3) {
		main_list[i + 1] = i + 1 + 3;
	}
	main_list[i + 1] = -1;

	push_free_list(6);
	push_free_list(12);
	printf("\n\n%d\n\n", free_index);
	pop_free_list();
	printf("\n\n%d\n\n", free_index);
}

void process_option (int option) {
	switch (option) {
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: break;
		case 5: break;
		case 6: break;
		case 7: break;
		case 8: break;

		default: printf("\nFAILURE: INVALID OPTION\n");
			break;
	}
}
