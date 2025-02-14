#include <iostream>
#include <string>
#include <thread>
#include <mutex>
using namespace std;

class Logger
{
 public:
    static Logger *GetInstance();
    static void ReleaseInstance();
    Logger(const Logger&LogParam) = delete;
    Logger &operator = (const Logger&LogParam) = delete;
    void Log(const string &S) { std::cout << "LOG :: " <<  S << std::endl; }
 private:
    Logger() {
        std::cout << "Number of instance : " << ++count << std::endl;
    }
    ~Logger() {
        std::cout << "Number of instance : " << --count << std::endl;
    }
    static int count;
    static Logger *instance;
    static mutex mx;
};

Logger * Logger :: GetInstance() 
{
    if(instance == nullptr)
    {
        std::unique_lock<std::mutex> Ulock(mx);
        if(instance == nullptr) {
            instance = new Logger();
        }
    }
    return instance;
}

void Logger :: ReleaseInstance()
{
    std::unique_lock<std::mutex> Ulock2(mx);
    if(instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}

int Logger :: count = 0;
Logger * Logger :: instance = nullptr;
mutex Logger :: mx;

void TestForUser1() 
{    
    Logger *user1 = Logger :: GetInstance();
    user1->Log("Hello I am User 1\n");
}

void TestForUser2() 
{
    Logger *user2 = Logger :: GetInstance();
    user2->Log("Hello I am User 2\n");
}

void TestForUser3() 
{
    Logger *user3 = Logger :: GetInstance();
    user3->Log("Hello I am User 3\n");
}

int main()
{
    std::thread T1(&TestForUser1);
    std::thread T2(&TestForUser2);
    std::thread T3(&TestForUser3);

    if(T1.joinable()) {
        Logger::ReleaseInstance();
        T1.join();
    }

    if(T2.joinable()) {
        Logger::ReleaseInstance();
        T2.join();
    } 

    if(T3.joinable()) {
        Logger::ReleaseInstance();
        T3.join();
    } 

    return  0;
}