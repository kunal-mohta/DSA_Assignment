src = $(wildcard *.c)
obj = $(src:%.c=%.o)

run_assignment: $(src) $(obj)
	@echo "\nCOMPILING..."
	@gcc $(src)
	@echo "\nCOMPILED SUCCESSFULLY...\nEXECUTING PROGRAM..."
	@./a.out

clean:
	@rm *.out
	@rm *.o
