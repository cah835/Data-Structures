//
//  avltree.cpp
//  Hw4
//
//  Created by Corey Henry on 7/15/15.
//  Copyright (c) 2015 Corey Henry. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include "avltree.h"


using std::cin;
using std::getline;
using std::cout;
using std::endl;
using std::string;
using std::locale;
using std::tolower;



template<typename T>
int avl_tree<T>::checkBalance()//function for ballance
{
    int balance = 0;// initialize balance at 0
    if(getLeft())// if there is a left add 1
        balance += 1;
    if(getRight())// if there is a right minus 1
        balance -= 1;
    return balance;
}

template<typename T>
bool avl_tree<T>::insert(const T& data)
{
    if(root == nullptr)
        new node* =data
    if(data < root)
        root.getLeft(insert(const T& data))
        if(data > root)
            root.getright(insert(const T& data))
}

template<typename T>
bool avl_tree<T>::find(const T&) const

template<typename T>
Node<T>::Node(const T& data, Node* left, Node* right)

{
    this->_data = data;
    this-> left = left;
    this->right = right;
}

void avl_tree<T>::RotateLeft(Node* &root)
{
    Node *p// point to the root of the right subtree
    if(root == NULL)
        cout << "error in the tree" << endl;
    else if(root-> right == NULL)
        cout << "no right subtree to rotate" << endl;
    else
    {
        p = root-> right;
        root->right = p->left;// the left subtree of p becomes the right subtree of the root
        p->left = root;
        root = p; // make p the new root node
    }
}// this rotates left, constructed from the book example pg 645

void avl_tree<T>::RotateRight(Node* &root)
{
    Node *p// point to the root of the left subtree
    if(root == NULL)
        cout << "error in the tree" << endl;
    else if(root-> left == NULL)
        cout << "no right subtree to rotate" << endl;
    else
    {
        p = root-> left;
        root->right = p->right;// the right subtree of p becomes the left subtree of the root
        p->right = root;
        root = p; // make p the new root node
}// this rotates to the right, constructed from the book exaplme pg 645
