#ifdef NDEBUG
#define THIS_DEBUG
#endif

#undef NDEBUG
#include <assert.h>

#ifdef THIS_DEBUG
#define NDEBUG
#endif

#include <atomic>
#include <iostream>
#include <thread>

int main() {
    std::atomic<bool> flag = true;
    size_t counter         = 0;

    auto thread = std::thread([&flag, &counter] {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "thread" << std::endl;
        counter++;
        flag = false;
    });

    thread.detach();

    // Wait counter++;
    while (flag) {
    }

    assert(counter == 1);

    std::cout << "end" << std::endl;

    return 0;
}
