
#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

class Logger {
private:
    std::ofstream logfile;

public:
    Logger(const std::string& filename);
    ~Logger();

    void log(const std::string& message);
};

#endif  // LOGGER_H
