#include <iostream>
using namespace std;

template <class T>
class Vector
{
 public:
    Vector() : size_(0), capacity_(1){
        Arr = new T[capacity_];
    }
    ~Vector(){
        delete []Arr;
    }
    int size() const{
        return size_;
    }
    int capacity() const{
        return capacity_;
    }
    bool isEmpty() {
        return size_ == 0;
    }
    T operator[](int idx) {
        return Arr[idx];
    }
    void push_back(T item)
    {
        if(size_ == capacity_)
        {
            //Resizing the container
            capacity_ *= 2;
            T* Temp_Arr = new T[capacity_];
            for(int i = 0; i < size_; i++)
                Temp_Arr[i] = Arr[i];
                
            Arr = Temp_Arr;    
        }
        Arr[size_++] = item;
    }
    void pop(){
        if(size_ > 0) {
            size_--;
        }
    }
 private:
    T *Arr;
    int size_;
    int capacity_;
};

void showVector(Vector<int> &V)
{
    std::cout << "Size ::: " << V.size() << "\nCapacity ::: " << V.capacity() << std::endl;
    if(V.size()) {
        for(int i = 0; i < V.size(); i++)
            std::cout << V[i] << " ";   
    }
    std::cout << "\n\n";  
}

int main()
{
    Vector<int> V;
    showVector(V);
    V.isEmpty() ? (std::cout << "TRUE\n") : (std::cout << "FALSE\n"); 
    
    V.push_back(10);
    V.push_back(20);
    V.push_back(30);
    showVector(V);

    V.pop();
    showVector(V);

    V.pop();
    showVector(V);
    
    return 0;
}