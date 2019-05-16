#include <iostream>
#include <memory>
#include <thread>
#include <unistd.h>

#include <assert.h>

using namespace std;



int main() {

    // construction
    {
        std::shared_ptr<int> temp_p1;
        assert(temp_p1.use_count() == 0);
        assert(temp_p1 == nullptr);

        std::shared_ptr<int> p(new int(123));
        assert(*p == 123);
        assert(p.use_count() == 1);

        // copy, +1
        {
            std::shared_ptr<int> temp_copy(p);
            assert(p.use_count() == 2 && *p == 123);
            assert(temp_copy.use_count() == 2 && *temp_copy == 123);
        }
    
        // this is not construction
        // assign, new managed object +1
        //         old managed object -1. if use_count == 0, release memory
        {
            shared_ptr<int> temp_1;
            shared_ptr<int> temp_2;
            temp_1 = p;
            temp_2 = p;

            assert(temp_1.use_count() == 3 && *temp_1 == 123);
            assert(temp_2.use_count() == 3 && *temp_2 == 123);
            assert(p.use_count() == 3 && *p == 123);

            shared_ptr<int> temp_3(new int(321));
            temp_2 = temp_3;

            assert(p.use_count() == 2 && *p == 123);
            assert(temp_1.use_count() == 2 && *temp_1 == 123);

            assert(temp_2.use_count() == 2 && *temp_2 == 321);
            assert(temp_3.use_count() == 2 && *temp_3 == 321);
        }

          // move, transfer owership
        {
            std::shared_ptr<int> temp_1(p);
            std::shared_ptr<int> temp_2(p);
            std::shared_ptr<int> temp_3(p);
            assert(temp_1.use_count() == 4 && *temp_1 == 123);

            shared_ptr<int> temp_move_1(std::move(temp_1));

            assert(temp_1.use_count() == 0 && temp_1 == nullptr);
            assert(temp_move_1.use_count() == 4 && *temp_move_1 == 123);


            shared_ptr<int> temp_move_2(new int(321), [](int*p) {std::cout << "temp_move_2 delete" << std::endl;});
            assert(temp_move_2.use_count() == 1 && *temp_move_2 == 321);

            // here, temp_move_2' resource will be released.
            temp_move_2 = std::move(temp_2);
            std::cout << "==============" << std::endl;

            assert(temp_move_2.use_count() == 4 && *temp_move_2 == 123);

            temp_move_2.reset();
            assert(temp_move_2.use_count() == 0 && temp_move_2 == nullptr);
            assert(p.use_count() == 3 && *p == 123);

            temp_move_1.reset(new int(999));
            assert(p.use_count() == 2);
        }
    }



    std::cout << endl;
    
    // thread safe
    {
        shared_ptr<int> temp_1(new int(12345));
        std::thread thread_1([temp_1](){
                std::cout << "thread_1 : " << temp_1.use_count() << std::endl;
                shared_ptr<int> xx(temp_1);
                std::cout << "xx : " << xx.use_count()<< std::endl;
                sleep(4);
                std::cout << "thread_1 over" << std::endl;
            });

        std::thread thread_2([temp_1]() {
            std::cout << "thread 2 : " << temp_1.use_count() << std::endl;
            sleep(4);
            std::cout << "thread_2 over" << std::endl;
        });

        sleep(2);
        assert(temp_1.use_count() == 3);
        sleep(4);
    

    }



    return 0;
}




/*

shared_ptr

Manages the storage of a pointer, providing a limited garbage-collection facility, possibly sharing that management with other objects.

Objects of shared_ptr types have the ability of taking ownership of a pointer and share that ownership: 
once they take ownership, the group of owners of a pointer become responsible for its deletion 
when the last one of them releases that ownership.

shared_ptr objects release ownership on the object they co-own as soon as they themselves are destroyed, 
or as soon as their value changes either by an assignment operation 
or by an explicit call to shared_ptr::reset. 
Once all shared_ptr objects that share ownership over a pointer have released this ownership, the managed object is deleted 
(normally by calling ::delete, but a different deleter may be specified on construction).

shared_ptr objects can only share ownership by copying their value: If two shared_ptr are constructed (or made) from the same (non-shared_ptr) pointer, they will both be owning the pointer without sharing it, causing potential access problems when one of them releases it (deleting its managed object) and leaving the other pointing to an invalid location.

Additionally, shared_ptr objects can share ownership over a pointer while at the same time pointing to another object. This ability is known as aliasing (see constructors), and is commonly used to point to member objects while owning the object they belong to. Because of this, a shared_ptr may relate to two pointers:

A stored pointer, which is the pointer it is said to point to, and the one it dereferences with operator*.
An owned pointer (possibly shared), which is the pointer the ownership group is in charge of deleting at some point, and for which it counts as a use.

Generally, the stored pointer and the owned pointer refer to the same object, but alias shared_ptr objects (those constructed with the alias constructor and their copies) may refer to different objects.

A shared_ptr that does not own any pointer is called an empty shared_ptr. A shared_ptr that points to no object is called a null shared_ptr and shall not be dereferenced. Notice though that an empty shared_ptr is not necessarily a null shared_ptr, and a null shared_ptr is not necessarily an empty shared_ptr.

shared_ptr objects replicate a limited pointer functionality by providing access to the object they point to through operators * and ->. For safety reasons, they do not support pointer arithmetics.

A related class, weak_ptr, is able to share pointers with shared_ptr objects without owning them.

*/








