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

    private:
        int _size = 0;
        int _cap = 10;
        T* _ptr = nullptr;
    };
};


#endif // __VECTOR__