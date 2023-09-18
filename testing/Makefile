# Authors: 
# + Giovanni Rasera : c++ code
# + Lorenzo Mancini : database and specifications

# Links:
# + https://github.com/GiovanniRaseraF
# + https://github.com/MancioLollo

# for now using Makefile
# TODO: @MancioLollo / @GiovanniRaseraF: port to cmake
# TODO: @MancioLollo / @GiovanniRaseraF: windows port

all:
	g++ new_test.cpp \
	-lpqxx -lpq \
	\
	-lgtest \
	-o ./new_test.out && \
	echo GTest Compiled !&& \
	./new_test.out
