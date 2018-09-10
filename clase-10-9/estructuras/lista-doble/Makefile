CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		main.o list.o node.o element.o

LIBS =

TARGET =	listas

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
