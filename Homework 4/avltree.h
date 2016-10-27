//
//  avltree.h
//  Hw4
//
//  Created by Corey Henry on 7/15/15.
//  Copyright (c) 2015 Corey Henry. All rights reserved.
//

#ifndef Hw4_avltree_h
#define Hw4_avltree_h


#endif
//forward decleration
template <typename T> class avl_tree;




// Node class
template <typename T>
class Node
{
    // A friend declaration allows acl_tree class to access the Node's private data
    friend class avl_tree<T>;
    
public:
    Node(const T& data, Node* left = nullptr, Node* right = nullptr);
    
    
private:
    T _data;
    Node* left;
    Node* right;
    int balance;
};



template <typename T>
class avl_tree
{
public:
    avl_tree(const T&data) : data(data), left(nullptr), right(nullptr)
    {}
    
    avl_tree(const avl_tree<T>& copy) : left(nullptr), right(nullptr)
    {}
    
    ~avl_tree()// deconstructor
    {
        if(left)
            delete left;
        if(right)
            delete right;
    }
    
    avl_tree& operator=(const avl_tree* rhs)
    {
    if(this != &rhs)// not same already
    {
        if(left)
            delete left;
        if(right)
            delete right;
        left = nullptr;
        right = nullptr;
        
        data = rhs->data;
        if(rhs->left)
            left = new avl_tree(rhs->left);
        if(rhs->right)
            right = new avl_tree(rhs->right);
    }// end if statement
        return *this;
    }
    
    
    // allows tree to be changed
    
    
    avl_tree* getRoot()// gets the parent
    {
        return root;
    }
    
    /// add new data
    void appendLeft(const T& data)
    {
        left = new avl_tree(data);
    }
    
    void appendRight(const T& data)
    {
        right = new avl_tree(data);
    }

    T Insert(const T& data)// insert function
    {
    
    }
    T find()//find function
    {
        
    }
    find(const T&) const
    
    insert(const T&)
    
    
    void rotateleft( T&)
    
    void rotateright( T&)
    
    
    
private:
    avl_tree<T>* root;
    
};