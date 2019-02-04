src = $(wildcard *.c)

run_assignment:
	@echo "\nCOMPILING..."
	@gcc $(src)
	@echo "\nCOMPILED SUCCESSFULLY...\nEXECUTING PROGRAM..."
	@./a.out

clean:
	@rm *.out
	@rm *.o
