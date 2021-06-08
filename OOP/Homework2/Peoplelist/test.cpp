#include "catch_amalgamated.cpp"
#include "../Person/Person.cpp"
#include "Peoplelist.cpp"

Peoplelist* Peoplelist::instance = nullptr;
Vehiclelist* Vehiclelist::instance = nullptr;


TEST_CASE("addPerson()"){
  Person p("gencho", 1);
  REQUIRE(Peoplelist::getInstance()->getPerson(1));
  Peoplelist::getInstance()->clearPeople();
}

TEST_CASE("duplicateID()"){
  Person p("gencho", 1);
  try {
    Person p1("gencho", 1);
  }
  catch(std::invalid_argument& e){
    REQUIRE(&e != nullptr);
  }
  Peoplelist::getInstance()->clearPeople();

}

TEST_CASE("removePerson()"){
  Person p("gencho", 1);
  REQUIRE(!Peoplelist::getInstance()->isEmpty());
  Peoplelist::getInstance()->removePerson(1);
  REQUIRE(Peoplelist::getInstance()->isEmpty());

  Peoplelist::getInstance()->clearPeople();
}

TEST_CASE("clearPeople()"){
  Person p1("gencho",1);
  Person p2("pencho", 2);
  Person p3("sashko", 3);
  REQUIRE(!Peoplelist::getInstance()->isEmpty());
  Peoplelist::getInstance()->clearPeople();
  REQUIRE(Peoplelist::getInstance()->isEmpty());
}

TEST_CASE("getPerson()"){
  Person p1("gencho",1);
  REQUIRE(Peoplelist::getInstance()->getPerson(1));
  Peoplelist::getInstance()->clearPeople();
}

TEST_CASE("addVehicleToPerson()"){
  Person p1("gencho",1);
  Vehicle v("BA1234BA", "asdasd");
  Peoplelist::getInstance()->addVehicleToPerson(1,v);
  REQUIRE(Peoplelist::getInstance()->getPerson(1)->getVehicleViaReg("BA1234BA"));
  Peoplelist::getInstance()->clearPeople();
  Vehiclelist::getInstance()->clearVehicles();
}

TEST_CASE("addVehicleToPerson2()"){
  Person p1("gencho",2);
  Vehicle v("BA1234BA", "asdasd");
  Peoplelist::getInstance()->addVehicleToPerson(2,"BA1234BA");
  REQUIRE(Peoplelist::getInstance()->getPerson(2)->getVehicleViaReg("BA1234BA"));
  Peoplelist::getInstance()->clearPeople();
  Vehiclelist::getInstance()->clearVehicles();
}
TEST_CASE("removeVehicleFromPerson()"){
  Person p1("gencho",2);
  Vehicle v("BA1234BA", "asdasd");
  REQUIRE(!Peoplelist::getInstance()->getPerson(2)->hasVehicles());
  Peoplelist::getInstance()->addVehicleToPerson(2,"BA1234BA");
  REQUIRE(Peoplelist::getInstance()->getPerson(2)->getVehicleViaReg("BA1234BA"));
  REQUIRE(Peoplelist::getInstance()->getPerson(2)->hasVehicles());
  Peoplelist::getInstance()->removeVehicleFromPerson(2,"BA1234BA");
  REQUIRE(!Peoplelist::getInstance()->getPerson(2)->hasVehicles());
}