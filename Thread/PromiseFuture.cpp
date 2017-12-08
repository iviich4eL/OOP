#include <iostream> 
#include <thread>
#include <future>

void initiazer(std::promise<int> * promObj) {
    std::cout << "Inside thread" << std::endl;
    promObj->set_value(35);
}

int main() 
{
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();
    std::thread th(initiazer, &promiseObj);
    // std::cout << futureObj.get() << std::endl;
    int value = futureObj.get();
    std::cout << value << std::endl;
    th.join();typedef  std::function<void(void)> command;

    return 0;
}