#include "timer.hpp"

#include <thread>
#include <iostream>

using namespace std::chrono_literals;

int main(int argc, char* argv[])
{
    // TODO: implement perf tests
    // Timer usage example

    Timer timer;

    timer.start();

    std::this_thread::sleep_for(3s);
    timer.stop();

    std::cout << "Waited for " << timer.sInterval() << "s\n";

    return 0;
}
