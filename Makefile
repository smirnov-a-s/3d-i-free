OBJDIR = obj
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

TARGET = main

CXX = g++
LD = g++

CXXFLAGS = -c -Wall -g
LDFLAGS = -L/usr/local/lib -Lutils

LDLIBS = -lm -lglew -lglfw3 -lloadshaders -framework Cocoa -framework OpenGL -framework IOKit

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(OBJDIR)/%.o: %.cpp
	@-if [ ! -d $(OBJDIR) ]; then \
	mkdir $(OBJDIR); fi; \
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -r $(OBJDIR);
	rm $(TARGET);
