
#include<bits/stdc++.h>
class Command
{
    public:
        virtual void Execute() = 0;
};

class Invoker
{
    private:
      std::vector<Command *> commands_;

    public:
        void storeAndExecute(Command *command)
        {
            if (command){
                commands_.push_back(command);
                command->Execute();
            }
        }
};

class Client
{
    private:
       
    public:
       
        int id;
        std::string nombre;
        std::string apellido;
        std::string contacto;
        std::string correo;
        std::string numero;
        std::string colonia;
        std::string calle;
       
        Client(){}
    
        void contactar()
        {
            if(this->contacto=="mail") llamar();
            if(this->contacto=="sms")  mandarSMS();          
            if(this->contacto=="phone_call") mandarEmail();
        }
        void llamar()
        {
            std::cout<<"Llamando"<<std::endl;
        }

        void mandarSMS()
        {
            std::cout << "mandando SMS." << std::endl;
        }
         void mandarEmail()
        {
            std::cout<<"mandando EMAIL"<<std::endl;
        }
};


/* The Command for turning on the light - ConcreteCommand #1 */
class LlamarCommand : public Command
{
  private:
    Client *cliente_;

  public:
    LlamarCommand(Client *cliente)
    {
        cliente_ =cliente;
    }

    void Execute()
    {
        cliente_->llamar();
    }
};

class MensajeCommand : public Command
{
  private:
    Client *cliente_;

  public:
    MensajeCommand(Client *cliente)
    {
        cliente_ =cliente;
    }

    void Execute()
    {
        cliente_->mandarSMS();
    }
};
class CorreoCommand : public Command
{
  private:
    Client *cliente_;

  public:
    

    CorreoCommand(Client *cliente)
    {
        cliente_ =cliente;
    }

    void Execute()
    {
        cliente_->mandarEmail();
    }
};
class Tienda
{
private:
    static Tienda* instance;

    std::vector<Client*>  vectClientes;
    Tienda(){     }
    ~Tienda() {   }
    
public:
    static Tienda* createInstance()
    {
        if(instance == nullptr)
        {
            instance = new Tienda();
        }

        return instance;
    }
    static void deleteInstance()
    {

        if(instance!=nullptr)
        {
            delete instance;
            instance = nullptr;
        }
    }
    void readClients()
    {
        std::fstream myfile( "customers.csv", std::ios_base::in);
        while(myfile)
        {
       
            std::string line;
            std::string word;
            getline(myfile,line);
            std::stringstream ss(line);
            int i=0;
            while(getline(myfile,line))
            {
                Client * c = new Client();
                std::stringstream sss(line);
                getline(sss, word,',');
                c->id=stoi(word);
                getline(sss, word,',');
                c->nombre=word;
                getline(sss, word,',');
                c->apellido=word;
                getline(sss, word,',');
                c->contacto=word;
                getline(sss, word,',');
                c->correo=word;
                getline(sss, word,',');
                c->numero=word;
                getline(sss, word,',');
                c->calle=word;
                getline(sss, word,',');
                c->numero=word;
                getline(sss, word,',');
                c->colonia=word;
                vectClientes.push_back(c);

            }
      
        }
        
    }
    void contactClients()
    {
        int i =0;
        while(i<vectClientes.size())
        {
            vectClientes[i]->contactar();
            i++;
        }
    }
};
Tienda *Tienda::instance = nullptr;


int main()
{
    Tienda * instance = Tienda::createInstance();
    instance->readClients();
    std::unique_ptr<Client> client = std::make_unique<Client>();
    std::unique_ptr<Command>  llamarC (new LlamarCommand(client.get()));
    std::unique_ptr<Command> mensajeC (new MensajeCommand(client.get()));
    std::unique_ptr<Command> correoC (new CorreoCommand(client.get()));
    instance->contactClients();
    
    return 0;
}
