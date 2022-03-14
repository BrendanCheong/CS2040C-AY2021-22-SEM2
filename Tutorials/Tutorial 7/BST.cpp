#include <bits/stdc++.h>
using namespace std;

// Every vertex in this BST is a C Struct (to expose all its members publicly)
struct BSTVertex {
    // all these attributes remain public to slightly simplify the code although this may not be the best practice
    // BSTVertex* parent; // now removed, all code below thus becomes simpler by a bit
    BSTVertex* left;
    BSTVertex* right;
    int key;
    int freq_of_key
        int height; // will be used in AVL lecture
};

// This is just a sample implementation
// There are other ways to implement BST concepts...
template <typename T1>
class BST {
protected:
    BSTVertex* root;

    BSTVertex* insert(BSTVertex* T, T1 v) {
        if (T == NULL) {                             // insertion point is found
            T = new BSTVertex;
            T->key = v;
            // T->parent = 
            T->left = T->right = NULL;
            T->height = 0;                             // used in AVL lecture
        }
        else if (T->key < v)                         // search to the right
            T->right = insert(T->right, v);
        // T->right->parent = T;
        else                                         // search to the left
            T->left = insert(T->left, v);
        // T->left->parent = T;
        return T;                                    // return the updated BST
    }

    void inorder(BSTVertex* T) {
        if (T == NULL) return;
        inorder(T->left);                            // recursively go to the left
        cout << ' ' << T->key;                       // visit this BST node
        inorder(T->right);                           // recursively go to the right
    }

    void preorder(BSTVertex* T) {
        if (T == NULL) return;
        cout << ' ' << T->key;                       // visit this BST node
        preorder(T->left);                           // recursively go to the left
        preorder(T->right);                          // recursively go to the right
    }

    T1 findMin(BSTVertex* T) {
        if (T == NULL)       return -1;         // BST is empty, no minimum
        else if (T->left == NULL) return T->key;     // this is the min
        else                      return findMin(T->left); // go to the left
    }

    T1 findMax(BSTVertex* T) {
        if (T == NULL)        return -1;        // BST is empty, no maximum
        else if (T->right == NULL) return T->key;    // this is the max
        else                       return findMax(T->right); // go to the right
    }

    BSTVertex* search(BSTVertex* T, T1 v) {
        if (T == NULL)   return NULL;           // not found
        else if (T->key == v) return T;              // found
        else if (T->key < v)  return search(T->right, v); // search to the right
        else                  return search(T->left, v); // search to the left
    }

    T1 successor(BSTVertex* T) {                   //! find the successor of T->key, essentially its upper_bound(e)
        if (T->right != NULL)                        // we have right subtree
            return findMin(T->right);                  // this is the successor
        else {
            // the one explained in VisuAlgo animation
            // BSTVertex* par = T->parent;
            // BSTVertex* cur = T;
            // // if par(ent) is not root and cur(rent) is its right children
            // while ((par != NULL) && (cur == par->right)) {
            //   cur = par;                            // continue moving up
            //   par = cur->parent;
            // }
            // return par == NULL ? -1 : par->key;     // this is the successor of T

            // the alternative implementation that does NOT use parent pointers
            BSTVertex* succ = NULL;
            BSTVertex* cur = root;                     // start from the root
            while ((cur != NULL) && (cur != T)) {      // search for T
                if (T->key < cur->key) {
                    succ = cur;                            // candidate successor
                    cur = cur->left;                       // go left
                }
                else
                    cur = cur->right;                      // go right
            }
            return succ == NULL ? -1 : succ->key;
        }
    }

    T1 predecessor(BSTVertex* T) {                 // !find the predecessor of T->key, essentially its lower_bound(e)
        if (T->left != NULL)                         // we have left subtree
            return findMax(T->left);                   // this is the predecessor
        else {
            // the one explained in VisuAlgo animation
            // BSTVertex* par = T->parent;
            // BSTVertex* cur = T;
            // // if par(ent) is not root and cur(rent) is its left children
            // while ((par != NULL) && (cur == par->left)) { 
            //   cur = par;                            // continue moving up
            //   par = cur->parent;
            // }
            // return par == NULL ? -1 : par->key;     // this is the successor of T

            // the alternative implementation that does NOT use parent pointers
            BSTVertex* pred = NULL;
            BSTVertex* cur = root;                     // start from the root
            while ((cur != NULL) && (cur != T)) {      // search for T
                if (T->key < cur->key)
                    cur = cur->left;                       // go left
                else {
                    pred = cur;                            // candidate predecessor
                    cur = cur->right;                      // go right
                }
            }
            return pred == NULL ? -1 : pred->key;
        }
    }

    BSTVertex* remove(BSTVertex* T, T1 v) {
        if (T == NULL) return NULL;                  // cannot find the item

        if (T->key == v) {                           // the node to be deleted
            if ((T->left == NULL) && (T->right == NULL)) { // this is a leaf
                delete T;
                T = NULL;                                // simply erase this node
            }
            else if ((T->left == NULL) && (T->right != NULL)) // only one child at right
              // T->right->parent = T->parent;         // ma, take care of my child
                T = T->right;                            // bypass T
            else if ((T->left != NULL) && (T->right == NULL)) // only one child at left
              // T->left->parent = T->parent;          // ma, take care of my child
                T = T->left;                             // bypass T
            else { // has two children, find the successor of v to avoid quarrel
                int successorV = successor(v);           // predecessor is also OK btw
                T->key = successorV;                     // replace with successorV
                T->right = remove(T->right, successorV); // delete the old successorV
            }
        }
        else if (T->key < v)                         // search to the right
            T->right = remove(T->right, v);
        else                                         // search to the left
            T->left = remove(T->left, v);
        return T;                                    // return the updated BST
    }

