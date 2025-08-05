#include "Serializer.hpp"

int main ()
{
    Data data;
    data.value = 42;

    std::cout << &data << std::endl;
    std::cout << Serializer::serialize(&data) << std::endl;
    std::cout << Serializer::deserialize(Serializer::serialize(&data)) << std::endl;
    std::cout << Serializer::deserialize(Serializer::serialize(&data))->value << std::endl;
}
