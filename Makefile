CXX       := g++
CXXFLAGS  := -std=c++17 -I./include -Wall -Wextra

# Application principale
SRC_APP   := src/main.cpp src/Pokemon.cpp src/Attack.cpp src/Type.cpp src/Dresseur.cpp src/Combat.cpp
OBJ_APP   := $(SRC_APP:.cpp=.o)
TARGET    := pokemon-simulator

# Tests unitaires
SRC_TEST  := tests/Pokemon.test.cpp src/Pokemon.cpp
TEST_BIN  := runTests

.PHONY: all test clean

all: $(TARGET)

$(TARGET): $(OBJ_APP)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Génération de l'exécutable de tests
$(TEST_BIN): $(SRC_TEST) tests/catch.hpp
	$(CXX) $(CXXFLAGS) -I./tests $^ -o $@

# Lancer les tests
test: $(TEST_BIN)
	./$(TEST_BIN)

clean:
	rm -f $(OBJ_APP) $(TARGET) $(TEST_BIN)

