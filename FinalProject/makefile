PROG = final
CC = g++
OBJS = MusicTree.o ProjectDriver.o
CPPFLAGS = -Wall -std=c++11

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)
MusicTree.o : MusicTree.h
	$(CC) $(CPPFLAGS) -c MusicTree.cpp
ProjectDriver.o :
	$(CC) $(CPPFLAGS) -c ProjectDriver.cpp
clean:
	$(RM) $(PROG) $(OBJS)