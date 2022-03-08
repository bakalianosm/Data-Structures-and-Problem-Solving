# Path for

INCLUDE = include
MODULES = modules
SOURCE = src
 
# Command line arguments
ARGS = 


# Compiler
CC = g++

# Compile options
CFLAGS = -Wall -g -I$(INCLUDE)
LDFLAGS = -lm

# .o files
OBJS = $(SOURCE)/main.o $(MODULES)/trie.o  

# The executable program
EXEC = main

# Run targets
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)


clean:
	rm -f $(OBJS) $(EXEC) 

run: $(EXEC)
	./$(EXEC) $(ARGS)

valgrind: $(EXEC)
	valgrind ./$(EXEC) $(ARGS)

 
