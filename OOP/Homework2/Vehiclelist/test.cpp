#include "catch_amalgamated.cpp"
#include "Vehiclelist.cpp"


Vehiclelist* Vehiclelist::instance=nullptr;
Peoplelist* Peoplelist::instance=nullptr;


TEST_CASE("getInstance() and see that constructor doesnt work"){
  Vehicle v("BA1234BA", "asdasdasd");
//  Vehiclelist instance2;      <---------- Commented, because constructor is deleted adn doesnt work

  REQUIRE(Vehiclelist::getInstance());
  REQUIRE(strcmp(Vehiclelist::getInstance()->getVehicle("BA1234BA")->getRegNum().toString(),"BA1234BA")==0);

  Vehiclelist::getInstance()->clearVehicles();  //clearing vehiclelist to use same vehicles in the next testcase

}


TEST_CASE("addVehicle() && removeVehicle()"){
  Vehicle v("BA1234BA", "asdasdasd");
  REQUIRE(Vehiclelist::getInstance()->getVehicle("BA1234BA"));
  Vehiclelist::getInstance()->removeVehicle("BA1234BA");
  REQUIRE(Vehiclelist::getInstance()->isEmpty());
  Vehiclelist::getInstance()->addVehicle(v);
  REQUIRE(Vehiclelist::getInstance()->getVehicle("BA1234BA"));
  Vehiclelist::getInstance()->clearVehicles();

}
TEST_CASE("duplicateReg()"){
  Vehicle v("TA1234TA", "asdasdasd");
  try {
    Vehicle b("TA1234TA", "test2");
  }
  catch(std::invalid_argument& e){
    REQUIRE(&e);
  }
  Vehiclelist::getInstance()->clearVehicles();
}


TEST_CASE("clearVehicles()"){
  Vehicle a("TE1234ST", "asd");
  REQUIRE(!Vehiclelist::getInstance()->isEmpty());
  Vehiclelist::getInstance()->removeVehicle("TE1234ST");
  REQUIRE(Vehiclelist::getInstance()->isEmpty());
  Vehiclelist::getInstance()->clearVehicles();

}
TEST_CASE("getVegicle()"){
  Vehicle a("TE1234ST", "asd");
  REQUIRE(strcmp(Vehiclelist::getInstance()->getVehicle("TE1234ST")->getRegNum().toString(),"TE1234ST")==0);
  Vehiclelist::getInstance()->clearVehicles();
}
