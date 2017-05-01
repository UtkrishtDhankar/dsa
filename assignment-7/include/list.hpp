/*
 * queue.hpp
 *
 * functionality of a singly linked-list
 *
 * define your methods in coherence with the following
 * function signatures
 */

#ifndef LIST_HPP
#define LIST_HPP 1

#include <cstddef>
#include <stdexcept>

namespace cs202
{

template<class T>
struct node {
	node() {
		next_ = nullptr;
	}

	node(const T& data) : data_(data) {
		next_ = nullptr;
	}

	T data_;
	node* next_;
};

template<class T>
class list {
public:
	/*
		* Primary contructor.
		* Should construct an empty list.
		* Size of the created list should be zero.
		*/
	list() {
		first_ = nullptr;
		end_ = nullptr;
		size_ = 0;
	}

	/*
		* Secondary constructor.
		* Creates a new list which is a copy of the provided list.
		*/
	list(const list<T> & x) {
		size_ = 0;
		first_ = nullptr;
		end_ = nullptr;
		append(x);
	}

	/*
	 * Move constructor
	 */
	list(list<T>&& x) {
		size_ = x.size_;
		first_ = x.first_;
		end_ = x.end_;

		x.size_ = 0;
		x.first_ = x.end_ = nullptr;
	}

	/*
		* Frees all the memory acquired by the list.
		*/
	virtual ~list() {
		node<T>* cur = first_;
		while (cur != nullptr) {
			node<T>* next = cur->next_;
			delete cur;
			cur = next;
		}
	}

	void operator=(const list<T>& x) {
		node<T>* cur = first_;
		while (cur != nullptr) {
			node<T>* next = cur->next_;
			delete cur;
			cur = next;
		}

		size_ = 0;
		first_ = nullptr;
		end_ = nullptr;
		append(x);
	}

	void operator=(list<T>&& x) {
		size_ = x.size_;
		first_ = x.first_;
		end_ = x.end_;

		x.size_ = 0;
		x.first_ = x.end_ = nullptr;
	}

	bool has(const T& val) const {
		node<T>* cur = first_;
		bool found = false;
		while (cur != nullptr) {
			if (cur->data_ == val) {
				found = true;
				break;
			}

			cur = cur->next_;
		}

		return found;
	}

	/*
		* adds value at the end of the list.
		*/
	void append(const T& value) {
		node<T>* new_node = new node<T> (value);
		node<T>* end = get_end();

		if (end) {
			end->next_ = new_node;
			end_ = new_node;
		} else {
			first_ = new_node;
			end_ = first_;
		}

		size_++;
	}

	/*
		* Returns the length of the list.
		*/
	inline size_t length() const {
		return size_;
	}

	/*
		* Returns a boolean indicating whether the list is empty.
		*/
	inline bool empty() const {
		return (size_ == 0);
	}

	/*
		* Adds a value to the front of the list.
		*/
	void cons(const T& value) {
		node<T>* new_node = new node<T> (value);
		new_node->next_ = first_;

		first_ = new_node;

		if (size_ == 0) {
			end_ = new_node;
		}

		size_++;
	}

	/*
		* Removes the first occurence of the value from list.
		*/
	void remove(const T & x) {
		node<T>* cur = first_;
		node<T>* prev = nullptr;

		bool found = false;
		while (cur != nullptr) {
			if (cur->data_ == x) {
				found = true;
				break;
			}

			prev = cur;
			cur = cur->next_;
		}

		if (found) {
			if (prev) {
				prev->next_ = cur->next_;
			} else if (cur == first_) {
				first_ = cur->next_;
			}

			if (cur) {
				if (cur->next_ == nullptr) {
					end_ = prev;
				}
				delete cur;
			}
		}

		size_--;
	}

	/*
		* Appends the given list x at the end of the current list.
		*/
	void append(const list<T>& x) {
		node<T>* end = get_end();
		node<T>* cur = x.first_;

		if (!cur) {
			return;
		}

		if (end == nullptr) {
			node<T>* new_node = new node<T>(cur->data_);
			first_ = new_node;
			end = new_node;

			cur = cur->next_;
		}

		while (cur != nullptr) {
			node<T>* new_node = new node<T>(cur->data_);
			end->next_ = new_node;
			end = new_node;
			end_ = end;

			cur = cur->next_;
		}

		size_ += x.length();
	}

	T operator[](unsigned int i) {
		if (i >= size_) {
			throw std::range_error("Can't access that element, it's out of bounds");
		}

		node<T>* cur = first_;
		for (unsigned int j = 0; j < i; j++) {
			cur = cur->next_;
		}

		return cur->data_;
	}

	const T& at(unsigned int i) const {
		if (i >= size_) {
			throw std::range_error("Can't access that element, it's out of bounds");
		}

		node<T>* cur = first_;
		for (unsigned int j = 0; j < i; j++) {
			cur = cur->next_;
		}

		return cur->data_;
	}

	class iterator{
		private:
			node<T>* elem_;
		public:
			iterator() {elem_ = nullptr;}
			iterator(node<T>* ptr) {elem_ = ptr;}
			~iterator(){}
			T& operator*(){return elem_->data_;}
			void operator=(node<T> *ptr){elem_ = ptr;}
			void operator=(iterator iter){elem_ = iter.elem_;}
			iterator& operator++(){elem_ = elem_->next_; return *this;}
			iterator operator++(int){iterator it = *this; elem_ = elem_->next_; return it;}
			bool operator!=(node<T>* ptr){return (elem_ != ptr);};
			bool operator==(node<T>* ptr){return (elem_ == ptr);}
			bool operator!=(iterator iter){return (elem_ != iter.elem_);}
			bool operator==(iterator iter){return (elem_ == iter.elem_);}
	};

	iterator begin() {return iterator(first_);}
	iterator end() {return nullptr;}


protected:
	node<T>* first_;
	node<T>* end_;
	std::size_t size_;

	node<T>* get_end() {
		return end_;
	}
};
}

#endif
