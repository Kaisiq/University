#include "catch_amalgamated.cpp"
#include "Person.cpp"
#include <cstring>

Peoplelist* Peoplelist::instance = nullptr;
Vehiclelist* Vehiclelist::instance = nullptr;

TEST_CASE("Construct, getID, getName"){
  Person p("test",12);
  REQUIRE(p.getID() == 12);
  REQUIRE(p.getName() == "test");
}

TEST_CASE("addVehicle ; getVehicleViaReg"){
  Vehicle v("BA1234BA", "asdasdasd");
  Vehicle v2("CC1111CC", "asdasdasddsads");

  Person p("test",13);
  p.addVehicle(v);
  v.addOwner(&p);
  std::cout << p.getVehicleViaID(p.findVehicleByRegnum(v.getRegNum().toString()))->getRegNum().toString() << std::endl;
  REQUIRE(strcmp(p.getVehicleViaReg("BA1234BA")->getRegNum().toString(), "BA1234BA")==0);
  Person p2("test3",55);
  p2.addVehicle("CC1111CC");
  REQUIRE(strcmp(p2.getVehicleViaReg("CC1111CC")->getRegNum().toString(), v2.getRegNum().toString())==0);
}

TEST_CASE("removeVehicle"){
  Peoplelist::getInstance()->clearPeople();
  Vehiclelist::getInstance()->clearVehicles();
  Vehicle v("AB3214AB", "asdasdasd");
  Vehicle v2("DD2222DD", "asdasdasddsads");
  Person p("test",12);
  p.addVehicle(v);
  REQUIRE(strcmp(p.getVehicleViaReg("AB3214AB")->getRegNum().toString(), v.getRegNum().toString())==0);
  p.removeVehicle(v);
  REQUIRE(p.hasVehicles()==0);

  Person p2("test",55);
  p2.addVehicle(v2);
  REQUIRE(strcmp(p2.getVehicleViaReg("DD2222DD")->getRegNum().toString(), v2.getRegNum().toString())==0);
  p2.removeVehicle("DD2222DD");
  REQUIRE(p.hasVehicles()==0);
}

TEST_CASE("getVehicleViaReg"){
  Vehiclelist::getInstance()->clearVehicles();
  Peoplelist::getInstance()->clearPeople();
  Vehicle v("BA1234BA", "asd");
  Person p("testperson", 1);
  p.addVehicle(v);
  REQUIRE(strcmp(p.getVehicleViaReg("BA1234BA")->getRegNum().toString(),"BA1234BA")==0);
}

TEST_CASE("getVehicleViaID"){
  Vehiclelist::getInstance()->clearVehicles();
  Peoplelist::getInstance()->clearPeople();
  Vehicle v("BA1234BA", "asd");
  Person p("testperson", 1);
  p.addVehicle(v);
  REQUIRE(strcmp(p.getVehicleViaID(0)->getRegNum().toString(),"BA1234BA")==0);
}

TEST_CASE("findVehicle"){
  Vehiclelist::getInstance()->clearVehicles();
  Peoplelist::getInstance()->clearPeople();
  Vehicle v("BA1234BA", "asd");
  Person p("testperson", 1);
  p.addVehicle(v);
  REQUIRE(strcmp(p.getVehicleViaID(p.findVehicle(v))->getRegNum().toString(),"BA1234BA")==0);
}

TEST_CASE("findVehicleByRegnum"){
  Vehiclelist::getInstance()->clearVehicles();
  Peoplelist::getInstance()->clearPeople();
  Vehicle v("BA1234BA", "asd");
  Person p("testperson", 1);
  p.addVehicle(v);
  REQUIRE(strcmp(p.getVehicleViaID(p.findVehicleByRegnum("BA1234BA"))->getRegNum().toString(),"BA1234BA")==0);
}

TEST_CASE("print"){
  Vehiclelist::getInstance()->clearVehicles();
  Peoplelist::getInstance()->clearPeople();
  Person p("testperson", 1);
  std::cout << "\n";
  p.print();
  std::cout << "\n\n\n";
}

TEST_CASE("hasVehicles"){
  Vehiclelist::getInstance()->clearVehicles();
  Peoplelist::getInstance()->clearPeople();
  Vehicle v("BA1234BA", "asd");
  Person p("testperson", 1);
  REQUIRE(!p.hasVehicles());
  p.addVehicle(v);
  REQUIRE(p.hasVehicles());
  p.removeVehicle(v);
  REQUIRE(!p.hasVehicles());
}

