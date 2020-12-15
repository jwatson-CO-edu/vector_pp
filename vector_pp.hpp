/***** DEV PLAN *****
[ ] Read  https://medium.com/@vgasparyan1995/how-to-write-an-stl-compatible-container-fc5b994462c6
[ ] Read  https://gcc.gnu.org/wiki/Visibility
[ ] /usr/include/c++/9/bits/stl_list.h
    [ ] What is the underlying element?
[ ] /usr/include/c++/9/bits/stl_vector.h
    [ ] Is there an underlying element?
    [ ] How much is allocated when?
    [ ] What does access look like
[ ] /usr/include/c++/9/bits/stl_list.h
    [ ] What is the underlying element?
    [ ] How does append work?
    [ ] How does prepend work?
 ********************/

#ifndef VECTOR_PP_H
#define VECTOR_PP_H

template<typename T>
struct element_pp{
    
    /* Doubly-Linked List */
    T* prev;
    T* next;
    T* data;

    /* Constructors */
    element_pp( const T& cpyElem ){
        // NOTE: This method makes use of T's copy constructor
        prev = nullptr;
        next = nullptr;
        data = new T( cpyElem );
    }
};

template<typename T>
class vector_pp{

/*** Public ***/ public:


/*** Protected ***/ protected:

};

#endif