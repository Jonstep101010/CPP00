
CC = c++
CFLAGS = -Wall -Wextra -Werror
TARGET = megaphone

all: $(TARGET)

$(TARGET): megaphone.cpp
	$(CC) $(CFLAGS) -o $(TARGET) megaphone.cpp

clean:
	rm -f $(TARGET)

re: clean all
