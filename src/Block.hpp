#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Enums.hpp"

#include <set>

class Block
{
protected :
	std::set<Property> properties;
	std::string block_name;
	char block_visual[3][3];

public :
	Block(std::string name, std::set<Property> property, char block_visual[10]);

	void addProperty(Property property);
	void addProperty(std::set<Property> property);

	void removeProperty(Property property);
	void removeProperty(const std::set<Property>& property);

	bool containProperty(Property property) const;

};

class Text : public Block
{
private :
	Entity* this_entity;

public :
	Text(std::string name, std::set<Property> property, char block_visual[10], Entity* this_entity = nullptr);

	static Text baba;
	static Text is;
	static Text you;
	static Text flag;
	static Text win;
	static Text push;
	static Text stop;

	Entity* getThisEntity();
};

class Entity : public Block
{
private :

public :
	Entity(std::string name, std::set<Property> property, char block_visual[10]);

	static Entity baba;
	static Entity flag;
};

#endif