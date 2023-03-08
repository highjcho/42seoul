/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:46:03 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/16 21:33:24 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
class Array {
	private:
		T* _arr;
		size_t _size;

	public:
		Array() : _arr(NULL), _size(0) {}

		Array(size_t n) : _size(n) {
			if (!_size)
				_arr = NULL;
			else
				_arr = new T[_size];
		}

		Array(const Array& obj) : _arr(NULL) {
			*this = obj;
		}

		Array& operator=(const Array& obj) {
			if (this != &obj) {
				if (_arr) {
					delete[] _arr;
					_arr = NULL;
				}
				_size = obj.size();
				if (_size)
					_arr = new T[_size];
				for (size_t i = 0 ; i < _size ; ++i)
					_arr[i] = obj._arr[i];
			}
			return *this;
		}

		~Array() {
			if (_size) {
				delete[] _arr;
				_arr = NULL;
				_size = 0;
			}
		}

		size_t size(void) const {
			return _size;
		}

		T& operator[](size_t i) {
			if (i >= _size)
				throw OutOfIdxException();
			return _arr[i];
		}

		const T& operator[](size_t i) const {
			if (i >= _size)
				throw OutOfIdxException();
			return _arr[i];
		}

		class OutOfIdxException : public std::exception {
			public:
				const char* what(void) const throw() {
					return "Out of Index";
				}
		};
};