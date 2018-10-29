CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -lmysqlcppconn -lmysqlcppconn-static

OBJS =		main.o fecha.o persona.o 

LIBS =

TARGET =	26-09

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)  -lmysqlcppconn -lmysqlcppconn-static

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
