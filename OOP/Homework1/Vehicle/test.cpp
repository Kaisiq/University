#include "../MyString/MyString.cpp"
#include "Vehicle.cpp"

#include "catch_amalgamated.cpp"


TEST_CASE("constructor"){
  Vehicle v("reg", "desc", 2);
  REQUIRE(strcmp(v.registration(),"reg") == 0);
  REQUIRE(strcmp(v.description(),"desc") == 0);
  REQUIRE(v.space() == 2);
}

TEST_CASE("constructor with empty strings"){
  Vehicle v("", "", 3);
  REQUIRE(strcmp(v.registration(),"") == 0);
  REQUIRE(strcmp(v.description(),"") == 0);
  REQUIRE(v.space() == 3);
}