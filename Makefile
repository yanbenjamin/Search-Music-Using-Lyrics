CC = g++
CC_FLAGS = -std=c++11
SRC_DIR = .

#SRC = $(wildcard *.cpp)
LIB_SRC = process_song_data.cpp 
HELPER_SRC = utils.cpp 

LIB_OBJECTS = $(patsubst %.cpp, build/%, $(LIB_SRC))
HELPER_OBJECTS = $(patsubst %.cpp, build/%.o, $(HELPER_SRC)) 

all: $(LIB_OBJECTS) $(HELPER_OBJECTS)

$(LIB_OBJECTS): build/%: %.cpp
	$(CC) $(CC_FLAGS) -o $@ $<

$(HELPER_OBJECTS): build/%.o: %.cpp
	$(CC) $(CC_FLAGS) -c -o $@ $<

clean: 
	rm -f $(LIB_OBJECTS)
	rm -f $(HELPER_OBJECTS)
	






