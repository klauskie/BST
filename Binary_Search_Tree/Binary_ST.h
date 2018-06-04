//
// Created by Klaus Kientzle on 7/18/17.
//

#ifndef BST_BINARY_ST_H
#define BST_BINARY_ST_H

#include "Node.h"



class Binary_ST {
public:
    Node* root;

    Binary_ST(); //Constructor

    ~Binary_ST(); //Destructor

    void insert_helper(int item);

    bool find_Helper(int item);

    void preOrder_Helper();

    void inOrder_Helper();

    void posOrder_Helper();

    void mostrar_Helper();



private:
    void borrarTodo(Node* node);

    void preOrder(Node* node);

    void inOrder(Node* node);

    void posOrder(Node* node);

    void mostrar(Node* node, int level);

    void insert(int item, Node* node);

    bool find(int item, Node* node);

};


#endif //BST_BINARY_ST_H
