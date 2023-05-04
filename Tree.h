#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <stdexcept>
#include "Element.h"

template <class T>
class Tree;

// Custom exception class for the Tree
class TreeException : public std::runtime_error {
public:
    explicit TreeException(const std::string& msg) : std::runtime_error(msg) {}
};

template <class T>
class Tree {
public:
    Tree() : _first(nullptr) {}
    Tree(const Tree<T>& source);
    ~Tree() { deleteTree(_first); };

    void add(T value);
    bool isEmpty() const;
    bool isIn(T value, Element<T>* current) const;
    Element<T>* remove(Element<T>* current, T value);
    void display(int displayMode);
    void displayPreorder(Element<T>* current);
    void displayInorder(Element<T>* current);
    void displayPostorder(Element<T>* current);
    void setDepth(Element<T>* current);
    unsigned int minDepth();
    unsigned int maxDepth();
    Element<T>* getFirst() { return _first; };
    void setFirst(Element<T>* current) { _first = current; };

protected:
    void deleteTree(Element<T>* current);
    Element<T>* _first;
};

// Other methods remain unchanged

template <class T>
void Tree<T>::add(T value) {
    if (isEmpty()) {
        _first = new Element<T>(value);
    } else {
        Element<T>* current = _first;
        while (current != nullptr) {
            if (value >= (current->getValue())) {
                if (current->_left == nullptr) {
                    current->setLeft(value);
                    current->_left->setParent(current);
                    break;
                } else {
                    current = (current->_left);
                }
            } else if (value < current->getValue()) {
                if (current->_right == nullptr) {
                    current->setRight(value);
                    current->_right->setParent(current);
                    break;
                } else {
                    current = (current->_right);
                }
            }
        }
    }
}

template <class T>
Element<T>* Tree<T>::remove(Element<T>* current, T value) {
    if (current == nullptr)
        throw TreeException("Element not found in the tree.");

    if (current->_value < value)
        current->_left = remove(current->_left, value);
    else if (current->_value > value)
        current->_right = remove(current->_right, value);
    else {
        if (current->_left == nullptr && current->_right == nullptr) {
            delete(current);
            return nullptr;
        } else if (current->_left == nullptr) {
            Element<T>* temp = current->_right;
            delete(current);
            return temp;
        } else if (current->_right == nullptr) {
            Element<T>* temp = current->_left;
            delete(current);
            return temp;
        } else {
            Element<T>* rightMin = treeMinValue(current->_left);
            current->_value = rightMin->_value;
            current->_left = remove(current->_left, rightMin->_value);
        }
    }
    return current;
}

// Rest of the methods remain unchanged

#endif
