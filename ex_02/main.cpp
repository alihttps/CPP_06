#include "Base.hpp"

int main ()
{
    srand(time(0));
    Base *p = generate();
    identify(p);
    identify(*p);
}