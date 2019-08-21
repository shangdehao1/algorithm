#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

/*

==>>> static_cast 

 1:  user-defined type 

     1) : parent <------> child 
          it can perform conversions between pointers to related classes, not only upcasts (from pointer-to-derived to pointer-to-base), 
          but also downcasts (from pointer-to-base to pointer-to-derived). 

          no checks

          No checks are performed during runtime to guarantee that the object being converted is in fact a full object of the destination type. 
          Therefore, it is up to the programmer to ensure that the conversion is safe. On the other side, it does not incur the overhead of the type-safety checks of dynamic_cast.

              class Base {};
              class Derived: public Base {};
              Base * a = new Base;
              Derived * b = static_cast<Derived*>(a);  // dangerous !!!!!

           This would be valid code, although b would point to an incomplete object of the class and could lead to runtime errors if dereferenced.
           Therefore, static_cast is able to perform with pointers to classes not only the conversions allowed implicitly, but also their opposite conversions.

     2) : no-relative transfer between classes.
          static will explicitly call a single-argument construction or a conversion operation


 2: build-in type 

     static_cast is also able to perform all conversions allowed implicitly (not only those with pointers to classes), and is also able to perform the opposite of these. 

     - Convert enum class values into integers or floating-point values.
          
     - void* <----> any pointer type
       !!!! Convert any type to void, evaluating and discarding the value.

 3: lvalue ---> rvalue 
      static_cast<type&&> xxx; // transfer left value to right value.

          

==>>> dynamic_cast

  1:  dynamic_cast can only be used with pointers and references to classes (or with void*). Its purpose is to ensure that the result of the type conversion points to a valid complete object of the destination pointer type.

       - upcast
         This naturally includes pointer upcast (converting from pointer-to-derived to pointer-to-base), in the same way as allowed as an implicit conversion.

       - downcast
          1): (convert from pointer-to-base to pointer-to-derived) polymorphic classes (those with virtual members) 
              if and only-if the pointed object is a valid complete object of the target type.

          2):  When dynamic_cast cannot cast a pointer because it is not a complete object of the required class, it returns a null pointer to indicate the failure. 
  
    If dynamic_cast is used to convert to a reference type and the conversion is not possible, an exception of type bad_cast is thrown instead.
    dynamic_cast can also perform the other implicit casts allowed on pointers: casting null pointers between pointers types (even between unrelated classes), 
      and casting any pointer of any type to a void* pointer.
    base class need virtual function, otherwise fault....



conclusion 

  derive class =======>>>>>>> base class
    because cpp object model, this conversion always is successfull no matter dynamic_cast or static_cast

  base class   =======>>>>>>> derive class
    static_cast : can't ensure rumtime safer.
    dynamic_cast : must need virtual table to support it.


// ===============================================================




*/


class Base {
public:
  string m_data_base{"Base"};

  virtual string who_am_i() {
    return "Base"; 
  }
};

class Derived : public Base {
public: 
  string m_data_derived{"Derived"};

  virtual string who_am_i() {
    return "Derived";
  }
};


struct XX {
};

struct shang {
};

struct dehao : public shang {
};


void test_static_cast_pointer() 
{
  // base --> derived
  {
    Base* base_ptr = new Base();

    Derived* derive_ptr;
    derive_ptr = static_cast<Derived*>(base_ptr); 

    assert(derive_ptr != nullptr); //####

    assert(derive_ptr->m_data_base == "Base");

    // =====>>>> !!!! for error memory address, it can be readed, but can't be written !!!! <<<<========

    assert(derive_ptr->m_data_derived != "Derived");

    // operate derive will lead to segment fault. But it can compiler sucessfully.
     auto& run_time_error = derive_ptr->m_data_derived;
    // run_time_error = "error";
  }

  // derived ---> base ----> derived
  {
    Base* base_ptr = new Derived();

    Derived* derive_ptr;
    derive_ptr = static_cast<Derived*>(base_ptr);

    assert(derive_ptr != nullptr);
    assert(derive_ptr->m_data_base == "Base");
    assert(derive_ptr->m_data_derived == "Derived");
  }

}

void test_dynamic_cast_pointer() 
{

  // base ---> derived
  {
    Base* base_ptr = new Base();

    Derived* derive_ptr = dynamic_cast<Derived*>(base_ptr);

    assert(derive_ptr == nullptr); 
  }

  // derived ---> base ---> derived
  {
    Base* base_ptr = new Derived();

    Derived* derive_ptr = dynamic_cast<Derived*>(base_ptr);

    assert(derive_ptr != nullptr);
    assert(derive_ptr->m_data_base == "Base");
    assert(derive_ptr->m_data_derived == "Derived");
  }

  // unrelated class conversion  
  {
    Base* base_ptr = new Derived();

    XX* xx = dynamic_cast<XX*>(base_ptr); 

    assert(xx == nullptr);
  }
}


void test_virtual_support_dynamic_cast() {

  // with virtual, base --> derive
  {
    Base* base_ptr = new Base();
    Derived* derived_ptr = dynamic_cast<Derived*>(base_ptr);
  
    assert(derived_ptr == nullptr);

  }

  // without virtual, base --> derive
  {
    shang* base_ptr = new shang();

    // compiler error : source type is not polymorphic
    // dehao* derived_ptr = dynamic_cast<dehao*>(base_ptr);

    // assert(derived_ptr == nullptr);
  }

  // static don't need virtual support
  {
    shang* base_ptr = new shang();

    dehao* derived_ptr = static_cast<dehao*>(base_ptr);

    assert(derived_ptr != nullptr);

  }
}



int main() {

  test_static_cast_pointer();

  test_dynamic_cast_pointer();

  test_virtual_support_dynamic_cast();

  return 0;
}


