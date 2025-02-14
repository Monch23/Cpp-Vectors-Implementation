#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

class Vector {
	public:
		Vector();
		Vector(const Vector &other);
		~Vector();
	private:
		size_t m_capacity;
		size_t m_size;
		int *m_data;
	public:
		void push_back(int value);
		void push_front(int value);
		int at(size_t index);
		size_t get_size(void) const;
		size_t get_capacity(void) const;
		void resize(size_t new_cap);
		int front(void) const;
		int back(void) const;
		bool is_empty(void) const;
		void shrink_to_fit(void);
		void insert(size_t index, int value);
		void erase(size_t index);
		void clear(void);
		void list_vector(void) const;
};

#endif