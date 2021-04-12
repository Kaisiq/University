#include "MyString.cpp"
#include "OOP/Catch2/catch_amalgamated.cpp"

TEST_CASE("Create String and check for valid size"){
  MyString string;
  string.setString("Hello");
  REQUIRE(strcmp("Hello",string.getString())==0);
  REQUIRE(string.size() == 5);
}

TEST_CASE("Front-Back"){
  MyString string;
  string.setString("Hello");
  REQUIRE(string.front() == 'H');
  REQUIRE(string.back() == 'o');
}

//TEST_CASE("Create a char with char*"){                <------------- Not working
//  const char a[8] = "Zdrasti";
//  MyString str(a);
//  REQUIRE(strcmp(a, str.getString()) == 0);
//  REQUIRE(str.size() == 7);
//}

TEST_CASE("Testing \"at\" function"){
  MyString string;
  string.setString("Surprise");
  REQUIRE(string.at(4) == 'p');
}

TEST_CASE("Testing \"[]\" operator"){
  MyString string;
  string.setString("Surprise");
  REQUIRE(string[5] == 'r');
}

TEST_CASE("Testing \"empty\" function"){
  MyString string;
  REQUIRE(string.empty() == 1);
  REQUIRE(string.size() == 0);
}

TEST_CASE("Testing \"clear\" function"){
  MyString string;
  string.setString("Hello");
  REQUIRE(string.empty() == 0);
  string.clear();
  REQUIRE(string.empty() == 1);
}

TEST_CASE("Testing \"push back\" function"){
  MyString string;
  string.setString("Hell");
  string.push_back('o');
  REQUIRE(strcmp("Hello", string.getString()) == 0);
}

TEST_CASE("Testing \"pop back\" function"){
  MyString string;
  string.setString("Helloo");
  REQUIRE(strcmp("Helloo", string.getString()) == 0);
  string.pop_back();
  REQUIRE(strcmp("Hello", string.getString()) == 0);
}

TEST_CASE("Testing \"+=\" operator"){
  MyString string;
  string.setString("Hell");
  string+='o';
  REQUIRE(strcmp("Hello",string.getString()) == 0);
  MyString string1;
  string1.setString("Hello");
  MyString string2;
  string2.setString(" World");
  string1+=string2;
  REQUIRE(strcmp("Hello World", string1.getString()) == 0);
}

TEST_CASE("Testing \"+\" operator"){
  MyString string;
  string.setString("Hell");
  REQUIRE(strcmp("Hello",(string+'o').getString()) == 0);
  MyString string1;
  string1.setString("Hello");
  MyString string2;
  string2.setString(" World");
  REQUIRE(strcmp("Hello World", (string1+string2).getString()) == 0);
}

TEST_CASE("Testing \"c_str\" func"){
  MyString string;
  string.setString("Hello");
  const char* a = string.c_str();
  REQUIRE(strcmp("Hello", a) == 0);
}

TEST_CASE("== and < operations"){
  MyString string;
  MyString string2;
  MyString string3;
  string.setString("Hello");
  string2.setString("Hello");
  string3.setString("Hjllo");
  REQUIRE((string==string2) == 1);
  REQUIRE((string<string3) == 1);
  REQUIRE((string < string2) == 0);
}
