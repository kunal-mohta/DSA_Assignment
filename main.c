#include<stdio.h>

#include "display_options.h"

int main () {
	int user_input = -1;
	while (user_input) {
		display_options();
		printf("Select an option: ");
		scanf("%d", &user_input);
	}
	printf("\nTHANK YOU!\nEXITING PROGRAM...\n");
}
