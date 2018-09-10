CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		GetPostExample.o

LIBS =

TARGET =	GetPostExample

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
