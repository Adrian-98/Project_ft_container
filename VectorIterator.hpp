/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:21:29 by amunoz-p          #+#    #+#             */
/*   Updated: 2021/09/14 12:28:50 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

#include <iostream>
#include <limits>
#include <cstring>

template <typename T>
class VectorIterator{
    public: 
            typedef T value_type;
            typedef value_type* pointer;
            typedef const value_type* const_pointer;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef std::ptrdiff_t difference_type;
	private:
			pointer _ptr;
	public:
			VectorIterator(): _ptr(NULL){}
	        VectorIterator(const pointer &ptr): _ptr(ptr) { }
            VectorIterator(const VectorIterator &c): _ptr(c._ptr) { }
            
            virtual ~VectorIterator() {};
            VectorIterator &operator=(const VectorIterator &c) {this->_ptr = c._ptr; return *this;}

            reference operator*() const { return *_ptr; }
            const_reference operator*() { return *_ptr; }
            pointer operator->() const { return _ptr; }
            const_pointer operator->() { return _ptr; }
            reference operator[] (const difference_type& _n) const { return _ptr[_n]; }
            const_reference operator[] (const difference_type& _n) { return _ptr[_n]; }
            VectorIterator& operator++() {
                ++_ptr;
                return *this;
            }
            
            VectorIterator operator++(int) { return VectorIterator(_ptr++); }
            
            VectorIterator& operator--() {
                --_ptr;
                return *this;
            }
            
            VectorIterator operator--(int) { return VectorIterator(_ptr--); }
            
            VectorIterator operator+=(difference_type _n) { _ptr += _n; return *this; }

            VectorIterator operator+(difference_type _n) { return VectorIterator(_ptr + _n); }

            VectorIterator operator-=(difference_type _n) { _ptr -= _n; return *this; }

            VectorIterator operator-(difference_type _n) { return VectorIterator(_ptr - _n); }

            bool operator==(const VectorIterator &c) { return (this->_ptr == c._ptr); }
            bool operator!=(const VectorIterator &c) { return (this->_ptr != c._ptr); }
            bool operator<(const VectorIterator &c) { return (this->_ptr < c._ptr); }
            bool operator<=(const VectorIterator &c) { return (this->_ptr <= c._ptr); }
            bool operator>(const VectorIterator &c) { return (this->_ptr > c._ptr); }
            bool operator>=(const VectorIterator &c) { return (this->_ptr >= c._ptr); }

            difference_type operator-(VectorIterator const &other) const {
                return (this->_ptr - other._ptr);
            }
};

template <typename It>
class VectorReverseIterator: public It
{
	public:
		using typename It::value_type;
		using typename It::pointer;
		using typename It::const_pointer;
		using typename It::reference;
		using typename It::const_reference;
		using typename It::difference_type;
	
    private: 
        It _base;
        VectorReverseIterator();
        
	public	:
		VectorReverseIterator(It base): _base(base){}
		VectorReverseIterator(const VectorReverseIterator &x) : _base(x._base){}

	    ~VectorReverseIterator(){}
		
		VectorReverseIterator& operator=(VectorReverseIterator const &x) {this->_base = x._base; return *this; }
		

		reference operator*()
		{
			It tmp(_base);
			return (*--tmp);
		}

		const_reference operator*() const {
			It tmp(_base);
			return (*--tmp);
		}
		pointer operator->() {
			It tmp(_base);
			return (&*--tmp);
		}
		const_pointer operator->() const {
			It tmp(_base);
			return (&*--tmp);
		}
		VectorReverseIterator operator++(int) {
			VectorReverseIterator tmp(_base);
			operator++();
			return (tmp);
		}
		It &operator++() {
			return (this->It::operator--());
		}
		VectorReverseIterator operator--(int) {
			VectorReverseIterator tmp(_base);
			operator--();
			return (tmp);
		}
		It &operator--() {
			return (this->It::operator++());
		}
        
        bool operator==(const VectorReverseIterator &c) { return this->_base == c._base; }
        bool operator!=(const VectorReverseIterator &c) { return (this->_base != c._base); }
        bool operator<(const VectorReverseIterator &c) { return (this->_base > c._base); }
        bool operator<=(const VectorReverseIterator &c) { return (this->_base >= c._base); }
        bool operator>(const VectorReverseIterator &c) { return (this->_base < c._base); }
        bool operator>=(const VectorReverseIterator &c) { return (this->_base <= c._base); }

};

template<class value_type>
bool equal(value_type const &a, value_type const &b) {
	return (a == b);
}


#endif