#include "vector.h"
#include <iostream>

Vector::Vector() {
	this->m_capacity = 1;
	this->m_size = 0;
	this->m_data = new int[1];
	if (m_data == nullptr) {
		std::cout << "Allocation failed" << std::endl;
	}
}

Vector::Vector(const Vector &other) {
	if ((this->m_data) == (other.m_data)) {
		this->m_data = other.m_data;	
	} else {
		this->m_capacity = other.m_capacity;
		this->m_size = other.m_size;
		this->m_data = new int[other.m_capacity];
	}
}

Vector::~Vector() {
	delete[] m_data;
	m_data = nullptr;
}

void Vector::resize(size_t new_cap) {
	if (m_data == nullptr) {
		return;
	}

	int *tmp_space = new int[new_cap];
	if (tmp_space == nullptr) {
		std::cout << "Allocation failed" << std::endl;
		return;
	}

	for (int i = 0; i < m_size; ++i) {
		tmp_space[i] = m_data[i];
	}

	delete[] m_data;
	m_data = tmp_space;
}

void Vector::push_back(int value) {
	if (m_size == m_capacity) {
		m_capacity *= 2;
		this->resize(m_capacity);
	}
	
	m_data[m_size++] = value;
	return;
}

void Vector::push_front(int value) {
	if (m_size == m_capacity) {
		m_capacity *= 2;
		this->resize(m_capacity);
	}
	
	for (int i = m_size; i > 0; --i) {
		m_data[i] = m_data[i - 1];
	}

	m_data[0] = value;
	++m_size;
	return;
}

int Vector::at(size_t pos) {
	if (pos >= 0) {
		std::cout << "Invalid index" << std::endl;
		return -1;
	}

	return m_data[pos];
}

size_t Vector::get_size(void) const {
	return m_size;
}

size_t Vector::get_capacity(void) const {
	return m_capacity;
}

bool Vector::is_empty(void) const {
	return (m_size == 0) ? true : false;
}

int Vector::front(void) const {
	return m_data[0];
}

int Vector::back(void) const {
	if (this->is_empty() == true) {
		std::cout << "Vector is empty" << std::endl;
		return -1;
	}

	return m_data[m_size - 1];
}

void Vector::shrink_to_fit(void) {
	if (this->is_empty() == true) {
		return;
	}

	m_capacity = m_size;
	this->resize(m_size);
}

void Vector::insert(size_t index, int value) {
	if (index > m_size) {
		return;
	}
	
	if (m_capacity == m_size) {
		m_capacity *= 2;
		resize(m_capacity);
	}

	if (index == 0) {
		this->push_front(value);
		return;
	}

	if (index == m_size - 1) {
		this->push_back(value);
		return;
	}

	for (int i = m_size; i > index; --i) {
		m_data[i] = m_data[i - 1];
	}

	m_data[index] = value;
	++m_size;
}

void Vector::erase(size_t index) {
	if (index >= m_size) {
		return;
	}

	for (int i = index; i < m_size - 1; ++i) {
		m_data[i] = m_data[i + 1];
	}

	--m_size;
}

void Vector::clear(void) {
	m_size = 0;
}

void Vector::list_vector(void) const {
	for (int i = 0; i < m_size; ++i) {
		std::cout << m_data[i] << std::endl;
	}
}
