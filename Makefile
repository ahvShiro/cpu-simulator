CC = gcc
CPP = g++
LD = gcc
FLAGS = -Wall
CFLAGS = $(FLAGS)
CPPFLAGS = $(FLAGS)
LDFLAGS =
BIN_NAME = arq-sim
RM = rm

# -fprofile-arcs -ftest-coverage

########################################################

SRC = $(wildcard *.c)

headerfiles = $(wildcard *.h)

OBJS = ${SRC:.c=.o}

########################################################

# implicit rules

%.o : %.c $(headerfiles)
	$(CC) -c $(CFLAGS) $< -o $@

%.o : %.cpp $(headerfiles)
	$(CPP) -c $(CPPFLAGS) $< -o $@

########################################################

all: $(BIN_NAME)
	@echo program compiled!
	@echo yes!

$(BIN_NAME): $(OBJS)
	$(LD) -o $(BIN_NAME) $(OBJS) $(LDFLAGS)

clean:
	-$(RM) $(OBJS)
	-$(RM) $(BIN_NAME)

