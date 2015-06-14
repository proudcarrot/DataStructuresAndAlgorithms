CC = g++
CFLAGS = -W -Wall -Wextra -pedantic
MAIN = test
SRCS = $(wildcard *.cpp)
# define the C object files
OBJS = $(SRCS: .cpp=.o)

all:$(MAIN)

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)


.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN)
