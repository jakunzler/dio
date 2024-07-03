CXX = g++
ACXX = ac++

INCLUDE_DIR = include
SRC_DIR = main
BUILD_DIR = build
TEST_DIR = tests

CXXFLAGS = -I$(INCLUDE_DIR) -Wall -std=c++11
ACXXFLAGS = -I$(INCLUDE_DIR)

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

all: $(BUILD_DIR)/BancoTeste

$(BUILD_DIR)/BancoTeste: $(OBJECTS) $(BUILD_DIR)/VerificadorDeSaldo.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/VerificadorDeSaldo.o: include/balance-checker.ah
	$(ACXX) $(ACXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: all clean
