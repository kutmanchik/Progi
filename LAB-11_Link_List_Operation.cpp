#include <iostream>

using namespace std;

class List {
private:
    typedef struct node {
        int data;
        node* next;
    }* nodePtr;

    nodePtr head;
    nodePtr curr;
    nodePtr temp;

public:
    List();

    void Add(int data);
    void Insert(int data , int pos);
    void Delete(int pos);
    void print();
};

List::List() {
    head = NULL;
    curr = NULL;
    temp = NULL;
}


void List::Add(int data) {
    nodePtr n = new node;
    n->next = NULL;
    n->data = data;

    if(head != NULL) {
        curr = head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = n;
    }
    else head = n;

}

void List::Insert(int data , int pos) {
    nodePtr n = new node;
    n->data = data;
    n->next = NULL;
    if(head == NULL) {
        if(pos != 0) return;
        else head = n;
    }

    if(head != NULL && pos == 0) {
        n->next = head;
        head = n;
        return;
    }

    curr = head;
    temp = NULL;
    while(pos-- && curr != NULL) {
        temp = curr;
        curr = curr->next;
    }
    n->next = curr;
    temp->next = n;
}


void List::Delete(int pos) {
    nodePtr delptr;
    temp = head;

    if(pos == 1) {
        head = temp->next;
      delete temp;
      return;
    }

    for(int i = 1 ; i != pos ;i++) {
        delptr = temp;
        temp = temp->next;
    }
    delptr->next = temp->next;
    delete temp;
}

void List::print() {
    curr = head;
    while(curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}


int main() {

    int N,n,Choose, pos, data;
    List L;
    cin >> N;

    for(int i = 0 ; i < N ; i++) {
        cin >> n;
        L.Add(n);
    }

    while( cin >> Choose ) {
        if(!Choose) break;
        switch(Choose) {
            case 1:         // Insert Number
                cin >> pos >> data;
                L.Insert(data , pos-1);
                break;
            case 2:         // Delete Number at some position
                cin >> pos;
                L.Delete(pos);
                break;
            case 3:         // Print the whole list.
                L.print();
                break;

        }
    }

    return 0;
}
/**
Sample Input
5 1 2 3 4 5
3
1 1 0
3
2 6
3
0
Sample Output
1 2 3 4 5
0 1 2 3 4 5
0 1 2 3 4
*/
