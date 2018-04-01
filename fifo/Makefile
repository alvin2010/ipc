VERSION=v1.0

CC=gcc

PROGS=fifo_rd fifo_wr fifo_rd_nblock fifo_wr_nblock
OBJS=fifo_rd.o fifo_wr.o fifo_rd_nblock.o fifo_wr_nblock.o

all : $(PROGS)
.PHONY : clean

fifo_rd:fifo_rd.o
	$(CC) -o fifo_rd fifo_rd.o -lrt
fifo_rd.o:fifo_rd.c
	$(CC) -c fifo_rd.c

fifo_wr:fifo_wr.o
	$(CC) -o fifo_wr fifo_wr.o -lrt
fifo_wr.o:fifo_wr.c
	$(CC) -c fifo_wr.c

fifo_rd_nblock:fifo_rd_nblock.o
	$(CC) -o fifo_rd_nblock fifo_rd_nblock.o -lrt
fifo_rd_nblock.o:fifo_rd_nblock.c
	$(CC) -c fifo_rd_nblock.c

fifo_wr_nblock:fifo_wr_nblock.o
	$(CC) -o fifo_wr_nblock fifo_wr_nblock.o -lrt
fifo_wr_nblock.o:fifo_wr_nblock.c
	$(CC) -c fifo_wr_nblock.c	
clean:
	rm -f $(OBJS) $(PROGS)