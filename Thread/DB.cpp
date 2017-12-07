#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>

using namespace std::chrono;

std::string fetchDataFromDB(std::string recvdData) {
    std::this_thread::sleep_for(seconds(5));
    return "DB_" + recvdData;
}

std::string fetchDataFromFile(std::string recvdData) {
    std::this_thread::sleep_for(seconds(5));
    return "File_" + recvdData;
}

int main () {
    system_clock::time_point start = system_clock::now();

    std::future<std::string> resultFromDB = 
            std::async(std::launch::async,fetchDataFromDB, "Data");

    std::string fileData = fetchDataFromFile("Data");

    std::string dbData = resultFromDB.get();

    auto end = system_clock::now();
    auto diff = duration_cast<std::chrono::seconds> (end - start).count();
    std::cout << "Total Time Taken = " << diff 
              << " Seconds" << std::endl; 
    std::string data = dbData + " :: " + fileData;
    std::cout << "Data = " << data << std::endl;
    return 0;
}