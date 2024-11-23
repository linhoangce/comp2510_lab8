CC		= gcc
CFLAGS	= -Wall
LDFLAGS =
OBJFILES = circular_node.c main.c
TARGET	 = circular_linkedlist

all: $(TARGET)

$(TARGET): $(OBJFILES)
		$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
		rm -f $(TARGET) *~