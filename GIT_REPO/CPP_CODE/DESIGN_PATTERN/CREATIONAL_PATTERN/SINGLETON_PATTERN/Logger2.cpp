#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>
#include <cstring>
#include <algorithm>
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

void TestForUser(int n) 
{    
    Logger *user = Logger :: GetInstance();
    char msg[20];
    sprintf(msg, "Hello I am User : %d", n);
    user->Log(msg);
}

int main()
{
    std::vector<std::thread> T_Pool;
    for(int i = 0; i < 20; i++) {
        T_Pool.push_back(std::thread(&TestForUser, i+1));
    }
    
    for_each(T_Pool.begin(), T_Pool.end(), [](auto &t) {
        Logger::ReleaseInstance();
        if(t.joinable()) t.join();
    });

    return  0;
}