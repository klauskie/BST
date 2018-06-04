//
// Created by Klaus Kientzle on 7/18/17.
//

#include "Binary_ST.h"
#include <iostream>

using namespace std;

Binary_ST::Binary_ST() { //Implementacion del Constructor
    root = NULL;
}


Binary_ST::~Binary_ST(){ //Implementacion del Destructor
    borrarTodo(root);
    cout << "Destructor llamado!" << endl;
}

//Inserta Elemento
void Binary_ST::insert(int item, Node *node) {
    if(item < node->data){
        if(node->left == NULL){
            node->left = new Node(item);
        }
        else{
            insert((item), node->left);
        }
    }else if(item > node->data){
        if(node->right == NULL){
            node->right = new Node(item);
        }else{
            insert((item), node->right);
        }
    }
}

void Binary_ST::insert_helper(int item) {
    if(root == NULL){
        root = new Node(item);
    }else{//Calls the function from the class Node to insert an item
        insert(item, root);
    }
}

//Busca el elemento
bool Binary_ST::find(int item, Node* node) {
    if(root == NULL){
        cout << "El arbol esta vacio." <<endl;
        return false;
    }else{
        if(item == node->data){
            return true;
        }

        else{
            return (item < node->data) ? find(item,node->left) : find(item,node->right);
        }
    }
}

bool Binary_ST::find_Helper(int item) {
    return find(item, root);
}

//Ayuda para a la hora de llamar al metodo desde el main. Para pasarle la raiz dentro de la clase
void Binary_ST::preOrder_Helper(){
    preOrder(root);
    cout << endl;
}

//Recorre el arbol de modo PRE transvesal.
void Binary_ST::preOrder(Node* node){
    if(node == NULL){
        return;
    }else{
        cout << node->data << " | ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

//Ayuda para a la hora de llamar al metodo desde el main. Para pasarle la raiz dentro de la clase
void Binary_ST::inOrder_Helper(){
    inOrder(root);
    cout << endl;
}

//Recorre el arbol de modo IN transvesal.
void Binary_ST::inOrder(Node* node){
    if(node == NULL){
        return;
    }else{
        inOrder(node->left);
        cout << node->data << " | ";
        inOrder(node->right);
    }
}

//Ayuda para a la hora de llamar al metodo desde el main. Para pasarle la raiz dentro de la clase
void Binary_ST::posOrder_Helper(){
    posOrder(root);
    cout << endl;
}

//Recorre el arbol de modo POS transvesal.
void Binary_ST::posOrder(Node* node){
    if(node == NULL){
        return;
    }else{
        posOrder(node->left);
        posOrder(node->right);
        cout << node->data << " | ";
    }
}

//Ayuda para a la hora de llamar al metodo desde el main. Para pasarle la raiz dentro de la clase
void Binary_ST::mostrar_Helper(){
    mostrar(root,2);
    cout << endl;
}

//Display
void Binary_ST::mostrar(Node* node, int level){
    if(node != NULL){
        mostrar(node->right,level + 1);
        cout << endl;

        if(node == root){
            cout << "Root-> ";
        }else{
            for(int i = 0; i < level; i++){
                cout << "    ";
            }
        }

        cout << node->data;
        mostrar(node->left, level + 1);
    }
}

// Eliminar nodos
void Binary_ST::borrarTodo(Node* node) {
    if(node != NULL){
        borrarTodo(node->left);
        borrarTodo(node->right);
        delete node;
    }
}
