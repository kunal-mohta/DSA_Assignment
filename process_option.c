#include<stdio.h>
#include "execution_functions.h"
#include "free_list_functions.h"

#define MAIN_LIST_LEN 90
#define LIST_COUNT 5

int free_index = 0;
int main_list[MAIN_LIST_LEN];
int lists_index_no[LIST_COUNT]; // nth index => (n+1)th seq no
int total_list_count = 0;

void initialize_main_list () {
	int i;
	for (i = 0; i < MAIN_LIST_LEN - 3; i += 3) {
		main_list[i + 1] = i + 3;
	}
	main_list[i + 1] = -1;
}

void process_option (int option) {
	switch (option) {
		case 1: printf("\nThe sequence number of the newly created list is: %d", total_list_count+1);
			printf("\nEnter key value to be inserted in the newly created list-%d: ", total_list_count+1);
			int new_key;
			scanf("%d", &new_key);
			create_new_list(total_list_count, new_key);
			break;
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

	printf("\n\n%d\n\n", main_list[0]);
}
