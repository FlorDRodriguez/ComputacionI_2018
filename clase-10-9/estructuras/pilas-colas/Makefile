CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		main.o element.o node.o queue.o

LIBS =

TARGET =	pilasColas

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
