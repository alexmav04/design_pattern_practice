CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

TARGET = showdown.exe

SRCS += main.cpp \
	game.cpp \
	player.cpp \
	deck.cpp \
	card.cpp \
	ai_player.cpp \
	human_player.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /F /Q $(TARGET) $(OBJS) 2>nul || exit 0
