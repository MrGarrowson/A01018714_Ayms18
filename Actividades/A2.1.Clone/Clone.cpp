/*

Instrucciones
    mínimo dos apuntadores
    mínimos dos atributos normales

    encender()
    apagar()
    reiniciar()
    restaurar()

    clone()
    copy constructor
    main - > clonar al menos 3 objetos

Enrique Vadillo Calva A01018714
constructores copia y metodos clon

*/
#include <iostream>

class Movil
{
    public:
        int weight;
        int size;
        int *apuntador;
        int *apuntador2;
        
        virtual Movil *clone()=0;
        Movil(){}
        Movil(int n): weight(n), size(n), apuntador(new int(n)),apuntador2(new int(n))
        {
        }
        void encender(){std::cout<<"Dispositivo encendido\n";};
        void apagar(){std::cout<<"Dispositivo encendido\n";};
        void reiniciar(){std::cout<<"Dispositivo encendido\n";};
        void restaurar(){std::cout<<"Dispositivo encendido\n";};

};

class Tablet : public Movil
{
public:
    int* tablet;
    Movil *clone()
    {
        return new Tablet(*this);
    }
    Tablet() { }
    Tablet(int n): Movil(n), tablet(new int(n))
    {

    }
    Tablet(const Tablet & n)
    {
        weight = n.weight;
        size = n.size;
        apuntador = new int(*(n.apuntador));
        apuntador2 = new int(*(n.apuntador2));
        tablet = new int(*(n.tablet));
    }
};

class SmartPhone : public Movil 
{
public:
    int* smartphone;
    Movil *clone()
    {
        return new SmartPhone(*this);
    }
    SmartPhone() { }
    SmartPhone(int n): Movil(n), smartphone(new int(n))
    {

    }
    SmartPhone(const SmartPhone& n)
    {
        weight = n.weight;
        size = n.size;
        apuntador = new int(*(n.apuntador));
        apuntador2 = new int(*(n.apuntador2));
        smartphone = new int(*(n.smartphone));
    }
};

class SmartWatch : public Movil
{
public:
    int* smartwatch;
    Movil *clone()
    {
        return new SmartWatch(*this);
    }
    SmartWatch() { }
    SmartWatch(int n): Movil(n), smartwatch(new int(n))
    {

    }
    SmartWatch(const SmartWatch& n)
    {
        weight = n.weight;
        size = n.size;
        apuntador = new int(*(n.apuntador));
        apuntador2 = new int(*(n.apuntador2));
        smartwatch = new int(*(n.smartwatch));
    }
};

using namespace std;

int main()
{
    Movil *tablet_samsung = new Tablet(500);
    Movil *smartphone_sony = new SmartPhone(750);
    Movil *smartwatch_motorola = new SmartWatch(400);

    Movil *tablet_htc = tablet_samsung->clone();
    Movil *smartphone_huawei = smartphone_sony->clone();
    Movil *smartwatch_tizen = smartwatch_motorola->clone();

    
    cout << "tablet samsung   weight: " << tablet_samsung->weight << "\n";
    cout << "tablet htc:   weight: " << tablet_samsung->weight << "\n";
    cout << "smartphone sony  weight: " << smartphone_sony->weight << "\n";
    cout << "smartphone huawei  weight: " << smartphone_sony->weight << "\n";
    cout << "smartwatch motorola weight: " << smartwatch_motorola->weight << "\n";
    cout << "smartwatch tizen: weight: " << smartwatch_tizen->weight << "\n";

    tablet_htc->weight = 450;
    smartphone_huawei->weight = 300;
    smartwatch_tizen->weight = 120;
  
    cout << "tablet samsung   weight: " << tablet_samsung->weight << "\n";
    cout << "tablet htc:   weight: " << tablet_samsung->weight << "\n";
    cout << "smartphone sony  weight: " << smartphone_sony->weight << "\n";
    cout << "smartphone huawei  weight: " << smartphone_sony->weight << "\n";
    cout << "smartwatch motorola weight: " << smartwatch_motorola->weight << "\n";
    cout << "smartwatch tizen: weight: " << smartwatch_tizen->weight << "\n";
    

    
}
