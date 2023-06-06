
#include "Logger.h"


Logger::Logger(const std::string& filename) {
    logfile.open(filename, std::ios::app);
}

Logger::~Logger() {
    if (logfile.is_open())
        logfile.close();
}

void Logger::log(const std::string& message) {
    if (logfile.is_open()) {
        logfile << message << std::endl;
        logfile.flush();
    }
}
