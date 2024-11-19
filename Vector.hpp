#ifndef __VECTOR__
#define __VECTOR__
#include <iostream>
#include <algorithm>
// #include "Exception.hpp"

namespace myStl {
    
    class MyException : public std::exception {
    public:
        MyException(const std::string message) : _message(message) {}
        ~MyException() {}

        const char* what() const noexcept override {
            return _message.c_str();
        }
    private:
        std::string _message;
    };

    template <typename T>
    class Vector {
    public:
         // --ITERATOR FOR VECTOR--
        class Iterator {
            public:
                // PARAMETERIZED CONSTRUCTOR
                Iterator(T* ptr) : _ptr(ptr) {}

                // DEFAULT CONSTRUCTOR
                Iterator() : _ptr(nullptr) {}

                // --METHODS--
                T& operator*() {
                    return *_ptr;
                }
                
                T* operator->() {
                    return _ptr;
                }

                Iterator& operator=(const Iterator& oth) {
                    this->_ptr = oth._ptr;
                    return *this;
                }

                Iterator& operator++() {          //prefix
                    ++_ptr;
                    return *this;
                }
                
                Iterator& operator--() {          //prefix
                    --_ptr;
                    return *this;
                }
                
                Iterator& operator--(int) {       //postfix
                    Iterator temp = *this;
                    --_ptr;
                    return temp;
                }

                Iterator& operator++(int) {       //postfix
                    Iterator temp = *this;
                    ++_ptr;
                    return temp;
                } 

                Iterator operator+(unsigned int n) {
                    Iterator t = *this;
                    for (int i = 0; i < n; ++i) {
                        ++t;
                    }
                    return t;
                }

                Iterator& operator+=(unsigned int n) {
                    for (int i = 0; i < n; ++i) {
                        ++(*this);
                    }
                    return *this;
                }

                Iterator operator-(unsigned int n) {
                    Iterator t = *this;
                    for (int i = 0; i < n; ++i) {
                        --t;
                    }
                    return t;
                }

                Iterator& operator-=(unsigned int n) {
                    for (int i = 0; i < n; ++i) {
                        --(*this);
                    }
                    return *this;
                }

                bool operator==(const Iterator& oth) {
                    return this->_ptr == oth._ptr;
                }

                bool operator!=(const Iterator& oth) {
                    return this->_ptr != oth._ptr;
                }

                bool operator<(const Iterator& oth) {
                    return this->_ptr < oth._ptr;
                }

                bool operator>(const Iterator& oth) {
                    return this->_ptr > oth._ptr;
                }

                bool operator>=(const Iterator& oth) {
                    return this->_ptr >= oth._ptr;
                }

                bool operator<=(const Iterator& oth) {
                    return this->_ptr <= oth._ptr;
                }

                T& operator[](int i) {
                    Iterator tmp = *this;
                    tmp += i;
                    return *tmp;
                }
            private:
                T* _ptr;
        };


        //PARAMETERIZED CONSTRUCTOR
        Vector(const int& size) : _size(size), _cap(size * 2), _ptr(new T[_cap]) {
            for (int i = 0; i < _size; ++i) {
                _ptr[i] = 0;
            }
        }

        // INITIALIZER LIST CONSTRUCTOR
        Vector(std::initializer_list<T> vec) : _size(vec.size()), _cap(_size * 2), _ptr(new T[_cap]) {
            std::copy(vec.begin(), vec.end(), this->_ptr);
        }

        // DEFAULT CONSTRUCTOR
        Vector() : _ptr(new T[_cap]) {}
        
        // COPY CONSTRUCTOR
        Vector(const Vector<T>& other) {
            this->_size = other._size;
            this->_cap = other._cap;

            this->_ptr = new T[_cap];

            for (int i = 0; i < other._size; ++i) {
                this->_ptr[i] = other._ptr[i];
            }
        }

        // MOVE CONSTRUCTOR
        Vector(Vector<T>&& other) {
            this->_size = other._size;
            this->_cap = other._cap;

            other._size = 0;
            other._cap = 0;

            this->_ptr = other._ptr;
            other._ptr = nullptr;
        }

        // COPY ASSIGNMENT

        Vector<T>& operator=(const Vector<T>& other) {
            if (this != &other) {
                this->_size = other._size;
                this->_cap = other._cap;

                delete[] _ptr;

                _ptr = new T[_cap];

                for (int i = 0; i < other._size; ++i) {
                    this->_ptr = other._ptr[i];
                }
            }
            return *this;
        }

        //  MOVE ASSIGNMENT
        Vector<T>& operator=(Vector<T>&& other) {
            if (this != &other) {
                delete[] _ptr;
                
                this->_size = other._size;
                this->_cap = other._cap;
                this->_ptr = other._ptr;

                other._size = 0;
                other._cap = 0;
                other._size = nullptr;
            }
        }

