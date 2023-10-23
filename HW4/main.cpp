#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insertRec(root, val);
    }

    vector<int> search(int val) {
        vector<int> path;
        searchRec(root, val, path);
        return path;
    }

    void remove(int val) {
        root = removeRec(root, val);
    }

    int findSmallest() {
        if (!root) throw runtime_error("BST is empty");
        Node* current = root;
        while (current->left) current = current->left;
        return current->value;
    }

    int findLargest() {
        if (!root) throw runtime_error("BST is empty");
        Node* current = root;
        while (current->right) current = current->right;
        return current->value;
    }

    void display() {
        displayRec(root);
        cout << "\n";
    }

private:
    Node* root;

    Node* insertRec(Node* node, int val) {
        if (!node) return new Node(val);
        if (val <= node->value) node->left = insertRec(node->left, val);
        else node->right = insertRec(node->right, val);
        return node;
    }

    Node* searchRec(Node* node, int val, vector<int>& path) {
        if (!node) return nullptr;
        path.push_back(node->value);
        if (val == node->value) return node;
        if (val < node->value) return searchRec(node->left, val, path);
        return searchRec(node->right, val, path);
    }

    Node* removeRec(Node* node, int val) {
        if (!node) return nullptr;
        if (val < node->value) node->left = removeRec(node->left, val);
        else if (val > node->value) node->right = removeRec(node->right, val);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            node->value = findSmallestValue(node->right);
            node->right = removeRec(node->right, node->value);
        }
        return node;
    }

    int findSmallestValue(Node* node) {
        while (node->left) node = node->left;
        return node->value;
    }

    void displayRec(Node* node) {
        if (!node) return;
        displayRec(node->left);
        cout << node->value << " ";
        displayRec(node->right);
    }
};

int main() {
    BST tree;
    int choice, val;

    do {
        cout << "1. Insert\n2. Search\n3. Delete\n4. Find smallest\n5. Find largest\n6. Display\n0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                tree.insert(val);
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> val;
                {
                    vector<int> path = tree.search(val);
                    if (path.empty() || path.back() != val) {
                        cout << "Search unsuccessful. Path traversed: ";
                    } else {
                        cout << "Search successful. Path traversed: ";
                    }
                    for (int p : path) {
                        cout << p << " ";
                    }
                    cout << "\n";
                }
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> val;
                tree.remove(val);
                break;
            case 4:
                try {
                    cout << "Smallest value: " << tree.findSmallest() << "\n";
                } catch (const exception& e) {
                    cout << e.what() << "\n";
                }
                break;
            case 5:
                try {
                    cout << "Largest value: " << tree.findLargest() << "\n";
                } catch (const exception& e) {
                    cout << e.what() << "\n";
                }
                break;
            case 6:
                cout << "Tree: ";
                tree.display();
                break;
        }
    } while (choice != 0);

    return 0;
}

