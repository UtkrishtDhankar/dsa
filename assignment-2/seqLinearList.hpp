#ifndef _SEQ_LINEAR_LIST
#define _SEQ_LINEAR_LIST 1

#include <iostream>
#include <string.h>

namespace cs202 {
    template<typename T>
    class LinearList{
      private:
        T* buffer_;
        unsigned int size_;
        unsigned int capacity_;
      public:
        // Default Constructor
        // Creates a zero sized LinearList
        LinearList();

        // Constructor with size as input
        LinearList(const int& isize);                   

        // Constuctor with size and default value as input
        LinearList(const int& isize, const T& ival);    

        // Default Destructor
        ~LinearList();                                  

        // Accessing an element of the LinearList using operator
        inline T& operator[](const int& i);         

        // Return the element in the list at position k
        inline T& at(const int& k);         

        // Appending an element to the LinearList
        // The asymptotic time complexity of this function
        // should be O(1)
        void push_back(const T& item);              

        // Returns true if LinearList is empty
        bool empty();                               

        // Returns the size of the LinearList
        unsigned int size();                                 

        // Returns the capacity of the LinearList
        unsigned int capacity();                                 

        // Fills all the elements with a default value
        void fill(const T& item);                   

        // Resizes the LinearList
        void resize(const int& n); 

        // Find the index of first occurence of an item in the list
        // Return size of list if item not found
        // 0-based indexing
        int find(const T& item);

        // Remove all occurences of an item in the list
        void erase(const T& item);

        // Remove the item in the list at position pos
        void erase_pos(const int& pos);

        // Insert item at position k
        void insert(const T& item, const int& k);

        // Iterator class for LinearList
        // This should be used to traverse the LinearList
        // See std::vector<T>::iterator for more understanding
        // on how iterators work
        class iterator{                             
          private:
            T* elem_;
          public:
            iterator();
            iterator(T* ptr);
            ~iterator();
            T& operator*();
            void operator=(T *ptr);
            void operator=(iterator iter);
            void operator++();
            void operator--();
            bool operator!=(T* ptr);
            bool operator==(T* ptr);
            bool operator!=(iterator iter);
            bool operator==(iterator iter);
            iterator operator+(int i);
            iterator operator-(int i);
        };
        iterator begin();                       
        iterator end();
  };
}

#endif  /* _SEQ_LINEAR_LIST */

