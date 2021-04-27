#include "MyString/MyString.cpp"
#include "Garage/Garage.cpp"
#include "Vehicle/Vehicle.cpp"
using namespace std;

int main(){
  int capacity;
  cout << "Hello, to create a Garage enter a capacity: ";
  cin >> capacity;
  Garage garage(capacity);
  unsigned choice = 0;
  while(choice != 9){
    if(choice==0)
      cout << "Welcome to your garage! \n";
    cout << "Press 1 to add a vehicle \n"
         << "Press 2 to remove a vehicle \n"
         << "Press 3 to print the vehicles of the garage \n"
         << "Press 9 to exit the app\n";
    cin >> choice;
    switch(choice){
    case 1: {
      char registration[16];
      char description[16];
      int space;
      cout << "Enter Registration number: ";
      cin >> registration;
      cout << "Enter description: ";
      cin >> description;
      cout << "Enter space needed for vehicle: ";
      cin >> space;
      Vehicle vhcl(registration, description, space);
      garage.insert(vhcl);
      break;
    }
    case 2: {
      char *registrationToDelete = new (nothrow) char[16];
      cout << "Enter Registration of vehicle to delete: ";
      cin >> registrationToDelete;
      garage.erase(registrationToDelete);
      delete[] registrationToDelete;
      break;
    }
    case 3: {
      for(int i=0; i<garage.size(); i++){
      }
      garage.printGarage();
      break;
    }
    case 9: {
      return 0;
    }
    default:
      break;
    }
  }

  return 0;
}