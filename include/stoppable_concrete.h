
#ifndef STOPPABLE_CONCRETE_H_
#define STOPPABLE_CONCRETE_H_

#include "stoppable.h"

class StoppableConcrete : public Stoppable {

public:
    StoppableConcrete() = default;

    virtual ~StoppableConcrete() = default;

    // Function to be executed by thread function
    virtual void run() {
        std::cout << "Thread Task start!" << std::endl;

        std::cout << "Task work" << std::flush;
        // Check if thread is requested to stop!
        while(!stopRequested()) {
            std::cout << "." << std::flush;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        std::cout << "Thread Task end!" << std::endl;
    }


};

#endif //STOPPABLE_CONCRETE_H_