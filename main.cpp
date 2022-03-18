#include<iostream>
#include"Element.h"
#include"Tree.h"
//#include"level.h"

using namespace std;

int main(){
    int M =1;    
    int m;
    Tree<double> tree;
    double data;
    double toDelet=5.0;
    cin >>m;
    for(int i =0; i < m; i++){
        cin >> data;
        tree.add(data);
    }

    cout <<"============================================================== \n";
    tree.toDisp(M);
    cin >> m;
    for(int i = 0; i < m; i ++){
        cin >> toDelet;
        while(!(tree.isIn(toDelet, tree.getFirst()))){
            tree.SetFirst(tree.remove(tree.getFirst(), toDelet));
        }    
    }    
    cout <<"\n ============================================================== \n";
    cin >> M;
    tree.toDisp(M);
    cout << tree.maxPath();// << " "
//    cout  <<tree.minPath();

    return 0;
}