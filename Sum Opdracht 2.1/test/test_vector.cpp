#define CATCH_CONFIG_MAIN // Deze line maakt een main voor je

#include "include/catch.hpp"
#include "../src/vector.hpp"

TEST_CASE("De construstor geeft de attributen de daadwerkelijke waardes",
"Vector constructor"){
    Vector v = Vector(2,5);
    REQUIRE(v.x == 2);
    REQUIRE(v.y == 5);
}



