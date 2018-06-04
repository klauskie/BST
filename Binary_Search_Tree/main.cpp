#include <iostream>
#include "Binary_ST.h"

//using namespace std;

int main() {

    Binary_ST arbol;

    arbol.insert_helper(2);
    arbol.insert_helper(3);
    arbol.insert_helper(1);
    arbol.insert_helper(4);

    std::cout << "Buscar 2: "<<arbol.find_Helper(2)<< std::endl;

    arbol.preOrder_Helper();
    arbol.inOrder_Helper();
    arbol.posOrder_Helper();

    arbol.mostrar_Helper();

    return 0;
}