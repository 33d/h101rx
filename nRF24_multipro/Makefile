CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		Bayang.o nRF24L01.o util.o spi.o nrf_bridge.o XN297_emu.o main.o

LIBS =

TARGET =	nrf24_multipro_rx

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
