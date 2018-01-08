#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mtx;

void worker() {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "thread id: " << std::this_thread::get_id() << std::endl;
//    mtx.unlock();
}

int main() {
    std::vector<std::thread> ths(4);
    for(auto& th : ths) {
        th = std::thread(worker);
    }

    for(auto& th : ths) {
        th.join();
    }

    return 0;
}