

class Aint;
class Proxy
{
  Aint *a;
  int idx;
public:
  Proxy(Aint *a int idx)
  {
    this->a = a;
    this->idx = idx;
  
  }
  
}
class Aint 
{
  int nElem;
  int *arr;

  public:
    Aint()
    {
      arr = new int[100];
    }
    Proxy operator[](int idx)
    {
      if (idx < 0)
        puts("indices negativos no válidos");
      return new Proxy (this, idx);
    }
    int& setGet(int idx)
    {
      return array[idx];
    }
}
void Proxy::operator=(int value)
{
  if(value < 0)
    puts("no hay negativos");
  else
    a->setGet(idx) = value;
}
int main ()
{
  Aint a;
  a[-5]=1;
}
