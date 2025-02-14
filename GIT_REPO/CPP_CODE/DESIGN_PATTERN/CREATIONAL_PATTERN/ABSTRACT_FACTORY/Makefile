CC = g++
CFLAG = -g -Wall -c --std=c++17
SOURCES = VehicleClient.cpp
TARGET = VehicleClient
HEADER = AbsVehicleFactory.h\
		AutoMobileFactory.h
OBJECTS = $(SOURCES:.cpp=.o)
LIBRARY = ./LIB
INCLUDES = ./LIB

$(TARGET) : $(OBJECTS)
#	$(CC) -o $(TARGET) $(OBJECTS) -L$(LIBRARY) -lAutoMobFactoryStatic -I$(INCLUDES)
	$(CC) -o $(TARGET) -g $(OBJECTS) -L$(LIBRARY) -lAutoMobFactoryShared -I$(INCLUDES)

.cpp.o :
	$(CC) $(CFLAG) $< -o $@ -I$(INCLUDES)

clean :
	rm -f $(OBJECTS) $(TARGET)

# export LD_LIBRARY_PATH=./LIB	