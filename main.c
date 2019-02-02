#include<stdio.h>

#include "options.h"

int main () {
	int user_input = -1;
	while (user_input != 0 && user_input != 9) {
		display_options();
		initialize_main_list();
		printf("Select an option: ");
		scanf("%d", &user_input);
		process_option(user_input);
	}
	printf("\nTHANK YOU!\nEXITING PROGRAM...\n");
}
