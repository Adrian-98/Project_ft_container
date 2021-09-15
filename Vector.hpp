/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:20:37 by amunoz-p          #+#    #+#             */
/*   Updated: 2021/09/15 12:37:49 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "VectorIterator.hpp"

template<typename T>
class Vector
{
    public:
            typedef size_t size_type;
            typedef T value_type;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef value_type* pointer;
            typedef const value_type* const_pointer;
            typedef VectorIterator<value_type> iterator;
            typedef VectorIterator<value_type const> const_iterator;
            typedef VectorReverseIterator<iterator> reverse_iterator;
            typedef VectorReverseIterator<const_iterator> const_reverse_iterator;
            typedef std::ptrdiff_t difference_type;
    private:
            pointer _container;
            size_type _size;
            size_type _capacity;
            
            void copy_construct(size_type idx, const_reference val) {
		    new(&this->_container[idx]) value_type(val);
	        }
    public:
            Vector(): _container(nullptr), _size(0), _capacity(0){}
            
            Vector(size_type n, const_reference val=value_type()):
            _container(nullptr), _size(0), _capacity(0) {
            insert(begin(), n, val);
            }
        
            Vector(iterator first, iterator last):
                _container(nullptr), _size(0), _capacity(0) {
                insert(begin(), first, last);      
            }
            
            Vector(const Vector& x):
                _container(nullptr), _size(0), _capacity(0) {
                this->_capacity = x._capacity;
                this->_size = x._size;
                this->_container = new T[_capacity + 1];
                for (size_t i = 0; i < this->_capacity; i++)
                    this->_container[i] = x._container[i];
            }
            
            iterator begin() {
            return iterator(this->_container);
            }

            const_iterator begin() const {
                return const_iterator(this->_container);
            }

            iterator end() {
                return iterator(this->_container + this->_size);
            }

            const_iterator end() const {
                return const_iterator(this->_container + this->_size);
            }

            reverse_iterator rbegin() {
                return reverse_iterator(this->end());
            }

            const_reverse_iterator rbegin() const {
                return const_reverse_iterator(this->end());
            }

            reverse_iterator rend() {
                return reverse_iterator(this->begin());
            }

            const_reverse_iterator rend() const {
                return const_reverse_iterator(this->begin());
            }

            size_type size() const{
                return (this->_size);
            }

            size_type max_size() const{
                return (ft::min((size_type) std::numeric_limits<difference_type>::max(),
						std::numeric_limits<size_type>::max() / sizeof(value_type)));
            }

            void resize (size_type n, value_type val = value_type()){
                if (n < _size)
                    erase(begin() + n, end());
                if (n > _capacity)
                    reserve(n);
                if (n > _size)
                    insert(end(), n - _size, val);    
            }
            
            size_type capacity() const {
            return this->_capacity;
            }
            
            bool empty() const {
                return (this->_size == 0);
            }

            void reserve(size_type n) {
                if (n > max_size)
                    throw std::length_error("Vector::resize");
                if (_capacity == 0)
                {
                    this->_container = new value_type[n];
                    _capacity = n;
                }
                else if (n > _capacity)
                {
                    pointer tmp = static_cast<pointer>(::operator new(sizeof(value_type) * n));
                    for (size_t i = 0; i < this->_size; i++)
                    {
                        new (&tmp[i]) value_type(this->_container[i]);
                        delete (this->_container);
                    }
                    _capacity = n;
                    _container = tmp;
                }
            }

            reference operator[](size_type n) {
            return this->_ptr[n];
            }

            const_reference operator[](size_type n) const {
                return this->_ptr[n];        
            }

            reference at (size_type n) {
                if (n >= _size)
                    throw std::out_of_range("Vector index out of range");
                return this->_ptr[n];
            }

            const_reference at (size_type n) const {
                if (n >= _size)
                    throw std::out_of_range("Vector index out of range");
                return this->_ptr[n];    
            }
            
            reference front() {
                return this->_ptr[0];
            }
            const_reference front() const {
                return this->_ptr[0];
            }
            reference back() {
                return this->_ptr[_size - 1];
            }
            const_reference back() const {
                return this->_ptr[_size - 1];
            }

            

            
};

#endif