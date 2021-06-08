#include "catch_amalgamated.cpp"
#include "Vehicle.cpp"
#include <cstring>

Peoplelist* Peoplelist::instance = nullptr;
Vehiclelist* Vehiclelist::instance = nullptr;

TEST_CASE("Constr"){
  Vehicle v("BA1234BA", "test car!123");
  REQUIRE(strcmp(Vehiclelist::getInstance()->getVehicle("BA1234BA")->getRegNum().toString(), "BA1234BA")==0);
}

TEST_CASE("getRegNum"){
  Vehicle v("AB1234AB", "test car!123");
  REQUIRE(strcmp(v.getRegNum().toString(),"AB1234AB")==0);
}


TEST_CASE("getDesc") {
  Vehicle v("BB1234AB", "test car!123");
  std::cout << v.getDesc();
}

TEST_CASE("addOwner && getOwner"){
  Vehicle v("CC1234AB", "test car!123");
  Person p("testPerson", 1);
  v.addOwner(&p);
  REQUIRE(v.hasOwner());
  v.getOwner()->print();
}
TEST_CASE("removeOwner && hasOwner"){
  Vehicle v("DD1234AB", "test car!123");
  Person p("testPerson2", 2);
  v.addOwner(&p);
  REQUIRE(v.hasOwner());
  v.removeOwner();
  REQUIRE(!v.hasOwner());
}

TEST_CASE("print"){
  Vehicle v("EE1234AB", "test car!123");
  std::cout << "\n";
  v.print();
  std::cout << "\n";
  std::cout << "\n";
}
