#ifndef __VECTOR__
#define __VECTOR__
#include <iostream>

namespace myStl {
    template <typename T>
    class Vector {
    public:
        Vector(const int& size) : _cap(size * 2), _ptr(new T[_cap]) {
            for (int i = 0; i < _cap; ++i) {
                _ptr[i] = 0;
            }
        }
        Vector(std::initializer_list<T> vec) : _size(vec.size()), _cap(_size * 2), _ptr(new T[_cap]) {
            std::copy(vec.begin(), vec.end(), this->_ptr);
        }
        Vector() : _ptr(new T[_cap]) {}
        ~Vector() {
            delete[] _ptr;
            _ptr = nullptr;
        }
        T& operator[](const int& index) {
            try {
                if (index < 0 || index > _cap) {}
            }
            catch(const std::exception& e) {
                std::cerr << e.what() << '\n';

            }
            return _ptr[index];
            
        }
    public:
        void push_back(const T& elem) {
            if (_size >= _cap) {
                _cap *= 2;
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

        void push_front(const T& elem) {
            if (_size >= _cap) {
                _cap *= 2;
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
            for (int i = 0; i < _size; ++i) {
                _ptr[i + 1] = _ptr[i];
            }
            _ptr[0] = elem;
            ++_size;
        }

        void pop_front() {
            for (int i = 0; i < _size - 1; ++i) {
                _ptr[i] = _ptr[i + 1];
            }
            --_size;
        }

        void insert(const int& index, const T& val) {
            if (index < 0 || index > _cap) {
                std::cout << "Error. Wrong operation." << std::endl;
            }
            else {
                if (index == _cap || _size == _cap) {
                    _cap *= 2;
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

        int getSize() const {
            return _size;
        }
        int getCap() const {
            return _cap;
        }
    private:
        int _size = 0;
        int _cap = 10;
        T* _ptr = nullptr;
    };
};


#endif // __VECTOR__