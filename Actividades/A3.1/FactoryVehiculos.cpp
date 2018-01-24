#include <iostream>


class Vehicle
{
    public:
        virtual void ensamblar()=0;
        virtual void pintar()=0;
        virtual void hojalatear()=0;
        virtual void Entrega()=0;
        
};

class Dodge: public Vehicle
{
    
};
class BMW: public Vehicle
{
    
};
class VW: public Vehicle
{
    
};
class Nissan: public Vehicle
{
    
};


class Creator
{
    
        template<class Tipo> 
        Tipo * factoryMethod()
        {
            return new Tipo;
        }

    public:

        template<class Tipo> 
        static Tipo *create()
        {
            Tipo *temporal;
            temporal = factoryMethod<Tipo>();
            temporal->ensamblar();
            temporal->pintar();
            return temporal;
        }
};



int main()
{
    Creator *cliente = new Creator;
    Vehicle *miProducto = cliente->create<BMW>();
    return 1;
    //factoryM<Dodge>();
}
