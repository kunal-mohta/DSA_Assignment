#include<stdio.h>
#include "execution_functions.h"
#include "free_list_functions.h"

#define MAIN_LIST_LEN 90
#define LIST_COUNT 5

// for external files
int main_list_len = MAIN_LIST_LEN;
int list_count = LIST_COUNT;

int free_index = 0;
int main_list[MAIN_LIST_LEN];
int lists_index_no[LIST_COUNT]; // nth index => (n+1)th seq no
int total_list_count = 0;

void initialize_main_list () {
	int i;
	main_list[2] = -1; // head
	for (i = 0; i < MAIN_LIST_LEN - 3; i += 3) {
		main_list[i + 1] = i + 3;
	}
	main_list[i + 1] = -1; // tail

	for (int j = 0; j < LIST_COUNT; j++)
		lists_index_no[j] = -2;
}

void process_option (int option) {
	switch (option) {
		case 1: if (total_list_count < LIST_COUNT) {
					printf("\nThe sequence number of the newly created list is: %d", total_list_count+1);
					printf("\nEnter key value to be inserted in the newly created list-%d: ", total_list_count+1);
					int new_key;
					scanf("%d", &new_key);
					create_new_list(total_list_count, new_key);
				}
				else
					printf("\nFAILURE: MAX LIST COUNT REACHED");
				break;

		case 2: printf("\nList you want to insert in: ");
				int seq_no_insert;
				scanf("%d", &seq_no_insert);
				if (seq_no_insert <= LIST_COUNT && lists_index_no[seq_no_insert - 1] != -2) {
					printf("\nEnter the key value: ");
					int key_insert;
					scanf("%d", &key_insert);

					if (lists_index_no[seq_no_insert-1] == -1)
						create_new_list(seq_no_insert-1, key_insert);
					else
						insert_elem_in_list(seq_no_insert, key_insert);
				}
				else
					printf("\nFAILURE: LIST NOT FOUND");
				break;

		case 3: printf("\nList you want to delete from: ");
				int seq_no_delete;
				scanf("%d", &seq_no_delete);
				if (seq_no_delete <= LIST_COUNT && lists_index_no[seq_no_delete - 1] != -2) {
					printf("\nEnter the key value: ");
					int key_delete;
					scanf("%d", &key_delete);
					delete_elem_in_list(seq_no_delete, key_delete);
				}
				else
					printf("\nFAILURE: LIST NOT FOUND");
				break;

		case 4: printf("\nTotal number of nodes in all lists are %d", count_total_elems());
				break;

		case 5: printf("\nEnter the list number: ");
				int seq_no_count;
				scanf("%d", &seq_no_count);
				if (seq_no_count <= LIST_COUNT && lists_index_no[seq_no_count - 1] != -2)
					printf("\nTotal number of nodes in list-%d are %d", seq_no_count, count_list_elems(seq_no_count));
				else
					printf("\nFAILURE: LIST NOT FOUND");
				break;
		case 6: display_all_lists();
				break;

		case 7: display_free_list();
				break;

		case 8: defrag();
				break;

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
