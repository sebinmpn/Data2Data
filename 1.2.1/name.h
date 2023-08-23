#include <iostream>

class name
{
public:
	name (std::string nm): _nm(nm){};
	std::string _nm;
	void show() { std::cout << "name is " << _nm << std::endl;}
};
