cc := g++
cflags := -std=c++11
exe_name := cprobs

$(exe_name): main.o problems.o testing.o
	@echo "building $(exe_name)..."
	@$(cc) $(cflags) -o $@ main.o problems.o testing.o
	@echo "done."

main.o: main.cpp problems.hpp testing.hpp
	@echo "compiling main.cpp..."
	@$(cc) $(cflags) -c $<

problems.o: problems.cpp problems.hpp
	@echo "compiling problems.cpp..."
	@$(cc) $(cflags) -c $<

testing.o: testing.cpp testing.hpp problems.hpp
	@echo "compiling testing.cpp..."
	@$(cc) $(cflags) -c $<

.PHONY: clean
clean:
	@echo "deleting *.o files..."
	@echo "deleting $(exe_name) executable..."
	@rm -f ./*.o $(exe_name)
	@echo "done."