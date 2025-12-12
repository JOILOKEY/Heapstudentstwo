CXX = g++
CXXFLAGS = -Wall -std=c++11

SRC = main.cpp address.cpp date.cpp student.cpp
OBJ = $(SRC:.cpp=.o)

EXEC = student_data

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(EXEC)
	./$(EXEC)

debug: $(EXEC)
	gdb $(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)


clean:
	rm -f *.o $(EXEC)
