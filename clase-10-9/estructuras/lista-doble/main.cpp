#include <iostream>
#include "list.h"

using namespace std;

int main (int argc, char* const argv[]) {

    List ld;

    ld.insert(new Element(1));
    ld.insert(new Element(5));
    ld.insert(new Element(3));
    ld.insert(new Element(7));
    ld.insert(new Element(2));
    ld.insert(new Element(11));
    ld.insert(new Element(32));
    ld.insert(new Element(4));

    ld.show();

    cout << ld.remove(3)->toString() << endl << endl;

    cout << "Cleaning" << endl << endl;

    ld.show();
    ld.free();

    cout << "Cleaned" << endl;

    ld.show();

    return 0;

}
