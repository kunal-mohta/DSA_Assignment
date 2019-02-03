#include<stdio.h>

#include "options.h"

int main () {
	int user_input = -1;
	initialize_main_list();

	while (user_input != 0) {
		display_options();
		printf("Select an option: ");
		scanf("%d", &user_input);
		process_option(user_input);
	}
	printf("\nTHANK YOU!\nEXITING PROGRAM...\n");
}
