#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <string>

std::condition_variable g_Bell;
std::condition_variable_any g_Door;

class Manager
{
public:
    void ComeToWork()
    {
        std::cout << "Hey security, please open the door!\n";
        g_Bell.notify_one();
        std::mutex mutex;
        mutex.lock();
        g_Door.wait(mutex);
        mutex.unlock();
    }
};

class Security
{
    static bool m_SectorClear;
    static std::mutex m_SectorMutex;
public:
    static bool SectorClear()
    {
        std::lock_guard<std::mutex> lock(m_SectorMutex);
        return m_SectorClear;
    }
    void NotifyFellows()
    {
        std::lock_guard<std::mutex> lock(m_SectorMutex);
        m_SectorClear = false;
    }
    void WorkHard()
    {
        m_SectorClear = true;
        std::mutex mutex;
        std::unique_lock<std::mutex> lock(mutex);
        while(true)
        {
            if(g_Bell.wait_for(lock, std::chrono::seconds(5)) == std::cv_status::timeout)
                std::this_thread::sleep_for(std::chrono::seconds(10));
            else
            {
                NotifyFellows();
                g_Door.notify_one();
                std::cout << "Hello Great Manager, your slaves are ready to serve you!\n" << std::endl;
            }
        }
    }
};

bool Security::m_SectorClear;
std::mutex Security::m_SectorMutex;

class Programmer
{
public:
    void WorkHard()
    {
        std::cout << "Let's write some govnokod!\n" << std::endl;
        int i = 0;
        while(true)
        {
            i++;
            i--;
        }
    }
    void PlayStarcraft()
    {
        while(Security::SectorClear())
            ;//Играем! :)
        WorkHard();// Работаем :(
    }
};



int main()
{
    Manager manager;
    Programmer programmer;
    Security security;

    auto managerCall = [&manager]()
    {
        manager.ComeToWork();
    };
    auto programmerCall = [&programmer]()
    {
        programmer.PlayStarcraft();
    };
    auto securityCall = [&security]()
    {
        security.WorkHard();
    };
    std::thread securityThread(securityCall);
    std::thread programmerThread(programmerCall);
    std::this_thread::sleep_for(std::chrono::minutes(1));
    std::thread managerThread(managerCall);
    
    managerThread.join();
    programmerThread.join();
    securityThread.join();

    return 0;
}