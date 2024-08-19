#ifndef WORKER_HPP
#define WORKER_HPP
#include "Officer.hpp"

class Worker : public Officer{
    private:
        short int level;
    public:
        Worker(string name, short int age, string gender, string address, short int level): Officer(name, age, gender, address){
            this -> level =level;
        }
        short int getLevel() const override{
            return level;
        }
        void setLevel(int level){
            this->level = level;
        }
};
#endif
