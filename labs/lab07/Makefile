# Compiler & Flags
CXX = cl.exe
CXXFLAGS = /Zi /EHsc /nologo /std:c++17 /W4

# Executables
ALL = vertical.exe palindrome.exe selectionSort.exe

all: $(ALL)

# Vertical
vertical.exe: vertical.cpp
	$(CXX) $(CXXFLAGS) /Fe:vertical.exe vertical.cpp

# Palindrome: depends on headers & separate objects
palindrome.exe: palindrome.obj pfunctions.obj
	$(CXX) $(CXXFLAGS) /Fe:palindrome.exe palindrome.obj pfunctions.obj

# selectionSort: depends on headers & separate objects
selectionSort.exe: selectionSort.obj sfunctions.obj
	$(CXX) $(CXXFLAGS) /Fe:selectionSort.exe selectionSort.obj sfunctions.obj

# Compilation for individual files (flags if .cpp or .h changes)
palindrome.obj: palindrome.cpp pheaders.h
	$(CXX) $(CXXFLAGS) /c palindrome.cpp

pfunctions.obj: pfunctions.cpp pheaders.h
	$(CXX) $(CXXFLAGS) /c pfunctions.cpp

selectionSort.obj: selectionSort.cpp sheaders.h
	$(CXX) $(CXXFLAGS) /c selectionSort.cpp

sfunctions.obj: sfunctions.cpp sheaders.h
	$(CXX) $(CXXFLAGS) /c sfunctions.cpp

# Clean build files
clean:
	del /Q *.exe *.obj *.pdb *.ilk
