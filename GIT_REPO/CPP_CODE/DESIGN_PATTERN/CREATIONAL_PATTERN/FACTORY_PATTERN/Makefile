CC = g++
CFLAG = -g -Wall -c
SOURCES = VehicleClient.cpp
TARGET = VehicleClient
HEADER = VehicleFactory.h\
		Vehicle.h
OBJECTS = $(SOURCES:.cpp=.o)
LIBRARY = ./LIB
INCLUDES = ./LIB

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) -L$(LIBRARY) -lVehicleStatic -I$(INCLUDES)
#	$(CC) -o $(TARGET) $(OBJECTS) -L$(LIBRARY) -lVehicleShared -I$(INCLUDES)

.cpp.o :
	$(CC) $(CFLAG) $< -o $@ -I$(INCLUDES)

clean :
	rm -f $(OBJECTS) $(TARGET)

# export LD_LIBRARY_PATH=./LIB	