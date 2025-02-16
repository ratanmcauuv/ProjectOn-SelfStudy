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
        while(size_) {
            deleteFromEnd();
        }
    }
    void insertAtBegining(int n);
    void appendAtEnd(int n);
    void deleteFromBegining();
    void deleteFromEnd();
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
    
    L.deleteFromBegining();
    L.deleteFromBegining();
    L.showList();
    
    L.deleteFromEnd();
    L.deleteFromEnd();
    L.showList();
    
    return 0;
}