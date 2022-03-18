#ifndef TREE_H
#define TREE_H
#include<iostream>
#include"Element.h"
//#include"level.h"

template<class T>
class Tree{
public:
    //Element<T> *_first;
    Tree(): _first(nullptr) {}
    Tree(const Tree<T> &source);
    ~Tree(){};
    void add(T value);
    bool isEmpty() const;
    bool isIn(T value, Element<T>*current) const;
    //void TODelete(Element<T>* toDelete = nullptr, T valueToDelete=0);
    Element<T>* remove(Element<T>*current, T value);
    //Element<T>* isIn(T value, Element<T>*current);
    void toDisp(int howToDoIt);
    void dispPreorder(Element<T>*current);
    void dispInorder(Element<T>*current);
    void dispPostorder(Element<T>*current);
    void setDepth(Element<T>*current);
    unsigned int minPath();
    unsigned int maxPath();   
    void shift(Element<T>*first, Element<T>* second);
    Element<T>* succesor(Element<T>* current);
    Element<T>* treeMinValue(Element<T>*current);
    Element<T>* getFirst(){return _first;};
    void SetFirst(Element<T>*current){ _first = current;};
protected:
    Element<T> *_first;
};

template<class T>
bool Tree<T>::isEmpty() const{
    return _first == nullptr;
}
template<class T>
void Tree<T>::add(T value){
    if(isEmpty()){
        _first = new Element<T>(value);
    }else{
    Element<T>* current =_first;
        while (current !=nullptr){
            if(value >= (current ->getValue())){
               if(current ->_left == nullptr){
                //   current ->_left = new Element<T>(value);
                //   current ->_left->_parent = current;
                    current -> setLeft(value);
                    current -> _left->setParent(current);
                    break;
               }
               else current = (current->_left);
            }else if(value < current->getValue()){
               if(current->_right==nullptr){
                //   current->_right = new Element<T>(value);
                //   current->_right->_parent = current;
                    current -> setRight(value);
                    current -> _right->setParent(current);
                    //std::cout<<"jestem pusty xd\n";
                   break;
               }
               else current = (current ->_right);
           }
       }
    }
}
/*
template<class T>
Element<T>* Tree<T>::isIn(T value, Element<T>*current){
    bool check = true;
    while (current and (current->getValue() != value)){
        if(current->getValue() == value) check = false;
        if(value < current->getValue()) current=current->_right;
        else current=current->_left;
    }
    if(check==false) return current;
    else return nullptr;
}
*/
template<class T>
bool Tree<T>::isIn(T value, Element<T>*current) const{
    while (current and (current->getValue() != value)){
        if(current->getValue() == value) return true;
        if(value < current->getValue()) current=current->_right;
        else current=current->_left;
    }
    return false;
}
template<class T>
Element<T>* Tree<T>::remove(Element<T>*current, T value){
    if(current == nullptr)
        return nullptr;
    if(current->_value < value)
        current->_left = remove(current->_left,value);
    else if(current->_value > value)
        current->_right = remove(current->_right,value);
    else{
        if(current->_left == nullptr && current->_right == nullptr){
            delete(current);
            return nullptr;
        }
        else if(current->_left == nullptr){
            Element<T> *temp = current->_right;
            delete(current);
            return temp;
        }
        else if(current->_right == nullptr){
            Element<T> *temp = current->_left;
            delete(current);
            return temp;
        }
        else{
            Element<T>* rightMin = treeMinValue(current->_left);
            current->_value = rightMin->_value;
            current->_left = remove(current->_left,rightMin->_value);
        }
    }
    return current;
}

template<class T>
Element<T>* Tree<T>::treeMinValue(Element<T>*current){
    while (current->_right != nullptr){
        current=current->_right;
    }
    return current;    
}

template<class T>
void Tree<T>::toDisp(int a){
    switch (a)
    {
    case 0:
        dispPreorder(_first);
        break;
    case 1:
        dispInorder(_first);
        break;
    case 2:
        dispPostorder(_first);
        break;
    default:
        break;
    }
}

template<class T>
void Tree<T>::dispPreorder(Element<T>*current){
    if(current){
        std::cout << current->getValue() << " ";
        dispPreorder(current -> _left);
        dispPreorder(current -> _right);
    }
}

template<class T>
void Tree<T>::dispInorder(Element<T>*current){
    if(current){
        dispInorder(current -> _left);
        std::cout << current->getValue() << " ";
        dispInorder(current -> _right);
    }
}

template<class T>
void Tree<T>::dispPostorder(Element<T>*current){
    if(current){
        dispPostorder(current -> _left);
        dispPostorder(current -> _right);
        std::cout << current->getValue() << " ";
    }
}

template<class T>
void Tree<T>::setDepth(Element<T> *current){
  // Element<T>*current = _first;
    if(current){
        if(current-> _left != nullptr){
            current->_left->_deepth = current->_deepth +1;
        }
        if(current->_right!= nullptr){
            current->_right->_deepth=current->_right->_deepth+1;
        }

        setDepth(current->_left);
        setDepth(current->_right);    
    }
    
    
}

template<class T>
unsigned int Tree<T>::minPath(){
    unsigned int minDepth = 4294967295;

    Element<T>*current = _first;
/*    if(current){
        if(current-> _left){
            current->_left->_deepth = current->_deepth +1;
        }
        if(current->_right){
            current->_right->_deepth=current->_right->_deepth+1;
        }
    }
*/
    setDepth(current);
    while (current)
    {
        /* code */
        if(!(current->_left == nullptr and current->_right==nullptr)){
            if(current->_deepth<minDepth){
                minDepth= current->_deepth;
            }
        }
        if(current->_left) current=current->_left;
        if(current->_right) current=current->_right;

    }
    return minDepth;
    
}

template<class T>
unsigned int Tree<T>::maxPath(){
    Element<T>*current = _first;
    unsigned int maxDepth = 0;
    setDepth(current);
    while (current != nullptr)
    {
        /* code */
        if(!(current->_left == nullptr and current->_right==nullptr)){
            if(current->_deepth > maxDepth){
                maxDepth= current->_deepth;
            }
        }
        if(current->_left) current=current->_left;
        if(current->_right) current=current->_right;

    }
    return maxDepth;
    

}



#endif