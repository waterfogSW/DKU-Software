#
#   DKU Operating System Lab
#           Lab2 (Vehicle Production Problem)
#           Student id : 32170758
#           Student name : 김산
#
#   Makfeile :
#       - Makefile for lab2 compilation.
#

CC = gcc
INC = -I${CURDIR}/include/
CFLAGS = -g $(INC)
LDFLAGS = -lpthread -lm

OBJS_LAB2 = lab2_sync.o lab2_init.o lab2_uprod.o lab2_cprod.o lab2_fprod.o

SRCS = $(OBJS_LAB2:.o=.c)

TARGET_LAB2 = lab2_sync

.SUFFIXES : .c .o

.c.o:
	@echo "Compiling lab2 Vehicle Production Problem $< ..."
	$(CC) -c $(CFLAGS) -o $@ $<

$(TARGET_LAB2) : $(OBJS_LAB2)
	$(CC) -o $(TARGET_LAB2) $(OBJS_LAB2) $(LDFLAGS)

all : $(TARGET_LAB2)

dep : 
	gccmaedep $(INC) $(SRCS)

clean :
	@echo "Cleaning lab2 Vehicle Production Problem $< ..."
	rm -rf $(OBJS_LAB2) $(TARGET_LAB2)
new :
	$(MAKE) clean
	$(MAKE)