        // DESTRUCTOR  
        ~Vector() {
            delete[] _ptr;
            _ptr = nullptr;
        }

       
    private:

        void largerCap() {
            _cap = _cap * 2;
            T* temp = new T[_cap];
            for (int i = 0; i < _size; ++i) {
                temp[i] = _ptr[i];
            } 
            for (int i = 0; i < _cap; ++i) {
                temp[i] = 0;
            }
            delete[] _ptr;
            _ptr = temp;
            temp = nullptr;
        }
    
    public:

        // SUBSCRIPT OPERATOR
        T& operator[](const int& index) {
            return _ptr[index];
        }

        // --METHODS--
        Iterator begin() {
            return Iterator(this->data());
        }

        Iterator end() {
            return Iterator(this->data() + this->_size);
        }

        T& front() {
            if (_size) {
                return _ptr[0];
            }
            else {
                std::cout << "Wrong Operation!" << std::endl;
                exit(0);
            }
        }

        T& back() {
            if (_size) {
                return _ptr[_size - 1];
            }
            else {
                std::cout << "Wrong Operation!" << std::endl;
                exit(0);
            }
        }
        
        T* data() {
            return _ptr;
        }



        T& at(const int& index) {
            if (index < 0 || index > _cap) {
                throw std::out_of_range("Error! Your index is out of range.");
            }
            return _ptr[index];
        }

        void push_back(const T& elem) {
            if (_size >= _cap) {
                largerCap();
            }
            _ptr[_size++] = elem;
        }

        void pop_back() {
            if (_size == 0) {
                std::cout << "Error. Wrong operation." << std::endl;
            }
            else {
                _ptr[--_size] = 0;
            }
        }


        void insert(const int& index, const T& val) {
            if (index < 0 || index > _cap) {
                throw MyException("Error! Wrong operation.");
            }
            else {
                if (index == _cap || _size == _cap) {
                    largerCap();
                }
                if (index > _size) {
                    _ptr[index] = val;
                    _size = index;
                }
                else {
                    for (int i = index; i < _size; ++i) {
                        _ptr[i + 1] = _ptr[i];
                    }
                    _ptr[index] = val;
                    ++_size;
                }
            }
        }

        void emplace(Iterator pos, const T& val) {
            if (pos < this->begin() || pos > this->end()) {
                throw MyException("Invalid position");
            }
            else {
                if (_size + 1 >= _cap) {
                    largerCap();
                }
                T* tmp = new T[_size + 1];

                Iterator it(_ptr);
                Iterator p(tmp);

                for (; it < pos; ++it) {
                    *p = *it;
                    ++p;
                }
                *p = val;
                ++p;
                for (; it < this->end(); ++it) {
                    *p = *it;
                    ++p;
                }

                delete[] _ptr;
                _ptr = tmp;
                tmp = nullptr;
                ++_size;
            }
        }

        void erase(Iterator pos) {
            if (pos < this->begin() || pos > this->end()) {
                throw MyException("Invalid position");
            }

            Iterator it = pos;
            ++it;

            for (; it < this->end(); ++it, ++pos) {
                *pos = *it;
            }
            --_size;
        }

        void clear() {
            _size = 0;
            _cap = 0;
            delete[] _ptr;
            _ptr = nullptr;
        }
        
        void swap(Vector<T>& oth) {
            std::swap(this->_size, oth._size);
            std::swap(this->_cap, oth._cap);
            std::swap(this->_ptr, oth._ptr);
        }

        void printVec() {
            for (int i = 0; i < _size; ++i) {
                std::cout << _ptr[i] << " ";
            }
        }

        void resize(const int& count) {
            if (count <= _size) {
                return;
            }
            else if (count >= _cap) {
                largerCap();
            }
            for (int i = _size; i < _cap; ++i) {
                _ptr[i] = 0;
            }
            _size = count;
        }

        void reserve(const int& newCap) {
            if (newCap <= _cap) {
                return;
            }
            _cap = newCap;
            T* temp = new T[_cap];
            for (int i = 0; i < _size; ++i) {
                temp[i] = _ptr[i];
            }
            for (int i = _size; i < _cap; ++i) {
                temp[i] = 0;
            }
            delete[] _ptr;
            _ptr = temp;
            temp = nullptr;
        }
        
        bool empty() {
            return _size == 0;
        }

        int getSize() const {
            return _size;
        }
        
        int getCap() const {
            return _cap;
        }
        
        int maxSize() {
            return 1073741823;
        }
    private:
        int _size = 0;
        int _cap = 10;
        T* _ptr = nullptr;
    };
};


#endif // __VECTOR__