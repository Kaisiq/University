#include "MyString.cpp"
#include "../Catch2/catch_amalgamated.cpp"

TEST_CASE("Default Constructor with setString func and check for valid size"){
  MyString string;
  string.setString("Hello");
  REQUIRE(strcmp("Hello",string.getString())==0);
  REQUIRE(string.size() == 5);
}

TEST_CASE("Constructor with char*"){
  MyString str("Zdrasti");
  REQUIRE(strcmp("Zdrasti", str.getString()) == 0);
  REQUIRE(str.size() == 7);
}

TEST_CASE("Constructor with empty char*"){
  MyString str("");
  REQUIRE(strcmp("", str.c_str()) == 0);
  REQUIRE(str.size() == 0);
  REQUIRE(str.empty() == 1);
}


TEST_CASE("CopyConstr and assignment operator test"){
  MyString str1("Hello");
  MyString str2 = str1;
  MyString str3(str1);
  REQUIRE(strcmp(str2.c_str(), "Hello") == 0);
  REQUIRE(strcmp(str3.c_str(),"Hello") == 0);
}

TEST_CASE("CopyConstr with empty MyString"){
  MyString str1("");
  MyString str2 = str1;
  MyString str3(str1);
  REQUIRE(str1.empty() == 1);
  REQUIRE(str2.empty() == 1);
  REQUIRE(str3.empty() == 1);
  REQUIRE(strcmp(str2.c_str(),str3.c_str()) == 0);
  REQUIRE(strcmp(str2.c_str(), "") == 0);
}

TEST_CASE("Front-Back"){
  MyString string("Hello");
  REQUIRE(string.front() == 'H');
  REQUIRE(string.back() == 'o');
}

TEST_CASE("Front-Back with string with a length of one"){
  MyString str("a");
  REQUIRE(str.front() == 'a');
  REQUIRE(str.back() == 'a');
}

TEST_CASE("Testing \"at\" function"){
  MyString string;
  string.setString("Surprise");
  REQUIRE(string.at(4) == 'p');
  REQUIRE(string.at(1) == string.front());
  REQUIRE(string.at(8) == string.back());
}

TEST_CASE("Testing \"[]\" operator"){
  MyString string;
  string.setString("Surprise");
  REQUIRE(string[5] == 'r');
  REQUIRE(string[1] == string.front());
  REQUIRE(string[8] == string.back());
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

TEST_CASE("Clear empty MyString"){
  MyString str;
  REQUIRE(str.size() == 0);
  str.clear();
  REQUIRE(str.size() == 0);
}

TEST_CASE("Testing \"push back\" function"){
  MyString string;
  string.setString("Hell");
  string.push_back('o');
  REQUIRE(strcmp("Hello", string.getString()) == 0);

  //test with a long string
  MyString str;
  str.setString("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  str.push_back('a');
  REQUIRE(strcmp("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", str.getString()) == 0);
}

TEST_CASE("Testing \"pop back\" function"){
  MyString string;
  string.setString("Helloo");
  REQUIRE(strcmp("Helloo", string.getString()) == 0);
  string.pop_back();
  REQUIRE(strcmp("Hello", string.getString()) == 0);
}


//This test should fail all times!!  <--------------
//TEST_CASE("Pop back empty MyString"){
//  MyString str("");
//  str.pop_back();
//}

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

TEST_CASE("empty MyString += \'\' "){
  MyString str("");
  str+=0;
  REQUIRE(str.size() == 0);
  REQUIRE(str.empty() == 1);
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

TEST_CASE("empty MyString += empty MyString"){
  MyString str1("");
  REQUIRE(str1.size() == 0);
  REQUIRE(str1.empty() == 1);
  MyString str2("");
  str1+=str2;
  REQUIRE(str1.size() == 0);
  REQUIRE(str1.empty() == 1);
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
