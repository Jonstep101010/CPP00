TARGET = megaphone

CXX = c++
CCXXFLAGS = -Wall -Wextra -Werror

all: $(TARGET)

$(TARGET): megaphone.cpp
	$(CXX) $(CCXXFLAGS) -o $(TARGET) megaphone.cpp

clean:
	rm -f $(TARGET)

fclean: clean

re: clean all
