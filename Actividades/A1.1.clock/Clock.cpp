#include <stdio.h> 
#include <time.h>   
#include <iostream>

class Clock
{
public:
//crear un método estático para crear una instancia, debe de regresar un apuntador por ser dinámico
    static Clock* instance;
    static Clock* getInstance(){ return ((instance == nullptr) ? nullptr : instance);}
    static void freeMem(){ free(instance);};
    /*{
        if(instance==nullptr)
        {
            instance = new Clock();
        }
    return instance;
    }
    */
    int getTime(){time_t t1; return time(&t1);};
    
private:
    Clock(){};
    time_t tiempo;
    ~Clock();
};
Clock* Clock::instance=nullptr;
int main()
{
    Clock *c1 = Clock::getInstance();
    std::cout << c1->getTime();
    Clock *c2 = Clock::getInstance();
    Clock::freeMem();
}

