OBJDIR = obj
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

TARGET = libloadshaders.so

CXX = g++
LD = g++

CXXFLAGS = -Wall -fPIC -g
LDFLAGS = -shared -g -L/usr/local/lib
LDLIBS = -lglew

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(OBJDIR)/%.o: %.cpp
	@-if [ ! -d $(OBJDIR) ]; then \
	mkdir $(OBJDIR); fi; \
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(TARGET) $(OBJECTS)
