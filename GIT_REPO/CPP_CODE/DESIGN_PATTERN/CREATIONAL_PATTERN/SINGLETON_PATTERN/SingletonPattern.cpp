#include <iostream>
#include <string>
#include <mutex>
#include <thread>
using namespace std;
std::mutex MX;

class Singleton
{
 public:
    static Singleton *GetInstance();
    static void ReleaseInstance();
    void CallAPI() { std::cout << "CallAPI()\n";}
    /* Remove copy constructor, copy assignment operator*/
    Singleton &operator = (const Singleton &SParam) = delete;
    Singleton(Singleton &&SParam) = delete;
 private:
    Singleton() { std::cout << "Inside Singleton()\n"; }
    ~Singleton() { std::cout << "Inside ~Singleton()\n"; }
    static Singleton *instance_;
};

void Singleton :: ReleaseInstance() 
{
    std::cout << "Inside ReleaseInstance()\n";
    if(instance_ != nullptr)
    {
        MX.lock();
        delete instance_;
        instance_ = nullptr;
        MX.unlock();
    }
}

Singleton *Singleton :: GetInstance() 
{
    std::cout << "Inside GetInstance()\n";
    if(instance_ == nullptr)
    {
        MX.lock();
        if(instance_ == nullptr) {
            instance_ = new Singleton();
        }
        MX.unlock();        
    }
    return instance_;    
}

Singleton * Singleton :: instance_ = nullptr;

void TestingSingleton()
{
    Singleton *SObj = Singleton :: GetInstance();
    SObj->CallAPI();
    SObj->ReleaseInstance();
}

int main()
{
    std::thread T1(&TestingSingleton);
    std::thread T2(&TestingSingleton);
    std::thread T3(&TestingSingleton);
    
    if(T1.joinable()) T1.join();
    if(T2.joinable()) T2.join();
    if(T3.joinable()) T3.join();

    return 0;
}