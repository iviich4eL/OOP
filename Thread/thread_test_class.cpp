#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <functional>

class myThread {
public:
    void operator()() {
        std::cout << "myThread id: " 
                << std::this_thread::get_id() 
                << " is Executing" 
                << std::endl;  
    }
};

int main() {
    std::vector<std::thread> threadVec;
    for (int i = 0; i < 10; i++ ) {
        threadVec.push_back(std::thread( myThread() ) );
        threadVec[i].join();
    }
    // std::for_each(threadVec.begin(),threadVec.end(), std::mem_fn(&std::thread::join));
    return 0;
}