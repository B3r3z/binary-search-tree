#ifndef ELEMENT_H
#define ELEMENT_H
#include<iostream>

template<class T>
class Tree;

template<class T>
class Element {
public:
    Element(T valueIn, Element<T>* leftChild = nullptr, Element<T>* rightChild = nullptr, Element<T>* parent = nullptr)
        : _value(valueIn), _left(leftChild), _right(rightChild), _parent(parent), _depth(0) {};

    T getValue() const { return _value; };
    void setLeft(T value);
    void setRight(T value);
    void setParent(Element* point);
    ~Element() {};
    Element<T> getLeft();
    Element<T> getRight();
    Element<T> getParent();
    T minValue();
    void setValue(T value);

private:
    T _value;
    Element<T>* _parent;
    Element<T>* _left;
    Element<T>* _right;
    unsigned int _depth;
    friend class Tree<T>;
};

template<class T>
void Element<T>::setLeft(T value) {
    _left = new Element<T>(value);
}

template<class T>
void Element<T>::setRight(T value) {
    _right = new Element<T>(value);
}

template<class T>
void Element<T>::setParent(Element<T>* point) {
    _parent = point;
}

template<class T>
T Element<T>::minValue() {
    if (_left == nullptr) return _value;
    else return _left->minValue();
}

#endif
