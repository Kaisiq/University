#include <iostream>
using namespace std;
void func(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] <<' ';
    }

    std::cout << "new elem\n";
    std::cout << arr[12] << ' ';
    std::cout << arr[14] << ' ';
    std::cout << arr[16] << ' ';
    std::cout << arr[17] << ' ';

    arr[16] = 5;
    std::cout << arr[16] << ' ';
}

int main()
{
    std::cout << "=============== Arrays =====================\n";

    const int size = 10;
    int a[size] = { 1,2,3,4,5,6,7,8,10};
    func(a, size);
    return 0;
    }