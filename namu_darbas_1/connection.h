#ifndef __CONNECTION_H_
#define __CONNECTION_H_

#include <fstream>
#include <vector>

class Car;

class Connection {
    std::ofstream output;
    std::ifstream input;
    std::string filename;

    public:
        explicit Connection(const std::string& filename);
        ~Connection();

        void database_load(std::vector<Car*>* rows);

        void database_write(std::vector<Car*> rows);
};

#endif
