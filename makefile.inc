CXXFLAGS = -Werror -g $(OPTFLAGS)
CXX = g++
VPATH = $(CURDIR)/src/
LIBS = -lGLU -lGL -lSDL -I$(VPATH)
# SRCDIR = src/
SOURCES = $(wildcard $(VPATH)*h)
CPPFILES = $(wildcard *cpp)
HEADERS = $(subst src/, ,$(SOURCES))
OBJECTS = $(CPPFILES:.cpp=.o)
BUILDDIR = build/
ECHO = echo -e




