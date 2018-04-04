#include <vector>
#include <string>

virtual class Observer()
{
public:
  std::string name;
  Observer(std::string n){
    name = n;
  }
  virtual void update(std::String c){
    printf(" %s",c);
  }
}

virtual class Subject()
{
public:

  std:: vector <Observer> VO;
  std:: string name;
  std:: string message;
  void attach(Observer o){
    VO.push_back(o);
  }
  void detach(Observer o){
      for(Observer i: VO){
        if(i.name=o.name)
          VO.erase (i);
      }
  }
  void notifyAll(std::string c){
    for(Observer i : VO){
      i.update(c);
    }
  }
}
class ConcreteObvs : public Observer{
public:
  std::string name;
  ConcreteObvs(std::string s){
    name = s;
  }
  void publicar(std::string s)
    printf(" %s dice: %s\n",name,s);
}
class ConcreteSubject : public Subject{
public:
  std::string name;
}
int main(){
  
  
}
