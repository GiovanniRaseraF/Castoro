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
	g++ main.cpp -ldpp \
	-pthread \
	\
	-lboost_filesystem -lboost_system \
	-lboost_thread \
	-lboost_program_options \
	\
	-lpqxx -lpq \
	-o ../build/castoro.out && \
	echo Compiled castoro ! && \
	../build/castoro.out -h -k ~/Desktop/privatekey.key
