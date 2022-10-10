CC = g++
CC_FLAGS = -std=c++11
SRC_DIR = .

EXEC = build/search build/test_data_processor
BUILD = build/*
 
all: $(EXEC)

#build/process_song_data: process_song_data.cpp 
#	$(CC) $(CC_FLAGS) -o $@ $< utils.cpp 

build/search: search.cpp
	$(CC) $(CC_FLAGS) -o $@ $< utils.cpp build_data_maps.cpp process_song_data.cpp generate_queue.cpp
 
build/test_data_processor: test_data_processor.cpp 
	$(CC) $(CC_FLAGS) -o $@ $< utils.cpp process_song_data.cpp

clean: 
	rm -f $(BUILD)






