#include <iostream>
#include <thread>
#include <string>

int main() 
{
    auto func = [] (const std::string & first, 
                    const std::string & second) {
        std::cout << first << second;              
    };
    std::thread thread(func, "Hello, ", "threads!");
    std::cout << std::hex << thread.get_id() << "\n";
    thread.join();
}
