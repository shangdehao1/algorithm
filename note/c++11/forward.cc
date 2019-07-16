#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

void overloaded( int const &arg ) { std::cout << "lvalue" << endl;; }
void overloaded( int && arg ) { std::cout << "rvalue" << endl; }
 
/* "t &&" with "t" being template param is special, and  adjusts "t" to be
   (for example) "int &" or non-ref "int" so std::forward knows what to do. */

// && type parameter can receive lvalue and rvalue.
template<typename t>
void forwarding(t&& arg) 
{
    
    std::cout << "after std::forward, param type is : ";
    overloaded(std::forward<t>(arg));

    std::cout << "after std::move, param type is : ";
    overloaded( std::move(arg)); // conceptually this would invalidate arg

    std::cout << "after simple passing, arg type is : ";
    overloaded(arg);
}
 
int main() {

    std::cout << "==> initial caller passes rvalue : " << std::endl;
    forwarding(5);

    std::cout << std::endl << "==> initial caller passes lvalue : " << std::endl;;
    int x = 5;
    forwarding(x);

    return 0;
}



