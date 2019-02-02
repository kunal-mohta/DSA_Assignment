#include<stdio.h>
#include "execution_functions.h"
#include "free_list_functions.h"

#define MAIN_LIST_LEN 90
#define LIST_COUNT 5

int free_index = 0;
int main_list[MAIN_LIST_LEN];
int lists_index_no[LIST_COUNT] = {-1, -1, -1, -1, -1}; // nth index => (n+1)th seq no
int total_list_count = 0;

void initialize_main_list () {
	int i;
	main_list[2] = -1; // head
	for (i = 0; i < MAIN_LIST_LEN - 3; i += 3) {
		main_list[i + 1] = i + 3;
	}
	main_list[i + 1] = -1; // tail
}

void process_option (int option) {
	switch (option) {
		case 1: printf("\nThe sequence number of the newly created list is: %d", total_list_count+1);
				printf("\nEnter key value to be inserted in the newly created list-%d: ", total_list_count+1);
				int new_key;
				scanf("%d", &new_key);
				create_new_list(total_list_count, new_key);
				break;

		case 2: printf("\nList you want to insert in: ");
				int seq_no_insert;
				scanf("%d", &seq_no_insert);
				printf("\nEnter the key value: ");
				int key_insert;
				scanf("%d", &key_insert);
				insert_elem_in_list(seq_no_insert, key_insert);
				break;

		case 3: printf("\nList you want to delete from: ");
				int seq_no_delete;
				scanf("%d", &seq_no_delete);
				printf("\nEnter the key value: ");
				int key_delete;
				scanf("%d", &key_delete);
				delete_elem_in_list(seq_no_delete, key_delete);
				break;

		case 4: printf("\nTotal number of nodes in all lists are %d", count_total_elems());
				break;

		case 5: printf("\nEnter the list number: ");
				int seq_no_count;
				scanf("%d", &seq_no_count);
				printf("\nTotal number of nodes in list-%d are %d", seq_no_count, count_list_elems(seq_no_count));
				break;
		case 6: break;
		case 7: break;
		case 8: break;

		default: printf("\nFAILURE: INVALID OPTION\n");
			break;
	}

	/*int i = free_index;
//	int i = lists_index_no[0];
	int j = i;
	while (j != -1) {
		printf("\n\n%d", j);
		j = main_list[i+1];
		i = j;
	}*/
}
