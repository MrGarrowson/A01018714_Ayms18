
#include<iostream>

int operacion(int a, int b, int (*f)(int,int))
{
    //return (*f)(a,b);
    return f(a,b);
}
 int suma (int a, int b)
{
    return a+b;
}

int resta ( int a , int b)
{
    return a-b;
}
int duplica (int a)
{
    return a+a;
}
typedef int(*f)(int,int);
f getOperacion(char o)
{
    if(o=='r') return resta;
    else return suma;
}

int (*getF(char o))(int a, int b)
{
    if(o=='r') return resta;
    else return suma;
}

template<class T,class Function>
T doTemplateFntion(T a,T b,Function f)
{
    return f(a,b);
};  
template <class Function>
Function getTemplateOperation(char s)
{
    if(s=='r') return resta;
    if(s=='s') return suma;
    if(s=='d') return duplica;
}
int main()
{
    std::cout<<operacion(542,241,suma)<<std::endl;
    std::cout<<operacion(542,150,resta)<<std::endl;

    std::cout <<getOperacion('s')(200,250)<<std::endl;
    std::cout <<getF('s')(200,250)<<std::endl;

    std::cout<<getTemplateOperation<int(*)(int,int)>('s')(2,2)<<std::endl;
    std::cout<<getTemplateOperation<int(*)(int,int)>('d')(50)<<std::endl;

}
