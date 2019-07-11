#include <iostream>
#include <string>
#include <assert.h>

using namespace std;


/*

static_cast can perform conversions between pointers to related classes, not only upcasts (from pointer-to-derived to pointer-to-base), 
but also downcasts (from pointer-to-base to pointer-to-derived). 

 !!! No checks are performed during runtime to guarantee that the object being converted is in fact a full object of the destination type. 
Therefore, it is up to the programmer to ensure that the conversion is safe. On the other side, it does not incur the overhead of the type-safety checks of dynamic_cast.

      class Base {};
      class Derived: public Base {};
      Base * a = new Base;
      Derived * b = static_cast<Derived*>(a); 


This would be valid code, although b would point to an incomplete object of the class and could lead to runtime errors if dereferenced.

Therefore, static_cast is able to perform with pointers to classes not only the conversions allowed implicitly, but also their opposite conversions.

static_cast is also able to perform all conversions allowed implicitly (not only those with pointers to classes), and is also able to perform the opposite of these. It can:
Convert from void* to any pointer type. In this case, it guarantees that if the void* value was obtained by converting from that same pointer type, the resulting pointer value is the same.
Convert integers, floating-point values and enum types to enum types.

Additionally, static_cast can also perform the following:

 - Explicitly call a single-argument constructor or a conversion operator.

 - Convert to rvalue references.

 - Convert enum class values into integers or floating-point values.

 - Convert any type to void, evaluating and discarding the value.


// ===============================================================

dynamic_cast

dynamic_cast can only be used with pointers and references to classes (or with void*). Its purpose is to ensure that the result of the type conversion points to a valid complete object of the destination pointer type.

  - upcast
    This naturally includes pointer upcast (converting from pointer-to-derived to pointer-to-base), in the same way as allowed as an implicit conversion.

  - downcast
     (convert from pointer-to-base to pointer-to-derived) polymorphic classes (those with virtual members) if -and only if- the pointed object is a valid complete object of the target type.

key point : 

1 : When dynamic_cast cannot cast a pointer because it is not a complete object of the required class, it returns a null pointer to indicate the failure. 

2 : If dynamic_cast is used to convert to a reference type and the conversion is not possible, an exception of type bad_cast is thrown instead.

3 : dynamic_cast can also perform the other implicit casts allowed on pointers: casting null pointers between pointers types (even between unrelated classes), and casting any pointer of any type to a void* pointer.


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


void test_static_cast_pointer() {

  // upcast : conversion from base pointer to derive pointer
  // base pointer point to base object. !!!!! dangerous
  {
    Base* base_ptr = new Base();

    // derive_ptr currently point to in-complete object.
    Derived* derive_ptr;
    derive_ptr = static_cast<Derived*>(base_ptr); 

    assert(derive_ptr != nullptr); // #####

    // base data is right
    assert(derive_ptr->m_data_base == "Base");

    // derive data is wrong.
    assert(derive_ptr->m_data_derived != "Derived");

    // operate derive will lead to segment fault. But it can compiler sucessfully.
    auto& run_time_error = derive_ptr->m_data_derived;
    // run_time_error = "error";
  }


  // upcast : conversion from base pointer to derive pointer
  // base pointer point to derive object !!!! perfect, and dynamic_cast can't do this.
  {
    Base* base_ptr = new Derived();

    Derived* derive_ptr;
    derive_ptr = static_cast<Derived*>(base_ptr);

    assert(derive_ptr != nullptr);

    // base data is right
    assert(derive_ptr->m_data_base == "Base");

    // child data is right
    assert(derive_ptr->m_data_derived == "Derived");
  }

}

void test_dynamic_cast_pointer() {

  {
    Base* base_ptr = new Base();

    Derived* derive_ptr = dynamic_cast<Derived*>(base_ptr);
    assert(derive_ptr == nullptr); // #####
  }

  {
    Base* base_ptr = new Derived();
  
    Derived* derive_ptr = dynamic_cast<Derived*>(base_ptr);
    assert(derive_ptr != nullptr);
  }


  {


  }


}



int main() {

  test_static_cast_pointer();

  test_dynamic_cast_pointer();

  return 0;
}


