OBJDIR = obj
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

TARGET = main

CXX = g++
LD = g++

CXXFLAGS = -c -Wall -Iinclude -g -std=c++0x -I/opt/local/include/SOIL
LDFLAGS = -L/usr/local/lib -L/opt/local/lib

LDLIBS = -lm -lglew -lglfw3 -lSOIL -framework Cocoa -framework OpenGL -framework IOKit

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(OBJDIR)/%.o: %.cpp $(HEADERS)
	@-if [ ! -d $(OBJDIR) ]; then \
	mkdir $(OBJDIR); fi; \
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -r $(OBJDIR);
	rm $(TARGET);
