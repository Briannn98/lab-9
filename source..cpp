#include <iostream>
#include "list.cpp"

using namespace std;

int main() {

    List myNumbers;

    myNumbers.addBack(10);
    myNumbers.addBack(20);
    myNumbers.addFront(5);

    cout << "Forward: ";
    myNumbers.showForward();

    cout << "Backward: ";
    myNumbers.showBackward();

    myNumbers.deleteValue(10);

    cout << "After deleting 10: ";
    myNumbers.showForward();

    return 0;
}