CXXFLAGS = -Werror -g -std=c++11 $(OPTFLAGS)
CXX = g++
VPATH = $(CURDIR)/src/
LIBS = -lGLU -lGL -lSDL -I$(VPATH)
SOURCES = $(wildcard $(VPATH)*h)
CPPFILES = $(wildcard *cpp)
HEADERS = $(subst src/, ,$(SOURCES))
OBJECTS = $(CPPFILES:.cpp=.o)
BUILDDIR = build/
ECHO = echo -e




