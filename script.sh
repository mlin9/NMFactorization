g++ -std=c++11 -c *.cpp;
g++ matrix.o main.o environment.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system;
