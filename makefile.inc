CXXFLAGS =  -g -std=c++11 $(OPTFLAGS)
DEBUG = -g -Wall -Wextra-Werror
CXX = g++
VPATH = $(CURDIR)/src/
LIBS = -lGLU -lGL -lfreetype -lSDL -lalut -lopenal -lvorbis -lvorbisfile -lpthread -I$(VPATH)
SOURCES = $(wildcard $(VPATH)*h)
CPPFILES = $(wildcard *cpp)
HEADERS = $(subst src/, ,$(SOURCES))
OBJECTS = $(CPPFILES:.cpp=.o)
BUILDDIR = build/
ECHO = echo -e




