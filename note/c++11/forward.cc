#include <iostream>
#include <string>
#include <assert.h>

using namespace std;






/*
string overloaded( int &arg ) { return "lvalue"; }
string overloaded( int && arg ) { return "rvalue"; }
 
template< typename t >
void forwarding( t && arg ) {
    assert(overloaded(std::forward<t>(arg)) == "rvalue");
    assert(overloaded(std::move(arg)) == "rvalue"); // conceptually this would invalidate arg
    assert(overloaded(arg) == "lvalue");
}
 
int main() 
{
    forwarding( 5 );
    int x = 5;
    forwarding( x );

    return 0;
}
*/

void overloaded( int const &arg ) { std::cout << "lvalue" << endl;; }
void overloaded( int && arg ) { std::cout << "rvalue" << endl; }
 
/* "t &&" with "t" being template param is special, and  adjusts "t" to be
   (for example) "int &" or non-ref "int" so std::forward knows what to do. */

// && type parameter can receive lvalue and rvalue.
template<typename t>
void forwarding(t&& arg) 
{
    
    std::cout << "after std::forward, arg tye is : ";
    overloaded(std::forward<t>(arg));

    std::cout << "after std::move, arg type is : ";
    overloaded( std::move(arg)); // conceptually this would invalidate arg

    std::cout << "after simple passing, arg type is : ";
    overloaded(arg);
}
 
int main() {
    std::cout << "==> initial caller passes rvalue:\n";
    forwarding( 5 );
    std::cout << "==> initial caller passes lvalue:\n";
    int x = 5;
    forwarding( x );
}

/*
==> initial caller passes rvalue:
after std::forward, arg tye is : rvalue
after std::move, arg type is : rvalue
after simple passing, arg type is : lvalue
==> initial caller passes lvalue:
after std::forward, arg tye is : lvalue
after std::move, arg type is : rvalue
after simple passing, arg type is : lvalue
*/



















/*
namespace dehao_forward {


// at most cases, disable copy function.
  
template<typename T>
string print(T& t){
    cout << "lvalue" << endl;
    return "left-value";
}

template<typename T>
string print(T&& t){
    cout << "rvalue" << endl;
    return "right-value";
}


// if paramter is right value, will auto become left value.
template<typename T>
void test_right_value_parameter(T && v)
{
    assert(print(v) == "left-value");
    // assert(print(std::forward<T>(v)) == "right-value");
    assert(print(std::forward<T>(v)) == "left-value");
    assert(print(std::move(v)) == "right-value");
}

template<typename T> 
void test_left_value_parameter(T& v) {
    assert(print(v) == "left-value");
    assert(print(std::forward<T>(v)) == "right-value");
    assert(print(std::move(v)) == "right-value");
}


}







void test_forward() {

  using namespace dehao_forward;

  {
    cout << "------- directly test function -------------" << endl;
    string temp("shangdehao");
    assert(print(temp) == "left-value");
    assert(print(std::move(temp)) == "right-value");
    assert(print(std::forward<string>(temp)) == "right-value");
  }

  {
    cout << "------- test right value -------------" << endl;
    test_right_value_parameter("shangdehao");
    //test_right_value_parameter(std::move(temp));
  }

  {
    // test_right_value_parameter("shangdehao");
    cout << "--------------------" << endl;
  }

  {
    string temp("shangdehao");
    test_left_value_parameter(temp);
    cout << "--------------------" << endl;
  }

  {
    test_right_value_parameter(1);
    cout << "--------------------" << endl;
  }

}

*/






