# compilation flags for g++
CXXFLAGS:= -std=c++14 -g -Wall

# delete executables
clean:
	${RM} driver_list driver_sorter

# Clean input
clean-input:
	${RM} -r input

# Decompress the tar file for input data
decompress: clean-input
	tar -xvzf input.tar.gz 