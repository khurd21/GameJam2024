#ifndef IRUNNER_HPP
#define IRUNNER_HPP

class IRunner {
public:

    virtual ~IRunner() = default;

    virtual void run() = 0;

}; // class IRunner

#endif // IRUNNER_HPP