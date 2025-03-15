CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -I. -I./sprite -I./collision_handlers

BUILD_DIR = build
SRC_DIRS = . sprite collision_handlers

SRC_FILES := $(wildcard $(foreach dir, $(SRC_DIRS), $(dir)/*.cpp))
OBJ_FILES := $(patsubst %,$(BUILD_DIR)/%,$(SRC_FILES:.cpp=.o))

ifeq ($(OS), Windows_NT)
    RM = if exist $(BUILD_DIR) (del /F /Q /S $(BUILD_DIR)\* && rmdir /S /Q $(BUILD_DIR))
    MKDIR = if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"
    MKDIR_OBJ = if not exist "$(dir $@)" mkdir "$(dir $@)"
    EXE_SUFFIX = .exe
else
    RM = rm -rf $(BUILD_DIR)
    MKDIR = mkdir -p $(BUILD_DIR)
    MKDIR_OBJ = mkdir -p $(dir $@)
    EXE_SUFFIX =
endif

TARGET = $(BUILD_DIR)/collision$(EXE_SUFFIX)

.PHONY: all clean $(BUILD_DIR)

all: $(TARGET)

$(BUILD_DIR):
	$(MKDIR)

$(TARGET): $(OBJ_FILES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(MKDIR_OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM)
