VERSION=v1.0

CC=gcc

PROGS=pipe pipe_signal pipe_capacity
OBJS=pipe.o pipe_signal.o pipe_capacity.o

all : pipe pipe_signal pipe_capacity
.PHONY : clean

pipe:pipe.o
	$(CC) -o pipe pipe.o -lrt
pipe.o:pipe.c
	$(CC) -c pipe.c

pipe_signal:pipe_signal.o
	$(CC) -o pipe_signal pipe_signal.o -lrt
pipe_signal.o:pipe_signal.c
	$(CC) -c pipe_signal.c
pipe_capacity:pipe_capacity.o
	$(CC) -o pipe_capacity pipe_capacity.o -lrt
pipe_capacity.o:pipe_capacity.c
	$(CC) -c pipe_capacity.c
clean:
	rm -f $(OBJS) $(PROGS)
