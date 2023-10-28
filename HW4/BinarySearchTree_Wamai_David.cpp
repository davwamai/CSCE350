#include <iostream>  // For in and out
#include <vector>  // For structure containers
#include <sstream>  // Convienient CLI line parsing
#include <limits>  // For numeric limits
using namespace std;

// Structure for nodes
struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Class to define building and operating on the tree
class BST {
 public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insert_sub(root, val);
    }

    vector<int> search(int val) {
        vector<int> path;
        search_sub(root, val, path);
        return path;
    }

    void remove(int val) {
        root = remove_sub(root, val);
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
        display_sub(root);
        cout << "\n";
    }

    void trace(vector<int> path) {
      for (int p : path) {
       cout << p << " -> ";
      }
      cout << " search key not found\n";
    }


 private:
    Node* root;

    // Handles root, recursively calls itself to determine left or right node placement
    Node* insert_sub(Node* node, int val) {
        if (!node) return new Node(val);
        if (val == node-> value) {
          cout << val << " is a duplicate value, cannot add" << endl;
        }
        else if (val < node-> value) node->left = insert_sub(node->left, val);
        else node-> right = insert_sub(node->right, val);

        return node;
      }

    // If node deosnt exist, return a null address. Otherwise, recursively call self to determine traveral direction
    Node* search_sub(Node* node, int val, vector<int>& path) {
        if (!node) return nullptr;
        path.push_back(node->value);
        if (val == node->value) return node;
        if (val < node->value) return search_sub(node->left, val, path);
        return search_sub(node->right, val, path);
    }

    // Traverses to target node and replaces deleted node w tmep
    // TODO: handle two children
    Node* remove_sub(Node* node, int val) {
        if (!node) return nullptr;
        if (val < node->value) node->left = remove_sub(node->left, val);
        else if (val > node->value) node->right = remove_sub(node->right, val);
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
            node->right = remove_sub(node->right, node->value);
        }
        return node;
    }

    // Goes left for smallest
    int findSmallestValue(Node* node) {
        while (node->left) node = node->left;
        return node->value;
    }

    void display_sub(Node* node) {
        if (!node) return;
        display_sub(node->left);
        cout << node->value << " ";
        display_sub(node->right);
    }
};

int main() {
    BST tree;
    int choice, val;
    string line;

    do {
        cout << "1. Insert node\n2. Search for node\n3. Delete node\n4. Find smallest node\n5. Find largest node\n6. Display tree\n0. Exit\n";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                cout << "Enter values to insert (delimited by spaces): ";
                getline(cin, line);
                {  // Note: first entry is always root.
                    istringstream iss(line);
                    while (iss >> val) {
                        tree.insert(val);
                    }
                }
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
                    tree.trace(path);
                }
                break;
            case 3:
                cout << "Enter values to delete (delimited by spaces): ";
                getline(cin, line);
                {
                    istringstream iss(line);
                    while (iss >> val) {
                        tree.remove(val);
                    }
                }
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
