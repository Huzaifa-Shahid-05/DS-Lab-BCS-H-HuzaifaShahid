#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

class Node {
public:
    string name;
    Node* mother; 
    Node* father; 

    Node(string n) : name(n), mother(nullptr), father(nullptr) {}

    void getParents() {
        string n;
        cout << "Enter mother's name for " << name << " ('u' if not known): ";
        getline(cin, n);
        if (n != "u" && !n.empty()) {
            mother = new Node(n);
            mother->getParents();
        }

        cout << "Enter father's name for " << name << " ('u' if not known): ";
        getline(cin, n);
        if (n != "u" && !n.empty()) {
            father = new Node(n);
            father->getParents();
        }
    }
};

class FamilyAncestry {
public:
    Node* root;

    FamilyAncestry(string name) {
        root = new Node(name);
        cout << endl;
        cout << "--- Enter parental information ---" << endl;
        root->getParents();
    }

    void printLeafNodes(Node* root) {
        if (!root) return;
        if (!root->mother && !root->father) {
            cout << root->name << endl;
            return;
        }
        printLeafNodes(root->mother);
        printLeafNodes(root->father);
    }

    int getHeight(Node* root) {
        if (!root) return 0;
        int left = getHeight(root->mother);
        int right = getHeight(root->father);
        return 1 + max(left, right);
    }

    void printLevelMember(Node* root) {
        if (!root) return;
        int level = 0;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            cout << "Generation " << level << ": ";
            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();
                cout << current->name << " ";
                if (current->mother) q.push(current->mother);
                if (current->father) q.push(current->father);
            }
            cout << endl;
            level++;
        }
    }

    void deleteTree(Node* root) {
        if (!root) return;
        deleteTree(root->mother);
        deleteTree(root->father);
        delete root;
    }

    void displayInfo() {
        cout << endl;
        cout << "--- Family Ancestry Information ---" << endl;
        cout << "Youngest person (root): " << root->name << endl << endl;

        cout << "Ancestors with no known parents:" << endl;
        printLeafNodes(root);
        cout << endl;

        cout << "Family tree height: " << getHeight(root) << endl << endl;

        cout << "Family members by generation: " << endl;
        printLevelMember(root);
    }

    ~FamilyAncestry() {
        deleteTree(root);
    }
};

int main() {
    string name;
    cout << "Enter the youngest person's name: ";
    getline(cin, name);

    FamilyAncestry tree(name);
    tree.displayInfo();

    return 0;
}
