#include <iostream>
#include "Element.h"
#include "Tree.h"

using namespace std;

int main() {
    int M = 1;
    int m;
    Tree<double> tree;
    double data;
    double toDelete = 5.0;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> data;
        tree.add(data);
    }

    cout << "============================================================== \n";
    tree.display(M);
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> toDelete;
        try {
            while (!(tree.isIn(toDelete, tree.getFirst()))) {
                tree.setFirst(tree.remove(tree.getFirst(), toDelete));
            }
        } catch (const TreeException& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    cout << "\n ============================================================== \n";
    cin >> M;
    tree.display(M);
    cout << tree.maxDepth();

    return 0;
}
