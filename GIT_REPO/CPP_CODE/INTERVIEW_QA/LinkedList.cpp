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
    List() : header_(nullptr), size_(0){
        //std::cout << "List()\n";
    }
    ~List() {
        std::cout << "~List()\n";
        while(size_) 
            deleteFromEnd();
    }
    void insertAtBegining(int n);
    void appendAtEnd(int n);
    void deleteFromBegining();
    void deleteFromEnd();
    void reverseList();
    NODE getMidNodeFromList();
    bool checkIfCylic();
    void deleteNodeFromList(int n);
    void insertNodeAtPos(int n, int pos);
    void showList();
    int getLength() const {
        return size_;
    }
 private:
    NODE newNode(int n);
    NODE header_;
    int size_;
};

NODE List :: newNode(int n) 
{
    NODE temp = new Node();
    temp->data = n;
    temp->next = nullptr;
    return temp;
}

void List :: showList() 
{
    NODE curr = header_;
    while(curr != nullptr) {
        std::cout << curr->data;
        curr = curr->next;
        if(curr != nullptr)
            std::cout << "->";
    }
    std::cout << "\n";
}
//header->10->20->30
void List :: insertAtBegining(int n) 
{
    NODE curr = newNode(n);
    if(header_ == nullptr)
        header_ = curr;
    else {
        curr->next = header_;
        header_ = curr;
    }
    size_++;
}
//header->30->20->10->40
void List :: appendAtEnd(int n)
{
    NODE curr = newNode(n);
    if(header_ == nullptr)
        header_ = curr;
    else {
        NODE temp  = header_;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = curr;
    }
    size_++;
}
//header->30->20->10->40->50->60
void List :: deleteFromBegining()
{
    if(header_ == nullptr) {
        std::cout << "List Empty, Nothing to delete!!\n";
        return;
    }
    else if (header_->next == nullptr) {
        delete header_;
        header_ = nullptr;
    }
    else {
        NODE temp = header_;
        header_ = header_->next;
        delete temp;
    }
    size_--;
}
//10->40->50->60
void List :: deleteFromEnd()
{
    if(header_ == nullptr) {
        std::cout << "List Empty, Nothing to delete!!\n";
        return;
    }
    else if (header_->next == nullptr) {
        delete header_;
        header_ = nullptr;
    }
    else {
        NODE temp = header_;
        while(temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    size_--;  
}
//10->40->50->60
//header -> 10 -> 20
void List::reverseList()
{
    if(header_ == nullptr) {
        std::cout << "List Empty\n";
        return;
    }
    NODE curr = header_;
    NODE prev = nullptr;
    NODE next = nullptr;

    while(curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    header_ = prev;
}

NODE List::getMidNodeFromList()
{
    if(header_ == nullptr) {
        std::cout << "List Empty\n";
        return header_;
    }
    NODE fastPtr, slowPtr;
    fastPtr = slowPtr = header_;

    while((fastPtr->next != nullptr) && (fastPtr->next->next != nullptr))
    {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }
    return slowPtr;
}

bool List :: checkIfCylic()
{
    bool cyclicFlag = false;
    if(header_ == nullptr) {
        std::cout << "List Empty\n";
        return cyclicFlag;
    }

    NODE fastPtr, slowPtr;
    fastPtr = slowPtr = header_;
    while((fastPtr->next != nullptr) && (fastPtr->next->next != nullptr))
    {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
        if(fastPtr == slowPtr) {
            cyclicFlag = true;
            break;
        }
    }
    return cyclicFlag;
}

// header->10->20->30
void List :: deleteNodeFromList(int n)
{
    if(header_ == nullptr) {
        std::cout << "List Empty, Nothing to delete !!\n";
        return;
    }
    NODE curr = header_;
    while(curr->next != nullptr)
    {
        //If the Item is found
        if(curr->data == n) {
            NODE temp = curr;
            curr = curr->next;
            delete temp;
            return;
        }
        curr = curr->next;
    }
    std::cout << "Item not found !!\n";
}

void List :: insertNodeAtPos(int n, int pos)
{
    if(pos-1 == 0) {
        insertAtBegining(n);
    }else if(pos == size_) {
        appendAtEnd(n);
    } else if(pos > size_) {
        std::cout << "List size is less to position supplied !!\n";
        return;
    }
    else
    {
        //30->20->10->40->50->60
        // ->25->40
        NODE curr = header_;
        int count = 1;
        while(curr != nullptr)
        {
            if(count++ == pos-1) {
                NODE temp = newNode(n);
                temp->next = curr->next;
                curr->next = temp;
            }
            curr = curr->next;
        }
        size_++;
    }
}

int main()
{
    List L;
    L.insertAtBegining(10);
    L.insertAtBegining(20);
    L.insertAtBegining(30);
    L.showList();

    L.appendAtEnd(40);
    L.appendAtEnd(50);
    L.appendAtEnd(60);
    L.showList();

    L.deleteNodeFromList(100);
    L.showList();

    L.insertNodeAtPos(25,4);
    L.showList();

    NODE mid_node = L.getMidNodeFromList();
    if(mid_node) {
        std::cout << "Mid Node ::: " << mid_node->data << std::endl;
    }

    L.checkIfCylic() ? (std::cout << "CYCLIC\n") : (std::cout << "Not CYCLIC\n");

    L.deleteFromBegining();
    L.deleteFromBegining();
    L.showList();
    
    L.deleteFromEnd();
    L.deleteFromEnd();
    L.showList();

    L.reverseList();
    L.showList();

    return 0;
}