#include <iostream>
#include "SLList.cpp"

int main() {
  SLList<int> j;

    int i1;
    int i2;
    int i3;
    int i4;


    std::cout<< "Enter 4 numbers: \n";
    std::cin >> i1;
    std::cin >> i2;
    std::cin >> i3;
    std::cin >> i4;

    std::cout<< "Push back first two, push front last two \n";
    j.push_back(i1);
    j.push_back(i2);
    j.push_front(i3);
    j.push_front(i4);
    
    
    j.print();
    std::cout << "\n\n";

    j.pop_back();
    std::cout << "Pop back utilized\n";
    j.print();
    std::cout << "\n\n";


    SLList<int> k(j);

    std::cout << "Constructor utilized\n";

    k.print();
    std::cout << "\n\n";
    
    k = j;
    k.push_back(7);

    std::cout << "Push back utilized\n";
    k.print();
    std::cout << "\n\n";

    std::cout << "Pop back utilized\n";
    k.pop_back();
    k.print();
    std::cout << "\n\n";


    std::cout << "Insert utilized\n";
    k.insert(2, 2, 2);
    k.print();
    std::cout << "\n\n";

    std::cout << "Erase position 3\n";
    k.erase(3);
    k.print();
    std::cout << "\n\n";

    std::cout << "Remove value of i2\n";
    k.remove(i2);
    k.print();
    std::cout << "\n\n";

    std::cout << "Rotate right utilized\n";
    k.rotate_right(2); 
    k.print();
    }