TARGET = megaphone

CC = c++
CFLAGS = -Wall -Wextra -Werror

all: $(TARGET)

$(TARGET): megaphone.cpp
	$(CC) $(CFLAGS) -o $(TARGET) megaphone.cpp

clean:
	rm -f $(TARGET)

fclean: clean

re: clean all
