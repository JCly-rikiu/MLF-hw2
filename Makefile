CC = g++

SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = .
INC_DIR = ./inc

TARGET = $(BIN_DIR)/main

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.cpp=.o)))

CPPFLAGS = -g -Wall -std=c++17 -O2
INCLUDE = -I$(INC_DIR)
LIBS =

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	$(RM) $(OBJS)

run:
	$(TARGET)

7:
	$(TARGET) 7 | python3 draw.py 7

8:
	$(TARGET) 8 | python3 draw.py 8
