#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

class Wallet {
    int Money;
    std::mutex mutex;
public:
    Wallet() : Money(0) {} 
    int getMoney() { return Money; } 
    void addMoney(int money) {
        std::lock_guard<std::mutex> lockGuard(mutex);
        // mutex.lock();
        for (int i = 0; i < money; ++i) {
            Money++;
        }
        // mutex.unlock();
    }
};

int testMultithreadedWallet() {
    Wallet myWallet;
    std::vector<std::thread> threads;
    for ( int  i = 0; i < 5; i++ ) {
        threads.push_back(std::thread(&Wallet::addMoney, &myWallet, 1000));
    }

    for (int i = 0; i < threads.size(); i++) {
        threads.at(i).join();
    }  
    return myWallet.getMoney();
}

int main() {
    int val = 0;
    for (int k = 0; k < 1000; k++) {
        if ((val = testMultithreadedWallet()) != 5000) {
            std::cout << "Error at count = " 
                      << k << " Money in Wallet"
                      << val 
                      << std::endl;
        }
    }
    return 0;
}