#include <iostream>
#include "list.h"

using namespace std;

int main (int argc, char* const argv[]) {

    List ll;

    ll.insert(new Element(1));
    ll.insert(new Element(5));
    ll.insert(new Element(3));
    ll.insert(new Element(4));

    ll.show();

    cout << ll.remove(3)->toString() << endl << endl;

    cout << "Cleaning" << endl << endl;

    ll.show();
    ll.free();

    cout << "Cleaned" << endl;

    ll.show();

    return 0;

}
