#include "Base.hpp"

Base *generate(void)
{
    int type = rand() % 3;
    Base *p = NULL;
    switch(type)
    {
        case 0 :
            p = new A();
            std::cout << "generated A" << std::endl;
            break;
        case 1 :
            p = new B();
            std::cout << "generated B" << std::endl;
            break;
        case 2 :
            p = new C();
            std::cout << "generated C" << std::endl;
            break;
        default :
            break;
    }
    return p;
}

void identify(Base* p)
{
    std::cout << "type : ";
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Base" << std::endl;
}

void identify(Base& p)
{
    std::cout << "type : ";
    try
    {
        dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch(...){}
    try
    {
        dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch(...){}
    try
    {
        dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch(...){}
    std::cout << "Unknown" << std::endl;
}

Base::~Base()
{

}