VERSION=v1.0

CC=gcc

PROGS=shm_create shm_unlink shm_read shm_write shm_diff_proc
OBJS=shm_create.o shm_unlink.o shm_read.o shm_write.o shm_diff_proc.o

all : $(PROGS)
.PHONY : clean

shm_create:shm_create.o
	$(CC) -o shm_create shm_create.o -lrt
shm_create.o:shm_create.c
	$(CC) -c shm_create.c

shm_unlink:shm_unlink.o
	$(CC) -o shm_unlink shm_unlink.o -lrt
shm_unlink.o:shm_unlink.c
	$(CC) -c shm_unlink.c

shm_read:shm_read.o
	$(CC) -o shm_read shm_read.o -lrt
shm_read.o:shm_read.c
	$(CC) -c shm_read.c

shm_write:shm_write.o
	$(CC) -g -o shm_write shm_write.o -lrt
shm_write.o:shm_write.c
	$(CC) -c shm_write.c

shm_diff_proc:shm_diff_proc.o
	$(CC) -o shm_diff_proc shm_diff_proc.o -lrt
shm_diff_proc.o:shm_diff_proc.c
	$(CC) -c shm_diff_proc.c

clean:
	rm -f $(OBJS) $(PROGS)
