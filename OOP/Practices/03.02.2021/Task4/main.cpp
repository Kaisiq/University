#include <cstring>
#include <iostream>
using namespace std;

enum Color { brown = 1, green, orange, red, yellow };

struct Fruit {
    char name[16];
    int color;
    float weight;
    float price;
};

void enterFruit(Fruit &f) {
    cin >> f.name;
    cin >> f.color;
    cin >> f.weight;
    cin >> f.price;
}

void swap(int a, int b) {
    int c = a;
    a = b;
    b = c;
}

void sortByName(Fruit arr[], int len) {
    for (int i = 0; i < len; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (strcmp(arr[min].name, arr[j].name) > 0) {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

void sortByWeight(Fruit arr[], int len) {
    for (int i = 0; i < len; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if ((strcmp(arr[min].name, arr[j].name) == 0) &&
                (arr[min].weight > arr[j].weight)) {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

void sortByPrice(Fruit arr[], int len) {
    for (int i = 0; i < len; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if ((strcmp(arr[min].name, arr[j].name) == 0) &&
                (arr[min].weight == arr[j].weight) && arr[min].price > arr[j].price) {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

void printFruit(const Fruit &f) {
    cout << "Name: " << f.name;
    cout << endl;
    cout << "Color: ";
    switch (f.color) {
        case brown:
            cout << "Brown ";
            break;
        case green:
            cout << "Green ";
            break;
        case orange:
            cout << "Orange ";
            break;
        case red:
            cout << "Red ";
            break;
        case yellow:
            cout << "Yellow ";
            break;
    };
    cout << endl;
    cout << "Weight: " << f.weight;
    cout << endl;
    cout << "Price: " << f.price;
    cout << endl << endl;
}

int main() {
    Fruit Fruits[2];
    for (int i = 0; i < 2; i++) {
        cout << "enter Fruit number " << i + 1 << ":\n";
        enterFruit(Fruits[i]);
        cout << endl;
    }

    cout << endl << "=========== Before sort ============" << endl;

    for (int i = 0; i < 2; i++) {
        printFruit(Fruits[i]);
    }

    sortByName(Fruits, 2);
    sortByWeight(Fruits, 2);
    sortByPrice(Fruits, 2);

    cout << endl << "=========== After sort ============" << endl;

    for (int i = 0; i < 2; i++) {
        printFruit(Fruits[i]);
    }

    return 0;
}