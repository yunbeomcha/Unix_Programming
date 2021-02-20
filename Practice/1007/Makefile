CC = gcc
CFLAGS =

TARGET = test1_1
SRC = test1_1.c test2_1.c
OBJS = $(SRC:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(INC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(OBJS) $(TARGET)

