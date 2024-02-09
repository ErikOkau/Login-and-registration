CXX = g++
CXXFLAGS = -fdiagnostics-color=always -g -std=c++14
TARGET = main.exe
SRC = main.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
