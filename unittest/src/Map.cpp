#include "Catch2/catch.hpp"

#include "Map.hpp"

TEST_CASE("Map::Default Constructor", "[Map]")
{
    Map<10, 10> map;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            REQUIRE(map[i][j] == nullptr);
        }
    }
}

TEST_CASE("Map::[]Operator Overloading","[Map]")
{
    Block block1(BlockId::BABA, BlockType::ENTITY, { Property::PUSH }, "         ");
    Block block2(BlockId::BABA, BlockType::ENTITY, { Property::YOU }, "         ");
    Block block3(BlockId::BABA, BlockType::ENTITY, { Property::WIN }, "         ");
    Block block4(BlockId::BABA, BlockType::ENTITY, { Property::STOP }, "         ");

    Map<2,2> map;

    map[0][0] = &block1;
    map[0][1] = &block2;
    map[1][0] = &block3;
    map[1][1] = &block4;

    REQUIRE(map[0][0] == &block1 );
    REQUIRE(map[0][1] == &block2 );
    REQUIRE(map[1][0] == &block3 );
    REQUIRE(map[1][1] == &block4 );
}

TEST_CASE("Map::getWidth","[Map]")
{
    Map<10,10> map;
    REQUIRE(map.getWidth() == 10);
}

TEST_CASE("Map::getHeight", "[Map]")
{
	Map<10, 10> map;
	REQUIRE(map.getHeight() == 10);
}

TEST_CASE("Map::Update", "[Map]")
{
	Map<10, 10> map;

	map[1][1] = &Text::baba;
	map[1][2] = &Text::is;
	map[1][3] = &Text::you;

	REQUIRE(!Entity::baba.containProperty(Property::YOU));
	REQUIRE(map.update());
	REQUIRE(Entity::baba.containProperty(Property::YOU));

	map[2][1] = &Text::baba;
	map[2][2] = &Text::is;
	map[2][3] = &Text::win;

	REQUIRE(map.update());
	REQUIRE(Entity::baba.containProperty(Property::YOU));
	REQUIRE(Entity::baba.containProperty(Property::WIN));

	map[3][1] = &Text::flag;
	map[3][2] = &Text::is;
	map[3][3] = &Text::baba;

	REQUIRE(map.update());
	REQUIRE(Entity::flag.containProperty(Property::YOU));
	REQUIRE(Entity::flag.containProperty(Property::WIN));

	Map<10, 10> map2;

	map[1][1] = &Text::baba;
	map[1][2] = &Text::is;
	map[1][3] = &Entity::flag;

	REQUIRE(!map2.update());

	map[2][1] = &Text::baba;
	map[2][2] = &Text::flag;
	map[2][3] = &Text::win;

	REQUIRE(map2.update());
	REQUIRE(!Entity::baba.containProperty(Property::WIN));

	map[3][1] = &Text::baba;
	map[3][2] = &Text::is;
	map[3][3] = &Text::win;
	map[3][4] = &Text::you;

	REQUIRE(map2.update());
	REQUIRE(Entity::baba.containProperty(Property::WIN));
	REQUIRE(!Entity::baba.containProperty(Property::YOU));

}