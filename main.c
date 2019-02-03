#include<stdio.h>

#include "options.h"

int main () {
	int user_input = -1;
	initialize_main_list();

	while (1) {
		display_options();
		printf("Select an option: ");
		scanf("%d", &user_input);
		if (user_input != 0)
			process_option(user_input);
		else
			break;
	}
	printf("\nTHANK YOU!\nEXITING PROGRAM...\n");
}
