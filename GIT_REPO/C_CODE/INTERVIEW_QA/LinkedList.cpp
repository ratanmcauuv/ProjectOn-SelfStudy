#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node *NODE;

class List
{
 public:
    List() : header(nullptr) { std::cout << "List()\n"; }
    ~List() { std::cout << "~List()\n"; }
    void printElmOfList();
    void insertElmAtBeginingOfList(int n);
 private:
    NODE newNode(int n);
    NODE header;
};

NODE List :: newNode(int n)
{
    NODE curr = new Node;
    if(curr) {
        curr->data = n;
        curr->next = nullptr;
    }
    return curr;
}

void List :: insertElmAtBeginingOfList(int n)
{
    NODE curr = newNode(n);
    if(header == nullptr) {
        header = curr;
    }
    else {
        curr->next = header;
        header = curr;
    }
}

void List :: printElmOfList()
{
    NODE curr = header;
    while(curr != nullptr) {
        std::cout << curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main()
{
    List L;
    L.insertElmAtBeginingOfList(10);
    L.insertElmAtBeginingOfList(20);
    L.insertElmAtBeginingOfList(30);
    L.insertElmAtBeginingOfList(40);
    L.insertElmAtBeginingOfList(50);
    L.printElmOfList();
    
    return 0;
}