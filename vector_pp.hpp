/***** DEV PLAN *****
[ ] Read  https://medium.com/@vgasparyan1995/how-to-write-an-stl-compatible-container-fc5b994462c6
    * Idea: Allocate in chunks
        - [prepend chunk] next--> <--prev [append chunk]
        - Size of chunks double in each direction independently
        - On insert/delete, only break or shift a single chunk
        - Search for an index is linear in the number of chunks
        - Prepend until front space is consumed, then prepend chunk
        - Append until back space is consumed, then append chunk
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

#define INIT_BYTES    1024
#define EXPAND_FACTOR    2

template<typename T>
struct chunk_pp{
    
    /* Doubly-Linked List of Chunks */
    chunk_pp<T>* prev; // Points to previous chunk
    chunk_pp<T>* next; // Points to next     chunk
    u_short /**/ age; //- Number of doublings since "creation"

    /* Array Containing the Data */
    T* /**/ data; // ------ Points to memory allocated for array
    T* /**/ bgn; // ------- Points to the first element in the chunk
    T* /**/ end; // ------- Points to the last  element in the chunk
    size_t  bgnDex; // ---- `vector_pp` index represented by `bgn`
    size_t  len; // ------- Number of elements stored
    size_t  N; // --------- Array size
    size_t  front_space; // Array space at the front
    size_t  back_space; //- Array space at the back

    /* Constructors */
    chunk_pp( size_t N_ = 0 , size_t bytes = INIT_BYTES ){
        // NOTE: This method makes use of T's copy constructor
        prev = nullptr;
        next = nullptr;
        // data = new T( cpyElem );
        // If no length provided, calc length from size in bytes
    }

    bool copy_to( chunk_pp<T>* target ){}

    bool expand(){
        chunk_pp<T>* temp = new chunk_pp<T>( N * EXPAND_FACTOR );
        // Get the middle of the new array
        // Get the location of the first element
        // Copy the data centered on the new array
        // Connect the chunk to its neighbors
        // Erase the original chunk
    }

    bool insert_at_index( size_t index ){}
    bool remove_at_index( size_t index ){}
    bool split_at_index( size_t index , bool bias_left = 1 ){}
    
};

template<typename T>
class vector_pp{

/*** Public ***/ public:


/*** Protected ***/ protected:

};

#endif