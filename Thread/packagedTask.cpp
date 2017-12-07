#include <iostream>
#include <thread>
#include <future>
#include <string>

std::string getDataFromDB(std::string token) {
    std::string data= "Data fetched from DB by Filter :: " + token;
    return data;
}

int main() {
    std::packaged_task<std::string(std::string)> task(getDataFromDB);

    std::future<std::string> result = task.get_future();
    std::thread th(std::move(task), "Arg");
    th.join();

    std::string data = result.get();
    std::cout << data << std::endl;

    return 0;
}