CXX = c++ -std=c++17
CXXFLAGS = # -Wall -Wextra -Werror
TARGET = 1891

SRCS = main.cpp FragmentQuadrant.cpp XYCoordinate.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
