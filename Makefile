
CFLAGS += -Ialgorithms -IcodingProblems

LDFLAGS += -Losx

#C_SRC =  

default:
	gcc	*.c algorithms/*.c codingProblems/*.c -o test
	./test
clean:
	-@echo Cleaning ..


