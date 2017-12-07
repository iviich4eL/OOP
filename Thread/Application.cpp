#include <iostream>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std::placeholders;

class Application {
    std::mutex m_mutex;
    std::condition_variable m_condVar;
    bool m_bDataLoaded;
public:
    Application() {
        m_bDataLoaded = false;
    }    
    void loadData() {
        std::this_thread::sleep_for(std::chrono::microseconds(1000));
        std::cout << "Loading Data from XML" << std::endl;
        std::lock_guard<std::mutex> guard(m_mutex);
        m_bDataLoaded = true;
        m_condVar.notify_one();
    }
    bool isDataLoaded() {
        return m_bDataLoaded;
    }
    void mainTask() {
        std::cout << "Do Some Handshaking" << std::endl;
        std::unique_lock<std::mutex> mlock(m_mutex);
        m_condVar.wait(mlock, std::bind(&Application::isDataLoaded, this));
        std::cout << "Do Processing On Loaded Data" << std::endl;
    }
};

int main() {
    Application app;
    std::thread thread_1(&Application::mainTask, &app);
    std::thread thread_2(&Application::loadData, &app);
    thread_2.join();
    thread_1.join();
    return 0;
}