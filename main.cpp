#include <iostream>
#include "Element.h"
#include "Tree.h"

using namespace std;

// Print the menu options
void printMenu() {
    cout << "====================== Menu ======================" << endl;
    cout << "1. Add elements to the tree" << endl;
    cout << "2. Remove elements from the tree" << endl;
    cout << "3. Display tree" << endl;
    cout << "4. Show max depth" << endl;
    cout << "0. Exit" << endl;
    cout << "===================================================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    Tree<double> tree;

    // Main loop for menu
    do {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int numElements;
                double data;
                cout << "Enter the number of elements to add: ";
                cin >> numElements;
                for (int i = 0; i < numElements; i++) {
                    cout << "Enter element " << (i + 1) << ": ";
                    cin >> data;
                    tree.addElement(data);
                }
                break;
            }
            case 2: {
                int numElements;
                double toDelete;
                cout << "Enter the number of elements to remove: ";
                cin >> numElements;
                for (int i = 0; i < numElements; i++) {
                    cout << "Enter element " << (i + 1) << " to remove: ";
                    cin >> toDelete;
                    try {
                        if (tree.contains(toDelete)) {
                            tree.removeElement(toDelete);
                        } else {
                            cout << "Element not found in the tree." << endl;
                        }
                    } catch (const TreeException& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                }
                break;
            }
            case 3: {
                int displayMode;
                cout << "Select display mode (0: Preorder, 1: Inorder, 2: Postorder): ";
                cin >> displayMode;
                tree.display(displayMode);
                cout << endl;
                break;
            }
            case 4: {
                cout << "Max depth: " << tree.maxDepth() << endl;
                break;
            }
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
