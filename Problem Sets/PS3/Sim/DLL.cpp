/**
 * Matric: A0217988E
 * Name: Brendan Cheong Ern Jie
 * Lab: 10
 * TA: Fidella Widjojo
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long int;

struct Vertex { // we can use either C struct or C++/Python/Java class
    ll item; // the data is stored here, an integer in this example
    Vertex* next; // this pointer tells us where is the next vertex
    Vertex* prev; // this pointer tells us where is the previous vertex
};

class DLL {
private:
    Vertex* head;
    Vertex* tail;
    Vertex* current;
    ll curr_index;
    ll size;
public:
    DLL() {
        this->head = NULL;
        this->tail = NULL;
        this->current = NULL; // the current vertex after insertion of vertex to double linked list
        this->curr_index = 0;
        this->size = 0;
    }

    // create a function that inserts a new vertex at the head and updates vertex accordingly
    void InsertAtHead(ll v) {
        Vertex* vtx = new Vertex();
        vtx->item = v;
        vtx->next = this->head;
        vtx->prev = NULL;
        if (this->head != NULL) {
            this->head->prev = vtx;
        }
        this->head = vtx;
        if (this->tail == NULL) {
            this->tail = vtx;
        }
        this->current = vtx;
        this->curr_index = 0;
        ++size;
    }

    // create a function that inserts a new vertex at the tail and updates vertex accordingly
    void InsertAtTail(ll v) {
        Vertex* vtx = new Vertex();
        vtx->item = v;
        vtx->next = NULL;
        vtx->prev = this->tail;
        if (this->tail != NULL) {
            this->tail->next = vtx;
        }
        this->tail = vtx;
        if (this->head == NULL) {
            this->head = vtx;
        }
        this->current = vtx;
        ++size;
        this->curr_index = size - 1;
    }

    void InsertAtCurrentVertex(ll v) {
        // if (this->current == NULL || (this->curr_index == 0 && this->size > 0)) {
        //     InsertAtHead(v);
        //     return;
        // }
        // else if (this->curr_index == size) {
        //     InsertAtTail(v);
        //     return;
        // }

        if (this->current == NULL || this->current == tail) {
            InsertAtTail(v);
            return;
        }

        Vertex* vtx = new Vertex();
        vtx->item = v;
        Vertex* aft = this->current->next;
        Vertex* pre = this->current;
        vtx->next = aft;
        aft->prev = vtx;
        pre->next = vtx;
        vtx->prev = pre;
        this->current = vtx;
        ++size;
    }

    // create a function to delete the current vertex
    // the this->current attribute should point to its previous vertex
    void DeleteCurrentVertex() {
        if (this->current == NULL) {
            return;
        }
        if (this->current == this->head) {
            DeleteHead();
            return;
        }
        if (this->current == this->tail) {
            DeleteTail();
            return;
        }
        Vertex* pre = this->current->prev;
        Vertex* aft = this->current->next;
        pre->next = aft;
        aft->prev = pre;
        delete this->current;
        this->current = pre;
        --size;
    }

    ll GetHead() {
        if (head == NULL)
            return -1; // avoid crashing when DLL is empty
        return head->item;
    }

    ll GetTail() {
        if (tail == NULL)
            return -1; // avoid crashing when DLL is empty
        return tail->item;
    }

    ll GetCurrent() {
        if (current == NULL)
            return -1; // avoid crashing when DLL is empty
        return current->item;
    }

    ll GetSize() {
        return size;
    }

    // create a function to delete the head vertex
    // and update the current vertex if its the head vertex
    void DeleteHead() {
        bool isHead = false;
        if (head == NULL) return; // avoid crashing when DLL is empty
        Vertex* temp = head; // so we can delete it later
        if (current == head)
            isHead = true;
        head = head->next; // book keeping, update the head pointer
        delete temp; // which is the old head
        if (head != NULL)
            head->prev = NULL;
        if (isHead)
            this->current = head;
        --size;
    }

    void DeleteTail() {
        bool isTail = false;
        if (this->tail == NULL) return; // avoid crashing when DLL is empty
        Vertex* temp = tail; // so we can delete it later
        if (this->current == this->tail)
            isTail = true; // update the current pointer
        tail = tail->prev; // book keeping, update the tail pointer
        tail->next = NULL;
        if (isTail)
            this->current = tail;
        delete temp; // which is the old tail
        --size;
    }

    void Insert(ll index, ll v) { // O(n)
        if (index < 0 || index > size) {
            cout << "Invalid index\n";
            return;
        }
        if (index == 0) {
            InsertAtHead(v);
            return;
        }
        if (index == size) {
            InsertAtTail(v);
            return;
        }
        Vertex* vtx = new Vertex(); // create new vertex vtx from item v
        vtx->item = v;
        Vertex* curr = head;
        for (ll i = 0; i < index; ++i) {
            curr = curr->next;
        }
        vtx->next = curr;
        vtx->prev = curr->prev;
        curr->prev->next = vtx;
        curr->prev = vtx;
        this->current = vtx;
        ++size;
    }

    void Remove(ll index, ll v) { // O(n)
        if (index < 0 || index > size) {
            cout << "Invalid index\n";
            return;
        }
        if (index == 0) {
            DeleteHead();
            return;
        }
        if (index == size) {
            DeleteTail();
            return;
        }
        Vertex* curr = head;
        for (ll i = 0; i < index; ++i) {
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        DeleteCurrentVertex(); // already reduces size
        delete curr;
    }

    void UpdateCurrIndex(bool increment) {
        if (increment) {
            this->curr_index++;
        }
        else {
            this->curr_index--;
        }
    }

    void SetCurrIndex(ll index) {
        this->curr_index = index;
    }

    void printList() {
        Vertex* temp = head;
        while (temp != NULL) {
            cout << temp->item << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    void printCurrent() {
        cout << this->current->item << endl;
    }

    void printCurrIndex() {
        cout << this->curr_index << endl;
    }

    void ClearList() {
        while (this->head != NULL) {
            DeleteHead();
        }
    }
};

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    DLL dl;

    dl.InsertAtHead(5);
    dl.InsertAtTail(2);
    dl.InsertAtHead(7);
    dl.printList();
    dl.printCurrent();
    dl.InsertAtCurrentVertex(1);
    dl.InsertAtCurrentVertex(3);
    dl.DeleteCurrentVertex();
    dl.InsertAtCurrentVertex(9);
    dl.printList();
    cout << dl.GetSize() << '\n';

    dl.ClearList();

    dl.InsertAtHead(1);
    dl.printList();
    dl.InsertAtCurrentVertex(4);
    dl.InsertAtCurrentVertex(5);
    dl.InsertAtCurrentVertex(6);
    dl.InsertAtCurrentVertex(7);
    dl.InsertAtHead(8);
    dl.InsertAtCurrentVertex(2);
    // cout << dl.GetCurrent() << '\n';
    dl.DeleteCurrentVertex();
    dl.DeleteCurrentVertex();
    dl.InsertAtCurrentVertex(9);
    dl.printList();

    return 0;
}