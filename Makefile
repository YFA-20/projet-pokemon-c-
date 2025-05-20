# =============================
# Compilateur & options
# =============================
CXX      := g++
CXXFLAGS := -std=c++17 -I./include -Wall -Wextra

# =============================
# Fichiers sources
# =============================

SRC_DIR  := src
INC_DIR  := include
TEST_DIR := tests

SRC_APP := $(SRC_DIR)/main.cpp              \
           $(SRC_DIR)/Pokemon.cpp           \
           $(SRC_DIR)/Attack.cpp            \
           $(SRC_DIR)/Type.cpp              \
           $(SRC_DIR)/Dresseur.cpp          \
           $(SRC_DIR)/Combat.cpp            \
           $(SRC_DIR)/Joueur.cpp            \
           $(SRC_DIR)/LeaderGym.cpp         \
           $(SRC_DIR)/MaitrePokemon.cpp     \
           $(SRC_DIR)/MenuPrincipal.cpp     \
           $(SRC_DIR)/DataLoader.cpp        \

OBJ_APP := $(SRC_APP:.cpp=.o)
TARGET  := pokemon-simulator

# =============================
# Fichiers de test
# =============================
SRC_TEST := $(TEST_DIR)/Pokemon.test.cpp \
            $(SRC_DIR)/Pokemon.cpp       \
            $(SRC_DIR)/Attack.cpp        \
            $(SRC_DIR)/Type.cpp

TEST_BIN := runTests

# =============================
# Règles Make
# =============================
.PHONY: all clean test

# Compilation complète de l'application
all: $(TARGET)

$(TARGET): $(OBJ_APP)
	$(CXX) $(CXXFLAGS) -o $@ $^

# =============================
# Compilation des tests
# =============================
$(TEST_BIN): $(TEST_DIR)/catch.hpp $(SRC_TEST)
	$(CXX) $(CXXFLAGS) -I$(TEST_DIR) $(SRC_TEST) -o $@

test: $(TEST_BIN)
	./$(TEST_BIN)

# =============================
# Nettoyage
# =============================
clean:
	rm -f $(OBJ_APP) $(TARGET) $(TEST_BIN)
