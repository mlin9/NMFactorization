#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <SFML/Graphics.hpp>
#include "imageparser.h"
#include "matrix.h"
//#include "environment.h"

using namespace std;

int main()
{	
/*
	sf::RenderWindow window( sf::VideoMode( 800, 800 ), "ImageMatrix Testing");
	Environment environment(&window);
	environment.start();
*/
	ImageParser parser;
	sf::Image image;
	assert(image.loadFromFile("spoiler.png"));
	
	vector<vector<Matrix> > input = parser.parse_matrix(image, 6, 6);
	vector<vector<sf::Image> > result = parser.compile_matrix(input);
	
	int counter = 0;
	
	for(int y = 0; y < 6; y++)
	{
		for(int x = 0; x < 6; x++)
		{
			result[x][y].saveToFile(std::to_string(counter) + ".png");
			counter++;
		}
	}
	
}
