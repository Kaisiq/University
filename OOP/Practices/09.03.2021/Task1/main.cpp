#include <iostream>
using namespace std;

struct Person{
  char name[16];
  int age;
  float height;
  float weight;

  void changeName(){
    char newName[16];
    cin >> newName;
    setName(newName);
  }

  void setName(const char* nameValue) {
    for (int i = 0; i < 15; i++) {
      name[i] = nameValue[i];
    }
  }

  char* getName(){
    return name;
  }
  int getAge(){
    return age;
  }
  float getHeight(){
    return height;
  }
  float getWeight(){
    return weight;
  }
};


void printPerson(Person person){
  cout << endl << "Name: " << person.getName() << " Age: " << person.getAge() << " Height: " << person.getHeight() << " Weight: " << person.getWeight() << endl;
}

double getBMI(Person person) {
  return person.getWeight() / person.getWeight()*person.getHeight();
}

void sortArrayByBMI(Person *array, int len){
  for(int i=0; i<len ; i++){
    int min = i;
    for(int j=i; j<len; j++){
      if(getBMI(array[j]) < getBMI(array[min])){
        min = j;
      }
    }
    swap(array[min], array[i]);
  }
}

void printOldestPersonData(Person* array, size_t arrayLen) {
  size_t biggestAge = 0;
  for (int i = 0; i < arrayLen; ++i) {
    if(array[i].getAge() > biggestAge) {
      biggestAge = array[i].getAge();
    }
  }

  for (int i = 0; i < arrayLen; ++i) {
    if(array[i].getAge() == biggestAge) {
      printPerson(array[i]);
    }
  }

}



void printPersonsWithLessThanAverage(Person *array, int len){
  float averageweight = 0;
  for(int i=0; i<len; i++){
    averageweight += array[i].weight;
  }
  averageweight = averageweight / (len+0.0);

  for(int i=0; i<5; i++){
    if(array[i].weight < averageweight){
      printPerson(array[i]);
    }
  }
}

int main(){
  Person human;
  cin >> human.name;
  cin >> human.age;
  cin >> human.height;
  cin >> human.weight;
  printPerson(human);


  Person *array = new Person[5];
  for(int i=0; i<5; i++){
    cin >> array[i].name;
    cin >> array[i].age;
    cin >> array[i].height;
    cin >> array[i].weight;
  }

  sortArrayByBMI(array, 5);
  printPersonsWithLessThanAverage(array,5);
  printOldestPersonData(array, 5);



  delete[] array;

  return 0;
}