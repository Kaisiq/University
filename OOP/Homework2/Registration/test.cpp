#include "catch_amalgamated.cpp"
#include "Registration.cpp"
#include <cstring>


TEST_CASE("Constructor; toString func"){
  Registration a("AB1234AB");
  REQUIRE(strcmp(a.toString(), "AB1234AB") == 0);
}

TEST_CASE("CopyConstr"){
  Registration a("AB1234AB");
  Registration b(a);
  REQUIRE(strcmp(b.toString(), a.toString())==0);
}

TEST_CASE("Operator="){
  Registration a("AB1234AB");
  Registration b = a;
  REQUIRE(strcmp(b.toString(), a.toString())==0);
}




