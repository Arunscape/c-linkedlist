CC = clang
CFLAGS = -Wall
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:%.c=%.o)

.PHONY: all clean test

all: ll

clean:
	rm -f *.o ll valgrind-out.txt  *.out

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
 
ll: $(OBJECTS)
	$(CC) -o ll $(OBJECTS)


# add -g to CC flags before enabling
 leak: all
	valgrind --leak-check=full \
		 --show-leak-kinds=all \
		 --track-origins=yes \
		 --verbose \
		 ./ll
		#  --log-file=valgrind-out.txt \
format:
	clang-format -i *.c *.h
