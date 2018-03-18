#include <SFML/Graphics.hpp>
#include <cstdint>
#include "matrix.h"

#ifndef IMG_PARSER_H
#define IMG_PARSER_H

class ImageParser
{
	public:
	ImageParser();
	Matrix parse_image(sf::Image input);
	void compile_image(Matrix &input);
};

#endif
