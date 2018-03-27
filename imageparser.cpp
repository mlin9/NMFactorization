#include "imageparser.h"

/* CONSTRUCTORS */
ImageParser::ImageParser()
{

}
/* END CONSTRUCTORS */

/* MEMBER FUNCTIONS */
Matrix ImageParser::parse_image(sf::Image input)
{
	uint32_t buffer_int;
	sf::Color buffer_color;
	sf::Vector2u size = input.getSize();
	int width = size.x;
	int height = size.y;
	
	Matrix result(width, height);
	result.init(0);
	
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			buffer_color = input.getPixel(x,y);
			buffer_int = buffer_color.toInteger();
			result.matrix[x][y] += buffer_int;
		}
	}
	
	return result;
}

vector<vector<Matrix> > ImageParser::parse_matrix(sf::Image input, int width, int height)
{
	vector<vector<Matrix> > result;
	result.resize(height);
	
	for(int i = 0; i < height; i++)
	{
		result[i].resize(width);
	}
	
	uint32_t buffer_int;
	sf::Color buffer_color;
	sf::Vector2u size = input.getSize();
	int buffer_width = size.x / width;
	int buffer_height = size.y / height;
	
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			result[x][y].init(buffer_width, buffer_height);
			result[x][y].init(0);
		}
	}
	
	for(int y = 0; y < height; y++)
	{	
		for(int x = 0; x < width; x++)
		{
			for(int pos_y = 0; pos_y < buffer_height; pos_y++)
			{
				for(int pos_x = 0; pos_x < buffer_width; pos_x++)
				{
					buffer_color = input.getPixel(pos_x + (x*buffer_width),pos_y + (y*buffer_height));
					buffer_int = buffer_color.toInteger();
					result[x][y].matrix[pos_x][pos_y] += buffer_int;
				}
			}	
		}
	}
	
	return result;
}

sf::Image ImageParser::compile_image(Matrix &input, string title)
{
	int width = input.width;
	int height = input.height;
	
	sf::Image result;
	result.create(width, height, sf::Color::Black);
	
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			sf::Color buffer_color(static_cast<unsigned int>(input.matrix[x][y] + 0.5));
			result.setPixel(x,y,buffer_color);
		}
	}
	
	return(result);
}

vector<vector<sf::Image> > ImageParser::compile_matrix(vector<vector<Matrix> > &input)
{
	int height = input.size();
	int width = input[0].size();

	vector<vector<sf::Image> > result;
	result.resize(height);
	
	for(int i = 0; i < height; i++)
	{
		result[i].resize(width);
	}
	
	int buffer_width = input[0][0].width;
	int buffer_height = input[0][0].height;
	
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			result[x][y].create(buffer_width, buffer_height, sf::Color::Black);
		}
	}
	
	for(int y = 0; y < height; y++)
	{	
		for(int x = 0; x < width; x++)
		{
			for(int pos_y = 0; pos_y < buffer_height; pos_y++)
			{
				for(int pos_x = 0; pos_x < buffer_width; pos_x++)
				{
					sf::Color buffer_color(static_cast<unsigned int>(input[x][y].matrix[pos_x][pos_y] + 0.5));
					result[x][y].setPixel(pos_x, pos_y, buffer_color);
				}
			}	
		}
	}
	
	return result;
}

