#include <iostream>
#include "stoppable_concrete.h"

int main()
{
    std::cout << "starting example" << std::endl;
    std::cout << "===============================================================" << std::endl;

    StoppableConcrete sc;

    std::thread _thread([&]() {
        sc.run();
    });

    // Wait before asking the thread to stop 
    std::this_thread::sleep_for(std::chrono::seconds(10));

    std::cout << std::endl << "Asking the thread to stop!" << std::endl;

    sc.stop();

    // Wait for thread to join
    _thread.join();
    std::cout << "Thread joined!" << std::endl;

    std::cout << "===============================================================" << std::endl;
    std::cout << "end of example!" << std::endl;
    return 0;
}
