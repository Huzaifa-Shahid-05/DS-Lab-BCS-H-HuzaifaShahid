#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string songName;
    int playCount;
    Node* left;
    Node* right;

    Node(string n, int c) : songName(n), playCount(c), left(nullptr), right(nullptr) {}
};

class MusicApp {
private:
    int songCount = 0;

public:
    Node* root;

    MusicApp() {
        root = nullptr;
    }

    Node* createSong(string n, int c) {
        songCount++;
        return new Node(n, c);
    }

    void insertSong(string n, int c) {
        Node* p = createSong(n, c);
        if (!root) {
            root = p;
            cout << "Added first song: " << n << " (Play Count: " << c << ")" << endl;
            return;
        }

        Node* it = root;
        while (it) {
            if (c < it->playCount) {
                if (!it->left) {
                    it->left = p;
                    cout << "Inserted song: " << n << " (Play Count: " << c << ")" << endl;
                    return;
                }
                it = it->left;
            } else if (c > it->playCount) {
                if (!it->right) {
                    it->right = p;
                    cout << "Inserted song: " << n << " (Play Count: " << c << ")" << endl;
                    return;
                }
                it = it->right;
            } else {
                cout << "Cannot insert duplicate play count: " << c << endl;
                delete p;
                songCount--;
                return;
            }
        }
    }

    void searchSong(Node* root, int c) {
        if (!root) {
            cout << "No song found with play count " << c << endl;
            return;
        }
        if (root->playCount == c) {
            cout << "Song found: " << root->songName << " (" << c << ")" << endl;
            return;
        }
        if (c < root->playCount)
            searchSong(root->left, c);
        else
            searchSong(root->right, c);
    }

    void InOrder(Node* root) {
        if (root) {
            InOrder(root->left);
            cout << root->songName << " (Play Count: " << root->playCount << ")" << endl;
            InOrder(root->right);
        }
    }

    void PostOrder(Node* root) {
        if (root) {
            PostOrder(root->left);
            PostOrder(root->right);
            cout << root->songName << " (Play Count: " << root->playCount << ")" << endl;
        }
    }

    Node* deleteSong(Node* root, int c) {
        if (!root) {
            cout << "No song found with play count " << c << " to delete." << endl;
            return nullptr;
        }

        if (c < root->playCount)
            root->left = deleteSong(root->left, c);
        else if (c > root->playCount)
            root->right = deleteSong(root->right, c);
        else {
            if (!root->left && !root->right) {
                delete root;
                songCount--;
                return nullptr;
            } else if (!root->left) {
                Node* temp = root->right;
                delete root;
                songCount--;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                songCount--;
                return temp;
            } else {
                Node* successor = root->right;
                while (successor->left)
                    successor = successor->left;

                root->songName = successor->songName;
                root->playCount = successor->playCount;
                root->right = deleteSong(root->right, successor->playCount);
            }
        }
        return root;
    }

    Node* findMin(Node* root) {
        while (root && root->left)
            root = root->left;
        return root;
    }

    Node* findMax(Node* root) {
        while (root && root->right)
            root = root->right;
        return root;
    }

    void displayStats() {
        cout << endl << "------ Playlist Statistics ------" << endl;
        cout << "Total Songs: " << songCount << endl;

        if (root) {
            Node* leastPlayed = findMin(root);
            Node* mostPlayed = findMax(root);
            cout << "Most Played Song: " << mostPlayed->songName << " (" << mostPlayed->playCount << " plays)" << endl;
            cout << "Least Played Song: " << leastPlayed->songName << " (" << leastPlayed->playCount << " plays)" << endl;
        }
    }
};

int main() {
    cout << "=========================================" << endl;
    cout << "          MUSIC PLAYLIST APP             " << endl;
    cout << "=========================================" << endl << endl;

    MusicApp app;

    // Adding songs automatically (non-menu)
    cout << "Adding songs to playlist..." << endl;
    app.insertSong("Shape of You", 100);
    app.insertSong("Levitating", 90);
    app.insertSong("Birds of a Feather", 150);
    app.insertSong("Despacito", 200);
    app.insertSong("Perfect", 120);

    cout << endl;
    cout << "Songs (InOrder - Sorted by Play Count):" << endl;
    app.InOrder(app.root);

    cout << endl;
    cout << "Songs (PostOrder - Displayed in Deletion Order):" << endl;
    app.PostOrder(app.root);

    cout << endl;
    cout << "Searching for song with play count 120..." << endl;
    app.searchSong(app.root, 120);

    cout << endl;
    cout << "Deleting song with play count 90..." << endl;
    app.root = app.deleteSong(app.root, 90);

    cout << endl;
    cout << "Updated Songs (InOrder):" << endl;
    app.InOrder(app.root);

    app.displayStats();
}
