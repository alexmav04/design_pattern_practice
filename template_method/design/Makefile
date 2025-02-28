CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -Iuno/

SRC_DIR = uno
BUILD_DIR = build_game
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJ_FILES := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))
TARGET = $(BUILD_DIR)/cardGame.exe

.PHONY: all clean $(BUILD_DIR)

all: $(TARGET)

$(BUILD_DIR):
	if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"

$(TARGET): $(OBJ_FILES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	if exist "$(BUILD_DIR)" (del /F /Q /S "$(BUILD_DIR)\*" && rmdir /S /Q "$(BUILD_DIR)")
