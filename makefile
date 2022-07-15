#
# PROGRAM:    School Member system
#
    
# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

# Rule to link object code files to create executable file
main: main.o members.o student.o faculty.o
	$(CXX) $(CXXFLAGS) -o main $^

# Rules to compile source code file to object code
main.o: main.cpp members.h 
members.o: members.cpp members.h
student.o: student.cpp student.h
faculty.o: faculty.cpp faculty.h

student.h: members.h
faculty.h: members.h

# Pseudo-target to remove object code and executable files
clean:
	rm -f main *.o