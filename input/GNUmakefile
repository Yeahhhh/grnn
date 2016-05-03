HEADERS = $(wildcard *.hpp)
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
#EXE = $(SRC:.cpp=)
EXE = 1pair 2random 3modify 4format


CXX = clang++ -O2 -std=c++11
#CXX = g++ -O2


all: $(EXE)

% : %.cpp
	$(CXX) $(HEADPATH) $(LIBPATH) $< -o $@ $(LINKFLAGS)


4format : 4format.cpp
	$(CXX) $(HEADPATH) $(LIBPATH) -DFORMAT1 $< -o 4format1 $(LINKFLAGS)
	$(CXX) $(HEADPATH) $(LIBPATH) -DFORMAT2 $< -o 4format2 $(LINKFLAGS)
	$(CXX) $(HEADPATH) $(LIBPATH) -DFORMAT3 $< -o 4format3 $(LINKFLAGS)



echo:
	@(echo $(HEADERS))
	@(echo $(SRC))
	@(echo $(OBJ))
	@(echo $(EXE))

clean:
#	$(RM) $(OBJ)
	$(RM) $(EXE)

run: $(EXE)
	@./run.sh

