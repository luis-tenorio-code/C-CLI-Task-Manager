CC=gcc
TARGET=appCli
BIN_DIR=bin
SRC_DIR=src
INCLUDE_DIR=include

SRCS=$(wildcard $(SRC_DIR)/main.c $(SRC_DIR)/func-crud.c)

clear:
	rm -rf $(BIN_DIR) && clear

run: build
	$(BIN_DIR)/$(TARGET)

build:
	mkdir -p $(BIN_DIR)
	$(CC) $(SRCS) -I$(INCLUDE_DIR) -o $(BIN_DIR)/$(TARGET)

.PHONY: clear run build
