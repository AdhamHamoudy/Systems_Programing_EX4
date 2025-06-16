# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic

# Include directories
INCLUDES = -Iinclude

# Executable names
MAIN_EXEC = main_exec
TEST_EXEC = test_exec

# === Make Main ===
Main: Demo.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) Demo.cpp -o $(MAIN_EXEC)

# === Make Test ===
test: test.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) test.cpp -o $(TEST_EXEC)
	./$(TEST_EXEC)

# === Valgrind Test ===
valgrind: test
	valgrind --leak-check=full ./$(TEST_EXEC)

# === Clean Binaries ===
clean:
	rm -f $(MAIN_EXEC) $(TEST_EXEC)
