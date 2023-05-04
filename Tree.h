#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <memory>
#include <stdexcept>
#include "Element.h"

class TreeException : public std::runtime_error {
public:
    explicit TreeException(const std::string& msg) : std::runtime_error(msg) {}
};


template <class T>
class Tree {
public:
    Tree() : _root(nullptr) {}

    void addElement(T value);
    bool isEmpty() const;
    bool contains(T value) const;
    void removeElement(T value);
    void display(int mode) const;
    unsigned int maxDepth() const;

private:
    std::shared_ptr<Element<T>> _root;

    void addElementHelper(const std::shared_ptr<Element<T>>& current, T value);
    bool containsHelper(const std::shared_ptr<Element<T>>& current, T value) const;
    std::shared_ptr<Element<T>> removeElementHelper(const std::shared_ptr<Element<T>>& current, T value);
    void displayPreorder(const std::shared_ptr<Element<T>>& current) const;
    void displayInorder(const std::shared_ptr<Element<T>>& current) const;
    void displayPostorder(const std::shared_ptr<Element<T>>& current) const;
    unsigned int maxDepthHelper(const std::shared_ptr<Element<T>>& current) const;
    std::shared_ptr<Element<T>> treeMinValue(const std::shared_ptr<Element<T>>& current) const;
    
};

template <class T>
void Tree<T>::addElement(T value) {
    if (isEmpty()) {
        _root = std::make_shared<Element<T>>(value);
    } else {
        addElementHelper(_root, value);
    }
}

template <class T>
void Tree<T>::addElementHelper(const std::shared_ptr<Element<T>>& current, T value) {
    if (value < current->getValue()) {
        if (current->_left == nullptr) {
            current->_left = std::make_shared<Element<T>>(value);
        } else {
            addElementHelper(current->_left, value);
        }
    } else {
        if (current->_right == nullptr) {
            current->_right = std::make_shared<Element<T>>(value);
        } else {
            addElementHelper(current->_right, value);
        }
    }
}

template<class T>
bool Tree<T>::isEmpty() const{
    return _root == nullptr;
}

template <class T>
bool Tree<T>::contains(T value) const {
    return containsHelper(_root, value);
}

template <class T>
bool Tree<T>::containsHelper(const std::shared_ptr<Element<T>>& current, T value) const {
    if (current == nullptr) {
        return false;
    }
    if (current->getValue() == value) {
        return true;
    } else if (value < current->getValue()) {
        return containsHelper(current->_left, value);
    } else {
        return containsHelper(current->_right, value);
    }
}

template <class T>
void Tree<T>::removeElement(T value) {
    _root = removeElementHelper(_root, value);
}

template <class T>
std::shared_ptr<Element<T>> Tree<T>::removeElementHelper(const std::shared_ptr<Element<T>>& current, T value) {
    if (current == nullptr) {
        return nullptr;
    }

    if (value < current->getValue()) {
        current->_left = removeElementHelper(current->_left, value);
    } else if (value > current->getValue()) {
        current->_right = removeElementHelper(current->_right, value);
    } else {
        if (current->_left == nullptr && current->_right == nullptr) {
            return nullptr;
        } else if (current->_left == nullptr) {
            return current->_right;
        } else if (current->_right == nullptr) {
            return current->_left;
        } else {
            std::shared_ptr<Element<T>> minValueNode = treeMinValue(current->_right);
            current->setValue(minValueNode->getValue());
            current->_right = removeElementHelper(current->_right, minValueNode->getValue());
        }
    }
    return current;
}

template <class T>
void Tree<T>::display(int mode) const {
    switch (mode) {
        case 0:
            displayPreorder(_root);
            break;
        case 1:
            displayInorder(_root);
            break;
        case 2:
            displayPostorder(_root);
            break;
        default:
            std::cout << "Invalid mode" << std::endl;
            break;
    }
}

template <class T>
void Tree<T>::displayPreorder(const std::shared_ptr<Element<T>>& current) const {
    if (current) {
        std::cout << current->getValue() << " ";
        displayPreorder(current->_left);
        displayPreorder(current->_right);
    }
}

template <class T>
void Tree<T>::displayInorder(const std::shared_ptr<Element<T>>& current) const {
    if (current) {
        displayInorder(current->_left);
        std::cout << current->getValue() << " ";
        displayInorder(current->_right);
    }
}

template <class T>
void Tree<T>::displayPostorder(const std::shared_ptr<Element<T>>& current) const {
    if (current) {
        displayPostorder(current->_left);
        displayPostorder(current->_right);
        std::cout << current->getValue() << " ";
    }
}

template <class T>
unsigned int Tree<T>::maxDepth() const {
    return maxDepthHelper(_root);
}

template <class T>
unsigned int Tree<T>::maxDepthHelper(const std::shared_ptr<Element<T>>& current) const {
    if (current == nullptr) {
        return 0;
    }

    unsigned int leftDepth = maxDepthHelper(current->_left);
    unsigned int rightDepth = maxDepthHelper(current->_right);

    return std::max(leftDepth, rightDepth) + 1;
}

template <class T>
std::shared_ptr<Element<T>> Tree<T>::treeMinValue(const std::shared_ptr<Element<T>>& current) const {
    std::shared_ptr<Element<T>> minValueNode = current;
    while (minValueNode && minValueNode->_left != nullptr) {
        minValueNode = minValueNode->_left;
    }
    return minValueNode;
}
#endif
