# Compiler & Flags
CXX = cl.exe
CXXFLAGS = /Zi /EHsc /nologo /std:c++17 /W4

# Executables
ALL = vertical.exe palindrome.exe selectionSort.exe

all: $(ALL)

# Vertical: Single file build
vertical.exe: vertical.cpp
	$(CXX) $(CXXFLAGS) /Fe:vertical.exe vertical.cpp

# Palindrome: Linking palindrome.cpp & pfunctions.cpp
palindrome.exe: palindrome.cpp pfunctions.cpp pheaders.h
	$(CXX) $(CXXFLAGS) /Fe:palindrome.exe palindrome.cpp pfunctions.cpp

# selectionSort: Linking selectionSort.cpp & sfunctions.cpp
selectionSort.exe: selectionSort.cpp sfunctions.cpp sheaders.h
	$(CXX) $(CXXFLAGS) /Fe:selectionSort.exe selectionSort.cpp sfunctions.cpp

# Clean up build files
clean:
	del *.exe *.obj *.pdb *.ilk