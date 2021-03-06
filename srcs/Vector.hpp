/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:20:37 by amunoz-p          #+#    #+#             */
/*   Updated: 2021/10/19 13:16:59 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../srcs/VectorIterator.hpp"
#include "../srcs/Algorithm.hpp"

namespace ft
{
    template <typename T, class Alloc = std::allocator<T> >
    class Vector
    {
        public:
                typedef Alloc   _allocator_type;
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
                _allocator_type _alloc;
                
                
        public:
                explicit Vector(const _allocator_type& alloc = _allocator_type())
                {
                    _alloc = alloc;
                    _container = _alloc.allocate(0);
                    _size = 0;  //u_nullptr?
                    _capacity = 0;
                }
                
                //fill  - with n elemnts each a copy of value
                explicit Vector(size_type n, const value_type& val = value_type(), const _allocator_type& alloc = _allocator_type())
                {
                    _alloc = alloc;
                    _container = _alloc.allocate(n);
                    _size = n;
                    _capacity = n;
                    for (size_type i = 0; i < n; i++)
                        _alloc.construct(_container + i, val);
                }

                //range - as many elemnts as the range first-last
                template <class InputIterator>
                Vector(InputIterator first, InputIterator last, const _allocator_type& alloc = _allocator_type(),
                typename std::enable_if<!std::is_same<InputIterator, int>::value>::type* = 0)
                {
                    size_type  n = 0;
                    for (InputIterator tmp = first; tmp != last; tmp++)
                        n++;
                    _alloc = alloc;
                    _size = n;
                    _capacity = n;
                    _container = _alloc.allocate(n);
                    for (size_type i = 0; i != n; i++)
                    {
                        _alloc.construct(_container + i, *first);
                        first++;
                    }
                }

                //copy - each elemnt in v
                Vector(const Vector& x)
                {
                    _alloc = x._alloc;
                    _capacity = x._capacity;
                    _size = x._size;
                    _container = _alloc.allocate(x._capacity);
                    for (size_type i = 0; i < x._size; i++)
                        _alloc.construct(_container + i, x[i]);
                }
                virtual ~Vector() 
                {
                    for (size_type i = 0; i < _size; i++)
                        _alloc.destroy(_container + i);
                    _alloc.deallocate(_container, _capacity);
                }

                Vector &operator=(const Vector &src)
                {
                    if (this == &src)
                        return (*this);
                    for (size_type i = 0; i < _size; i++)
                        _alloc.destroy(_container + i);
                    _alloc.deallocate(_container, _capacity);
                    if (src._size > _capacity)
                    {
                        _alloc.deallocate(_container, _capacity);
                        _capacity = src._capacity;
                        _container = _alloc.allocate(_capacity);
                    }
                    _size = src._size;
                    if (src._capacity == 0)
                        _capacity = src._capacity;
                    _container = _alloc.allocate(src._capacity);
                    for (size_type i = 0; i != src._size; i++)
                        _alloc.construct(_container + i, src[i]);
                    return (*this);
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

                void reserve(size_type n)
                {
                        if (n > _alloc.max_size())
                            throw std::length_error("n exceed max size!");
                        if (n > _capacity)
                        {
                            T *	new_vec = _alloc.allocate(n);
                            for (size_type i = 0; i != _size; i++)
                            {
                                _alloc.construct(new_vec + i, _container[i]);
                                _alloc.destroy(_container + i);
                            }
                            _alloc.deallocate(_container, _capacity);
                            _capacity = n;
                            _container = new_vec;
                        }
                }

                reference operator[](size_type n) {
                return this->_container[n];
                }

                const_reference operator[](size_type n) const {
                    return this->_container[n];        
                }

                reference at (size_type n) {
                    if (n >= _size)
                        throw std::out_of_range("Vector index out of range");
                    return this->_container[n];
                }

                const_reference at (size_type n) const {
                    if (n >= _size)
                        throw std::out_of_range("Vector index out of range");
                    return this->_container[n];    
                }
                
                reference front() {
                    return this->_container[0];
                }
                const_reference front() const {
                    return this->_container[0];
                }
                reference back() {
                    return this->_container[_size - 1];
                }
                const_reference back() const {
                    return this->_container[_size - 1];
                }

                void assign (size_type n, const value_type& val){
                    clear();
                    insert(begin(), n, val);
                }
                void assign(iterator first, iterator last) {
                    clear();
                    insert(begin(), first, last);
                }

                void push_back(const value_type& val) {
                    insert(end(), val);
                }   

                void pop_back() {
                    erase(end() - 1);
                }

                iterator insert(iterator position, const value_type& val)
                {
                    size_type init = 1;
                    this->insert(position, init, val);
                    return ++position;
                }

                void insert(iterator position, size_type n, const value_type& val)
                {
                    iterator it = this->begin();
                    difference_type index = 0;
                    
                    while (it != position)
                    {
                        ++it;
                        ++index;
                    }
                    if (!n)
                        return ;
                    if (_size + n > _capacity)
                        this->reserve(_size + n);
                    std::allocator<T> _alloc;
                    for (ptrdiff_t i = _size - 1; i >= (ptrdiff_t)index;  i--)
                    {
                        _alloc.construct(&_container[i + n], _container[i]);
                        _alloc.destroy(&_container[i]);
                    }
                    for (size_type i = index; i < index + n; i++)
                        _alloc.construct(&_container[i], val);
                    _size +=  n;
                }
                
                template <class InputIterator>
                void insert (iterator position, InputIterator first, InputIterator last,
                typename ft::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0)
                {
                    iterator it = this->begin();
                    size_type index = 0;
                    size_type n = last - first;
                    
                    if (_size + n > _capacity)
                        this->reserve(n + _size);
                    while (it != position)
                    {
                        ++it;
                        ++index;
                    }
                    if (!n)
                        return ;
                    for (ptrdiff_t i = _size - 1; i >= (ptrdiff_t)index;  i--)
                    {
                        _alloc.construct(&_container[i + n], _container[i]);
                        _alloc.destroy(&_container[i]);
                    }
                    for (iterator it2 = first; it2 != last; it2++)
                            _alloc.construct(&_container[index++], *it2);
                    _size = _size + n;
                }

                iterator erase (iterator position){
                   return (erase(position, position + 1));
                }

                iterator erase (iterator first, iterator last){
                    iterator it = this->begin();
                    size_type n = last - first;
                    size_type index = 0;
                    while (it != first){
                        index++;
                        it++;
                    }
                    if (n <= 0)
                        return last;
                    std::allocator<T> alloc;
                    for (size_t i = index; i < index + n; i++)
                        alloc.destroy(&_container[i]);
                    for (size_t i = index + n; i < _size; i++)
                    {
                        _alloc.construct(&_container[i - n], _container[i]);
                        _alloc.destroy(&_container[i]);
                    }
                    _size -= n;
                    return first;
                }

                void swap(Vector& x) {
                    std::swap(this->_container, x._container);
                    std::swap(this->_size, x._size);
                    std::swap(this->_capacity, x._capacity); 
                }
                
                void clear() {
                    erase(this->begin(), this->end());
                }
    };
    
    template<typename T>
    bool operator==(Vector<T> const &lhs, Vector<T> const &rhs) {
        return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template<typename T>
    bool operator!=(Vector<T> const &lhs, Vector<T> const &rhs) {
        return (!(lhs == rhs));
    }

    template<typename T>
    bool operator<(Vector<T> const &lhs, Vector<T> const &rhs) {
        return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template<typename T>
    bool operator<=(Vector<T> const &lhs, Vector<T> const &rhs) {
        return (!(rhs < lhs));
    }

    template<typename T>
    bool operator>(Vector<T> const &lhs, Vector<T> const &rhs) {
        return (rhs < lhs);
    }

    template<typename T>
    bool operator>=(Vector<T> const &lhs, Vector<T> const &rhs) {
        return (!(lhs < rhs));
    }

    template<typename T>
    void swap(Vector<T> &x, Vector<T> &y) {
        x.swap(y);
    }
}

#endif