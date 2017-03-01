#ifndef SEQLINEARLIST_HPP
#define SEQLINEARLIST_HPP

#include <stdexcept>

template<class Item>
class LinearList
{
public:
		/* Default constructor.
		 * Should create an empty list that not contain any elements*/
		LinearList();

		/* This constructor should create a list containing MaxSize elements. You can intialize the elements with any values.*/
		LinearList(const int& MaxListSize);

    /* Copy constructor */
		LinearList(const LinearList<Item>& other);

		/* Destructor.
		 * Must free all the memory contained by the list */
		~LinearList();

		/* Indexing operator.
     		 * It should behave the same way array indexing does. i.e,
     		 * LinearList L;
     		 * L[0] should refer to the first element;
     		 * L[1] to the second element and so on.
     		 * */
		Item& operator[](const int& i); //return i'th element of list

		/* Returns true if the list is empty, false otherwise.
     		 * */
		bool isEmpty() const;

		/* Returns the actual length (number of elements) in the list.
     		 * */
		int length() const;

		/* Returns the maximum size of the list.
     		 * */
		int maxSize() const;

		/* Returns the k-th element of the list.
     * Use this instead of the operator if you want a const reference instead of a modifiable one
		 * */
		const Item& returnListElement(const int k) const;

		/* Set x to the k-th element and
		 * return true if k-th element is present otherwise return false.
		 * */
		bool find(const int k, Item& x);

		/* Search for x and
		 * return the position if found, else return 0. (actually returns -1 as 0 is a valid position)
		 * */
		int search(Item& x) const;

		/* Set x to the k-th element and delete that k-th element.
		 * */
		void deleteElement(const int  k, Item& x);

		/* Insert x after k-th element.
		 * */

    // CHANGED I made the insertion parameter a const so that constants
    // like 1, "hello!" etc can be added to the list without making variables
		void insert(const int  k, const Item& x);

private:
		int MaxSize;
		Item *element;    // 1D dynamic array
    int len;

    static int defaultMaxSize; // The size of a LinearList constructed by the default constructor

};

template<class Item>
LinearList<Item>::LinearList()
{
    MaxSize = defaultMaxSize;
    element = new Item[MaxSize];
    len = 0;
}

template<class Item>
LinearList<Item>::LinearList(const int& MaxListSize)
{
    MaxSize = MaxListSize;
    element = new Item[MaxSize];
    len = 0;
}


template<class Item>
LinearList<Item>::LinearList(const LinearList<Item>& other)
{
    MaxSize = other.maxSize();
    element = new Item[MaxSize];
    len = other.length();

    for (int i = 0; i < len; i++) {
        element[i] = other.returnListElement(i);
    }
}

template<class Item>
LinearList<Item>::~LinearList()
{
    delete element;
}

template<class Item>
Item& LinearList<Item>::operator[](const int& i)
{
    return element[i];
}

template<class Item>
bool LinearList<Item>::isEmpty() const
{
    return len == 0;
}

template<class Item>
int LinearList<Item>::length() const
{
    return len;
}

template<class Item>
int LinearList<Item>::maxSize() const
{
    return MaxSize;
}

template<class Item>
const Item& LinearList<Item>::returnListElement(const int k) const
{
    if (k < len && k >= 0) {
        return element[k];
    } else {
        throw std::runtime_error("Requested element is not in LinearList.");
    }
}

template<class Item>
bool LinearList<Item>::find(const int k, Item& x)
{
    if (k >= len || k < 0) {
        return false;
    } else {
        x = element[k];
        return true;
    }
}

template<class Item>
int LinearList<Item>::search(Item& x) const
{
    for (int i = 0; i < len; i++) {
        if (element[i] == x) {
            return i;
        }
    }

    return -1;
}

template<class Item>
void LinearList<Item>::deleteElement(const int k, Item& x)
{
    x = element[k];
    for (int i = k; i < len - 1; i++) {
        element[i] = element[i + 1];
    }

    len--;
}

template<class Item>
void LinearList<Item>::insert(const int k, const Item& x)
{
    if (k < 0 || k > MaxSize - 1) {
        throw std::range_error("cannot insert at requested position");
    }

    for (int i = len - 1; i >= k; i--) {
        element[i + 1] = element[i];
    }

    element[k] = x;
    len++;
}

#endif
