#include "catch_amalgamated.cpp"
#include "../Person/Person.cpp"
#include "../Commands/Commands.cpp"
#include <cstring>

Vehiclelist* Vehiclelist::instance = nullptr;
Peoplelist* Peoplelist::instance = nullptr;

TEST_CASE("toLower"){
  char str[] = "STRING tO GeT tO LoWCaseS OnlYyY";
  REQUIRE(strcmp(tolower(str),"string to get to lowcases onlyyy")==0);
}

TEST_CASE("addVehicle"){
    addVehicle("BA1234BA","test descr");
    REQUIRE(strcmp(Vehiclelist::getInstance()->getVehicle("BA1234BA")->getRegNum().toString(),"BA1234BA")==0);
    Vehiclelist::getInstance()->clearVehicles();
}

TEST_CASE("addPerson"){
    addPerson("Test Person", 1);
    REQUIRE(Peoplelist::getInstance()->getPerson(1)->getID() == 1);
    Peoplelist::getInstance()->clearPeople();
}

TEST_CASE("acquire"){
  addVehicle("BA1234BA","test descr");
  addPerson("Test Person", 1);
  acquire(1,"BA1234BA");
  REQUIRE(Peoplelist::getInstance()->getPerson(1)->getVehicleViaID(0));
  Peoplelist::getInstance()->clearPeople();
  Vehiclelist::getInstance()->clearVehicles();
}

TEST_CASE("release"){
  addVehicle("BA1234BA","test descr");
  addPerson("Test Person", 1);
  REQUIRE(!Peoplelist::getInstance()->getPerson(1)->hasVehicles());
  acquire(1,"BA1234BA");
  REQUIRE(Peoplelist::getInstance()->getPerson(1)->hasVehicles());
  release(1,"BA1234BA");
  REQUIRE(!Peoplelist::getInstance()->getPerson(1)->hasVehicles());
  Peoplelist::getInstance()->clearPeople();
  Vehiclelist::getInstance()->clearVehicles();
}

TEST_CASE("isValidID"){
    REQUIRE(!isValidID("1a"));
    REQUIRE(isValidID("123352346136"));
}

TEST_CASE("removeVorP"){
  addVehicle("BA1234BA","test descr");
  addPerson("Test Person", 1);
  REQUIRE(!Vehiclelist::getInstance()->isEmpty());
  REQUIRE(!Peoplelist::getInstance()->isEmpty());
  removeVorP("1");
  REQUIRE(Peoplelist::getInstance()->isEmpty());
  removeVorP("BA1234BA");
  REQUIRE(Vehiclelist::getInstance()->isEmpty());
  try{
    removeVorP("asf@423t");
  }
  catch(std::invalid_argument& e){
    REQUIRE(&e);
  }
  Peoplelist::getInstance()->clearPeople();
  Vehiclelist::getInstance()->clearVehicles();
}

TEST_CASE("show"){
  addVehicle("BA1236BA","test descr1");
  addPerson("Test Person1", 1);
  addVehicle("BA1237BA","test descr2");
  addPerson("Test Person2", 2);
  addVehicle("BA1238BA","test descr3");
  addPerson("Test Person3", 3);
  show("people");
  show("vehicles");
  show("1");
  show("BA1236BA");
  try {
    show("gsdkjh");
  }
  catch(std::invalid_argument& e){
    REQUIRE(&e);
  }


  Peoplelist::getInstance()->clearPeople();
  Vehiclelist::getInstance()->clearVehicles();
}
