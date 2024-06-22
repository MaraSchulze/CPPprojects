/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:02:29 by marschul          #+#    #+#             */
/*   Updated: 2024/03/15 10:46:04 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <cstddef>

template<typename T>
Array<T>::Array() : _size(0), _array(NULL) {}

template<typename T>
Array<T>::Array(int size) : _size(size), _array(new T[size]) {}

template<typename T>
Array<T>::Array(const Array& other) {
	_array = new T[other.size()];
	_size = other.size();
	for (int i = 0; i < _size; i++) {
		_array[i] = T(other._array[i]);
	}
}

template<typename T>
Array<T>::~Array() {
	delete[] _array;
}

template<typename T>
Array<T>&	Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] _array;
		_size = other.size();
		_array = new T[_size];
		for (int i = 0; i < _size; i++) {
			_array[i] = T(other._array[i]);
		}
	}
	return (*this);
}

template<typename T>
T&	Array<T>::operator[](int index) const {
	if (index < 0 || index >= _size)
		throw std::exception();
	else
		return _array[index];
}

template<typename T>
int	Array<T>::size(void) const {
	return _size;
}
