#include <iostream>
#include "queue.h"

using namespace std;

int main (int argc, char* const argv[]) {

    Queue qu;

    qu.qstore(new Element("Juan", "Diaz"));
    qu.qstore(new Element("Jorge", "Garcia"));
    qu.qstore(new Element("Josefina", "Lopez"));

    qu.show();

    cout << qu.qretrieve()->toString() << endl << endl;

    cout << "Cleaning" << endl << endl;

    qu.show();
    qu.free();

    cout << "Cleaned" << endl;

    qu.show();

    return 0;

}
