src = $(wildcard *.c)
obj = $(src:%.c=%.o)

run_assign: $(src) $(obj)
	@echo "\nCOMPILING..."
	@gcc $(src)
	@echo "\nCOMPILED SUCCESSFULLY...\nEXECUTING PROGRAM..."
	@./a.out

clean:
	@rm *.out
	@rm *.o
