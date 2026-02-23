# Compiler and Flags
CXX = cl.exe
CXXFLAGS = /Zi /EHsc /nologo /std:c++17 /W4

# Target Executables
ALL = vertical.exe palindrome.exe selectionSort.exe

all: $(ALL)

# Program 1: Simple single-file build
vertical.exe: vertical.cpp
	$(CXX) $(CXXFLAGS) /Fe:vertical.exe vertical.cpp

# Program 2: Linking palindrome.cpp and pfunctions.cpp
palindrome.exe: palindrome.cpp pfunctions.cpp pheaders.h
	$(CXX) $(CXXFLAGS) /Fe:palindrome.exe palindrome.cpp pfunctions.cpp

# Program 3: Linking selectionSort.cpp and sfunctions.cpp
selectionSort.exe: selectionSort.cpp sfunctions.cpp sheaders.h
	$(CXX) $(CXXFLAGS) /Fe:selectionSort.exe selectionSort.cpp sfunctions.cpp

# Clean up build files
clean:
	del *.exe *.obj *.pdb *.ilk