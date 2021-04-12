#include "Garage.cpp"
#include "catch_amalgamated.cpp"


TEST_CASE("constructor"){
  Garage garage(3);
  REQUIRE(garage.size() == 0); //no vehicles in the garage
}

TEST_CASE("insert + copyConstructor"){
  Garage garage(3);
  Vehicle v("BAPHA", "asd", 2);
  garage.insert(v);
  Garage garage2 = garage;
  REQUIRE(garage2.empty()==0);
  REQUIRE(garage2.size() == 1);
  REQUIRE(garage2.at(1).space() == 2);
}

TEST_CASE("erase , empty and size"){
  Vehicle v("BAPHA", "asd", 2);
  Garage garage(3);
  garage.insert(v);
  REQUIRE(garage.size()==1);
  garage.erase("BAPHA");
  REQUIRE(garage.size()==0);
  REQUIRE(garage.empty()==1);
}

TEST_CASE("at  and   []"){
  Vehicle v("BAPHA", "asd", 2);
  Garage garage(3);
  garage.insert(v);
  Vehicle v1("BAPHA1", "a2s2d", 1);
  garage.insert(v1);
  REQUIRE(strcmp(garage.at(1).registration(),"BAPHA") == 0);
  REQUIRE(strcmp(garage.at(2).registration(),"BAPHA1") == 0);
  REQUIRE(strcmp(garage[1].registration(),"BAPHA") == 0);
  REQUIRE(strcmp(garage[2].registration(),"BAPHA1") == 0);
}

TEST_CASE("clear"){
  Vehicle v("BAPHA", "asd", 2);
  Garage garage(3);
  garage.insert(v);
  Vehicle v1("BAPHA1", "a2s2d", 1);
  garage.insert(v1);
  garage.clear();
  REQUIRE(garage.size()==0);
  REQUIRE(garage.empty()==1);
}

TEST_CASE("find"){
  Garage garage(6);
  Vehicle v2("BA2PHA", "asd", 1);
  garage.insert(v2);
  Vehicle v("BAPHA", "asd", 2);
  garage.insert(v);
  Vehicle v3("B2APH3A", "asd", 1);
  garage.insert(v3);
  REQUIRE(strcmp(garage.find("BAPHA")->registration(), "BAPHA")==0);
}

