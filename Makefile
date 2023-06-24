# Pseudo targets
.PHONY : clean install uninstall

# Variables and flags
TARGET   = CalcBit
CPP      = g++
CPPFLAGS = -c -Wall
LDFLAGC  =
OUTFLAGS = -o

# Path for src files
PREF_SRC = ./src/
PREF_OBJ = ./obj/
PREF_BIN = /usr/local/bin



# We get src files in src-dir
SRC      = $(wildcard $(PREF_SRC)*.cpp)

# We get hpp files in src-dir
HPP 	 = $(wildcard $(PREF_SRC)*.hpp)

# We get obj files before compile
OBJ 	 = $(patsubst $(PREF_SRC)%.cpp, $(PREF_OBJ)%.o, $(SRC))

# We get executable file
$(TARGET) : $(OBJ)
	$(CPP) $(LDFLAGS) $(OBJ) $(OUTFLAGS) $(TARGET)

# We compile src.cpp
$(PREF_OBJ)%.o : $(PREF_SRC)%.cpp $(HPP)
	$(CPP) $(CPPFLAGS) $< $(OUTFLAGS) $@

# Intall calculator in System
install:
	sudo install $(TARGET) $(PREF_BIN)

# Uninstall calculator from System
uninstall:
	sudo rm -rf $(PREF_BIN)/$(TARGET)

# Remove all object files and Executable
clean:
	rm -rf $(OBJ) $(TARGET)
