VERSION=v1.0

CC=gcc

PROGS=mq_create mq_unlink mq_send mq_recv mq_notify_err1 mq_notify_err2 mq_notify_unblock mq_thread
OBJS=mq_create.o mq_unlink.o mq_send.o mq_recv.o mq_notify_err1.o mq_notify_err2.o mq_notify_unblock.o mq_thread.o

all : $(PROGS)
.PHONY : clean

mq_create:mq_create.o
	$(CC) -o mq_create mq_create.o -lrt
mq_create.o:mq_create.c
	$(CC) -c mq_create.c

mq_unlink:mq_unlink.o
	$(CC) -o mq_unlink mq_unlink.o -lrt
mq_unlink.o:mq_unlink.c
	$(CC) -c mq_unlink.c

mq_send:mq_send.o
	$(CC) -o mq_send mq_send.o -lrt
mq_send.o:mq_send.c
	$(CC) -c mq_send.c

mq_recv:mq_recv.o
	$(CC) -o mq_recv mq_recv.o -lrt
mq_recv.o:mq_recv.c
	$(CC) -c mq_recv.c

mq_notify_err1:mq_notify_err1.o
	$(CC) -o mq_notify_err1 mq_notify_err1.o -lrt
mq_notify_err1.o:mq_notify_err1.c
	$(CC) -c mq_notify_err1.c	

mq_notify_err2:mq_notify_err2.o
	$(CC) -o mq_notify_err2 mq_notify_err2.o -lrt
mq_notify_err2.o:mq_notify_err2.c
	$(CC) -c mq_notify_err2.c	

mq_notify_unblock:mq_notify_unblock.o
	$(CC) -o mq_notify_unblock mq_notify_unblock.o -lrt
mq_notify_unblock.o:mq_notify_unblock.c
	$(CC) -c mq_notify_unblock.c	

mq_thread:mq_thread.o
	$(CC) -o mq_thread mq_thread.o -lrt
mq_thread.o:mq_thread.c
	$(CC) -c mq_thread.c	

clean:
	rm -f $(OBJS) $(PROGS)