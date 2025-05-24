#ifndef ELEMENT_H
#define ELEMENT_H
#include<iostream>
#include <memory>

template<class T>
class Tree;

template<class T>
class Element{
    public:
    Element(T valueIn, std::shared_ptr<Element<T>> leftChild = nullptr, std::shared_ptr<Element<T>> rightChild = nullptr, std::shared_ptr<Element<T>> parent = nullptr)
    : _value(valueIn), _right(rightChild) , _left(leftChild), _parent(parent){};
    T getValue() const{return _value;};
    void setParent(std::shared_ptr<Element<T>> point);
    ~Element(){};
    std::shared_ptr<Element<T>> getLeft();
    std::shared_ptr<Element<T>> getRight();
    std::shared_ptr<Element<T>> getParent();
    T minValue();
    void setValue(T value);
    private:
    T _value;
    std::shared_ptr<Element<T>> _parent;
    std::shared_ptr<Element<T>> _left;
    std::shared_ptr<Element<T>> _right;
    friend class Tree<T>;
};

template<class T>
void Element<T>::setParent(std::shared_ptr<Element<T>> point){
    _parent=point;
}

template<class T>
T Element<T>::minValue(){
    if(_left == nullptr) return _value;
    else return _left->minValue();
}

template<class T>
void Element<T>:: setValue(T value){
    _value = value;
}

#endif
