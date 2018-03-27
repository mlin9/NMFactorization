#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdint>
#include <string>
#include "matrix.h"

#ifndef IMG_PARSER_H
#define IMG_PARSER_H

class ImageParser
{
	public:
	ImageParser();
	Matrix parse_image(sf::Image input);
	sf::Image compile_image(Matrix &input, string title);
	vector<vector<Matrix> > parse_matrix(sf::Image input, int width, int height);
	vector<vector<sf::Image> > compile_matrix(vector<vector<Matrix> > &input);
};

#endif
