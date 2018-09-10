CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		main.o persona.o fecha.o

LIBS =

TARGET =	ejecutable

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
