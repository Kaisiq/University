#include <iostream>
using namespace std;

struct Planet{
    char name[5];
    float distance;
    double diameter;
    double weight;
};

void insertPlanet(Planet& planet) {
    for(int i=0; i<5; i++){
        cin >> planet.name[i];
    }
    cin >> planet.distance;
    cin >> planet.diameter;
    cin >> planet.weight;
}

void printInformation(const Planet& P){
    for(int i=0; i<5; i++){
        cout << P.name[i];
    }
    cout << endl;
    cout << P.distance;
    cout << endl;
    cout << P.diameter;
    cout << endl;
    cout << P.weight;
    cout << endl;
}

float travelTime(const Planet& p) {
    return p.distance/(299792+0.0);
}

int main(){
    Planet Planets[2];
    for (int i=0; i<2; i++){
        insertPlanet(Planets[i]);
    }
    for (int i=0; i<2; i++){
        printInformation(Planets[i]);
    }
    cout << endl;
    for (int i=0; i<2; i++){
        cout << travelTime(Planets[i]);
        cout << endl;
    }

    return 0;
}