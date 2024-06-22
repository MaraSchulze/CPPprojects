/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:10:53 by marschul          #+#    #+#             */
/*   Updated: 2024/03/19 12:39:24 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
MutantStack<T>::MutantStack() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other), _mirror(other._mirror) {}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {
    if (this != &other) {
        std::stack<T>::operator=(other);
		_mirror = std::vector<T>::operator=(other._mirror);
    }
    return *this;
}

template<typename T>
void MutantStack<T>::push(const T& element) {
	std::stack<T>::push(element);
	_mirror.push_back(element);
}

template<typename T>
void MutantStack<T>::pop() {
	std::stack<T>::pop();
	_mirror.pop_back();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return iterator(&_mirror[0]);
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return iterator(&_mirror[_mirror.size()]);
}

// ************ Inner class iterator begins here ***************

template<typename T>
MutantStack<T>::iterator::iterator() : _ptr(NULL) {
}

template<typename T>
MutantStack<T>::iterator::iterator(T* ptr) : _ptr(ptr) {
}

template<typename T>
MutantStack<T>::iterator::iterator(const iterator& other) : _ptr(other._ptr) {
}

template<typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator=(const iterator& other) {
    if (this != &other) {
        _ptr = other._ptr;
    }
    return *this;
}

template<typename T>
MutantStack<T>::iterator::~iterator() {
}

template<typename T>
bool MutantStack<T>::iterator::operator==(const iterator& other) const {
    return _ptr == other._ptr;
}

template<typename T>
bool MutantStack<T>::iterator::operator!=(const iterator& other) const {
    return _ptr != other._ptr;
}

template<typename T>
typename MutantStack<T>::iterator::reference MutantStack<T>::iterator::operator*() const {
    return *_ptr;
}

template<typename T>
typename MutantStack<T>::iterator::pointer MutantStack<T>::iterator::operator->() const {
    return _ptr;
}

template<typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator++() {
    ++_ptr;
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++(int) {
    ++_ptr;
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator--() {
    --_ptr;
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--(int) {
    --_ptr;
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator+(difference_type n) const {
    return iterator(_ptr + n);
}

template<typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator+=(difference_type n) {
    _ptr += n;
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator-(difference_type n) const {
    return iterator(_ptr - n);
}

template<typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator-=(difference_type n) {
    _ptr -= n;
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator::difference_type MutantStack<T>::iterator::operator-(const iterator& other) const {
    return _ptr - other._ptr;
}

template<typename T>
bool MutantStack<T>::iterator::operator<(const iterator& other) const {
    return _ptr < other._ptr;
}

template<typename T>
bool MutantStack<T>::iterator::operator>(const iterator& other) const {
    return _ptr > other._ptr;
}

template<typename T>
bool MutantStack<T>::iterator::operator<=(const iterator& other) const {
    return _ptr <= other._ptr;
}

template<typename T>
bool MutantStack<T>::iterator::operator>=(const iterator& other) const {
    return _ptr >= other._ptr;
}

template<typename T>
typename MutantStack<T>::iterator::reference MutantStack<T>::iterator::operator[](difference_type n) const {
    return *(_ptr + n);
}

