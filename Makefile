basic: main.c display_options.c process_option.c options.h
	gcc main.c display_options.c process_option.c main_list_functions.c free_list_functions.c
	@echo "\nCOMPILED SUCCESSFULLY...\nEXECUTING PROGRAM..."
	@./a.out
