#include <iostream>
#include <thread>
#include <string>

void thread_function(const std::string & word) {
    std::cout << word << std::endl;
}

int main() {
    std::thread thread_test(thread_function, "Hello Thread!");
    std::cout << std::hex << thread_test.get_id() << std::endl;
    thread_test.join();
    return 0;
}