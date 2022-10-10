CC = g++
CC_FLAGS = -std=c++11
SRC_DIR = .

EXEC = build/process_song_data
BUILD = build/*
 
all: $(EXEC)

build/process_song_data: process_song_data.cpp 
	$(CC) $(CC_FLAGS) -o $@ $< utils.cpp 

clean: 
	rm -f $(BUILD)