    // will be used in AVL lecture
    int getHeight(BSTVertex* T) {
        if (T == NULL) return -1;
        else return max(getHeight(T->left), getHeight(T->right)) + 1;
    }

public:
    BST() { root = NULL; }

    void insert(int v) { root = insert(root, v); }

    void inorder() { inorder(root); cout << '\n'; }

    void preorder() { preorder(root); cout << '\n'; }

    int findMin() { return findMin(root); }

    int findMax() { return findMax(root); }

    int search(T1 v) {
        BSTVertex* res = search(root, v);
        return res == NULL ? -1 : res->key;
    }

    int successor(T1 v) {
        BSTVertex* vPos = search(root, v);
        return vPos == NULL ? -1 : successor(vPos);
    }

    int predecessor(T1 v) {
        BSTVertex* vPos = search(root, v);
        return vPos == NULL ? -1 : predecessor(vPos);
    }

    void remove(T1 v) { root = remove(root, v); }

    int getHeight() { return getHeight(root); } // will be used in AVL lecture
};

// IMPORTANT: comment this int main() if you want to run AVLDemo.cpp (that inherits BST class above)

int main() {
    cout << "Our own Binary Search Tree (NOT NECESSARILY BALANCED)\n";
    BST<int> T;                                    // an empty BST

    cout << T.findMin() << '\n';                   // not found, -1
    cout << T.findMax() << '\n';                   // not found, -1

    // Sample BST as shown in Lecture, the keys are inserted in 'random' order
    T.insert(15);
    T.insert(23);
    T.insert(6);
    T.insert(71);
    T.insert(50);
    T.insert(4);
    T.insert(7);
    T.insert(5);

    cout << T.findMin() << '\n';                  // 4
    cout << T.findMax() << '\n';                  // 71

    cout << T.search(71) << '\n';                 // found, 71
    cout << T.search(7) << '\n';                  // found, 7
    cout << T.search(22) << '\n';                 // not found, -1

    T.inorder();                                  // 4, 5, 6, 7, 15, 23, 50, 71
    cout << T.successor(23) << '\n';              // 50
    cout << T.successor(4) << '\n';               // 5
    cout << T.successor(71) << '\n';              // -1
    cout << T.predecessor(23) << '\n';            // 15
    cout << T.predecessor(4) << '\n';             // -1
    cout << T.predecessor(71) << '\n';            // 50

    cout << T.getHeight() << '\n';                // 3
    T.preorder();                                 // 15, 6, 4, 5, 7, 23, 71, 50

    cout << "Removing 5\n";
    T.remove(5);
    cout << "Removing 71\n";
    T.remove(71);
    cout << "Removing 15\n";
    T.remove(15);

    T.inorder();                                  // 4, 6, 7, 23, 50
    cout << T.getHeight() << '\n';                // 2
    T.preorder();                                 // 23, 6, 4, 7, 50

    cout << "C++ STL version\n";
    set<int> T_stl;

    cout << (T_stl.empty() ? -1 : *T_stl.begin()) << '\n';  // not found, -1
    cout << (T_stl.empty() ? -1 : *T_stl.rbegin()) << '\n'; // not found, -1

    // Sample BST as shown in Lecture, the keys are inserted in 'random' order
    T_stl.insert(15);
    T_stl.insert(23);
    T_stl.insert(6);
    T_stl.insert(71);
    T_stl.insert(50);
    T_stl.insert(4);
    T_stl.insert(7);
    T_stl.insert(5);

    cout << *T_stl.begin() << '\n';                // 4
    cout << *T_stl.rbegin() << '\n';               // 71

    cout << (T_stl.find(71) != T_stl.end() ? 71 : -1) << '\n'; // found, 71
    cout << (T_stl.find(7) != T_stl.end() ? 7 : -1) << '\n'; // found, 7
    cout << (T_stl.find(22) != T_stl.end() ? 22 : -1) << '\n'; // not found, -1

    for (auto& v : T_stl)                          // 4, 5, 6, 7, 15, 23, 50, 71
        cout << ' ' << v;
    cout << '\n';
    cout << *T_stl.upper_bound(23) << '\n';        // 50
    cout << *T_stl.upper_bound(4) << '\n';         // 5
    cout << (T_stl.upper_bound(71) == T_stl.end() ? -1 : *T_stl.upper_bound(71)) << '\n'; // -1
    cout << *(--T_stl.lower_bound(23)) << '\n';    // 15
    cout << (T_stl.lower_bound(4) == T_stl.begin() ? -1 : *(--T_stl.lower_bound(4))) << '\n'; // -1
    cout << *(--T_stl.lower_bound(71)) << '\n';    // 50

    cout << "No equivalent check tree height in STL\n";
    cout << "No equivalent preorder traversal in STL\n";

    cout << "Removing 5\n";
    T_stl.erase(5);
    cout << "Removing 71\n";
    T_stl.erase(71);
    cout << "Removing 15\n";
    T_stl.erase(15);

    for (auto& v : T_stl)                          // 4, 6, 7, 23, 50
        cout << ' ' << v;
    cout << '\n';
    cout << "No equivalent check tree height in STL\n";
    cout << "No equivalent preorder traversal in STL\n";

    return 0;
}