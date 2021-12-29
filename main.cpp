#include <iostream>
//статический полиморфизм
template <typename T>
struct Head
{
    void print_(){
       ((T*)this)->printsome();
    }
};

struct Back:Head<Back>
{
    void printsome(){
        std::cout<<"backend";
    }
};
struct Front:Head<Front>
{
    void printsome(){
        std::cout<<"front";
    }
};

int main()
{
Back obj1;
Front obj2;
obj1.print_();
obj2.print_();
	return 0;
}