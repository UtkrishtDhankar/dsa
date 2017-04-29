#ifndef _SEQ_LINEAR_LIST
#define _SEQ_LINEAR_LIST

#include<cstddef>
#include<stdexcept>
#include<utility>

namespace cs202 {
template<typename T>
	class LinearList{
		private:
			T* buffer_;
			size_t size_;
			size_t capacity_;

			static const size_t default_size_ = 8;

		public:
			// Default Constructor
			// Creates a zero sized LinearList
			LinearList();

			// Constructor with size as input
			LinearList(const size_t& isize);

			// Copy Constructor
			LinearList(const LinearList& other);

			// Move constructor
			LinearList(LinearList<T>&& other);

			// Constuctor with size and default value as input
			LinearList(const size_t& isize, const T& ival);

			// Default Destructor
			~LinearList();

			// Accessing an element of the LinearList using operator
			inline T& operator[](const int& i) {return buffer_[i];}

			// Copy assignment
			void operator=(const LinearList<T>& other);

			// Return the element in the list at position k
			inline const T& at(const int& k) const {return buffer_[k];}

			inline T copy_at(const int& k) const {return buffer_[k];}

			// Appending an element to the LinearList
			// The asymptotic time complexity of this function
			// should be O(1)
			void push_back(const T& item);

			// Returns true if LinearList is empty
			bool empty() const;

			// Returns the size of the LinearList
			size_t size() const;

			// Returns the capacity of the LinearList
			size_t capacity() const;

			// Fills all the elements with a default value
			void fill(const T& item);

			// Resizes the LinearList
			void resize(const size_t& new_size);

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
					iterator() {elem_ = nullptr;}
					iterator(T* ptr) {elem_ = ptr;}
					~iterator(){}
					T& operator*(){return *elem_;}
					void operator=(T *ptr){elem_ = ptr;}
					void operator=(iterator iter){elem_ = iter.elem_;}
					iterator& operator++(){elem_++; return *this;}
					iterator operator++(int){iterator it = *this; elem_++; return it;}
					iterator& operator--(){elem_--; return *this;}
					iterator operator--(int){iterator it = *this; elem_--; return it;}
					bool operator!=(T* ptr){return (elem_ != ptr);};
					bool operator==(T* ptr){return (elem_ == ptr);}
					bool operator!=(iterator iter){return (elem_ != iter.elem_);}
					bool operator==(iterator iter){return (elem_ == iter.elem_);}
					iterator operator+(int i){return iterator(elem_ + i);}
					iterator operator-(int i){return iterator(elem_ - i);}
			};

			iterator begin() {return iterator(&buffer_[0]);}
			iterator end() {return iterator(&buffer_[size_]);}
	};

	template<typename T>
	LinearList<T>::LinearList() {
		buffer_ = new T[default_size_];

		size_ = 0;
		capacity_ = default_size_;
	}

	template<typename T>
	LinearList<T>::LinearList(const size_t& isize) {
		buffer_ = new T[isize];

		size_ = 0;
		capacity_ = isize;
	}

	template<typename T>
	LinearList<T>::LinearList(const size_t& isize, const T& ival) {
		buffer_ = new T[isize];

		size_ = isize;
		capacity_ = isize;

		for (int i = 0; i < isize; i++) {
			buffer_[i] = ival;
		}
	}

	template<typename T>
	LinearList<T>::LinearList(const LinearList<T>& other) {
		capacity_ = other.capacity_;
		size_ = other.size_;

		buffer_ = new T[capacity_];
		for (int i = 0; i < size_; i++) {
			buffer_[i] = other.copy_at(i);
		}
	}

	template<typename T>
	void LinearList<T>::operator=(const LinearList<T>& other) {
		capacity_ = other.capacity_;
		size_ = other.size_;

		buffer_ = new T[capacity_];
		for (int i = 0; i < size_; i++) {
			buffer_[i] = other.copy_at(i);
		}
	}

	template<typename T>
	LinearList<T>::LinearList(LinearList<T>&& other) {
		capacity_ = other.capacity_;
		size_ = other.size_;

		buffer_ = other.buffer_;

		other.buffer_ = nullptr;
		other.capacity_ = 0;
		other.size_ = 0;
	}

	template<typename T>
	LinearList<T>::~LinearList() {
		if (buffer_)
			delete[] buffer_;
	}

	template<typename T>
	bool LinearList<T>::empty() const {
		return (size_ == 0);
	}

	template<typename T>
	size_t LinearList<T>::size() const {
		return size_;
	}

	template<typename T>
	size_t LinearList<T>::capacity() const {
		return capacity_;
	}

	template<typename T>
	void LinearList<T>::fill(const T& item) {
		for (auto& elem : *this) {
			elem = item;
		}
	}

	template<typename T>
	void LinearList<T>::resize(const size_t& new_size) {
		if (new_size < size_) {
			throw std::range_error("Can't resize to a size smaller than the current size.");
		}

		T* new_buffer = new T[new_size];
		for (int i = 0; i < size_; i++) {
			new_buffer[i] = buffer_[i];
		}

		delete buffer_;
		buffer_ = new_buffer;
		capacity_ = new_size;
	}

	template<typename T>
	void LinearList<T>::insert(const T &item, const int &k) {
		if (k >= capacity_) {
			resize(2 * capacity_);
		}    

		if (k < size_) {
			for (int i = size_; i >= k; i--) {
				buffer_[i] = std::move(buffer_[i - 1]);
			}

			buffer_[k] = item;
		} else if (k == size_ && k < capacity_) {
			buffer_[k] = item;
		}     size_++;
	}

	template<typename T>
	void LinearList<T>::push_back(const T& item) {
		insert(item, size_);
	}

	template<typename T>
	void LinearList<T>::erase_pos(const int& pos) {
		for (int i = pos; i < size_ - 1; i++) {
			buffer_[i] = buffer_[i + 1];
		}

		size_--;
	}

	template<typename T>
	void LinearList<T>::erase(const T& item) {

		for (int i = 0; i < size_; i++) {
			if (buffer_[i] == item) {
				erase_pos(i);
			}
		}
	}

	template<typename T>
	int LinearList<T>::find(const T& item) {
		for (int i = 0; i < size_; i++) {
			if (buffer_[i] == item) {
				return i;
			}
		}

		return size_;
	}
}
#endif  /* _SEQ_LINEAR_LIST */
