#include <iostream>
#include <future>

std::future<bool> submitForm(const std::string &form)
{
    auto handle = [](const std::string &form) -> bool {
        std::cout << "Handle the submitted form: " << form << "\n";
        return true;
    };
    std::packaged_task<bool(const std::string &)> task(handle);
    auto future = task.get_future();
    std::thread thread(std::move(task), form);
    thread.detach();
    return std::move(future);
}

int main()
{
    auto check = submitForm("my form");
    if (check.get())
        std::cout << "Wow I've got a passport!\n";
    else
        std::cout << "Dammit, they found a mistake again!\n";
}