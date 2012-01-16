# Makefile

CC = g++
CFLAGS = -g -Wall -Wextra
OBJS = ngon.o utils.o

ngon: $(OBJS)
	ar rvs libngon.a $(OBJS)

clean:
	del *.o

ngon.o: ngon.h
utils.o: utils.h
utils.h: ngon.h

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<
