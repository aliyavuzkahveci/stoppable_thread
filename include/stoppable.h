#ifndef STOPPABLE_H_
#define STOPPABLE_H_

#include <iostream>
#include <future>
#include <chrono>

class Stoppable {

    std::promise<void> m_exitSignal;
    std::future<void> m_futureObj;

public:
    Stoppable() : m_futureObj(m_exitSignal.get_future()) {
        std::cout << "Default constructor is called!" << std::endl;
    }

    virtual ~Stoppable() = default;

    Stoppable(Stoppable && stoppable) : 
        m_exitSignal(std::move(stoppable.m_exitSignal)), m_futureObj(std::move(stoppable.m_futureObj)) {
        
        std::cout << "Move constructor is called!" << std::endl;
    }

    Stoppable & operator=(Stoppable && stoppable) {
        std::cout << "Move assignment is called!" << std::endl;
        this->m_exitSignal = std::move(stoppable.m_exitSignal);
        this->m_futureObj = std::move(stoppable.m_futureObj);

        return *this;
    }

    // to be implemented by the concrete class!
    virtual void run() = 0;

    // thread function to be executed by thread
    void operator()() {
        run();
    }

    // Check if stop requested!
    bool stopRequested() {
        // checks if value in object future is available
        if(m_futureObj.wait_for(std::chrono::milliseconds(0)) == std::future_status::timeout) {
            return false;
        }

        // stop is requested!
        return true;
    }

    // Request the thread to stop by setting the value in future object
    void stop() {
        m_exitSignal.set_value();
    } 


};

#endif