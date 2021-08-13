 set -e
 g++ -c main.cpp -o ./obj/main.o
 g++ -o ./bin/main obj/main.o -s -Wall -lraylib -lm -lpthread -ldl -lrt /usr/lib/libX11.so
 ./bin/main
