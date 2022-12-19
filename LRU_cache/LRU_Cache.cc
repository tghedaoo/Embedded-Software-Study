#include "dll.hh"

int main()
{
    DLL list_1;

    list_1.create_n_node_dll(10);
    list_1.print_dll();
    std::cout << list_1.dll_capacity() << std::endl;
    
    return 0;
}