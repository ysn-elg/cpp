#ifndef   ARRAY_HPP
# define  ARRAY_HPP

# include <exception>

template <typename T>
class Array {
private:
    unsigned int _n;
    T *array;
public:
    Array() : _n(0), array(NULL) {}
    Array(unsigned int n) : _n(n), array(new T[_n]()) { }
    Array(const Array &other) : _n(other._n) {
        array = new T[_n];
        for (unsigned int i = 0; i < _n; i++)
            array[i] = other.array[i];
    }
    Array &operator=(const Array &other) {
        if (this != &other) {
            if (this->_n != other._n) {
                if (this->array)
                    delete[] this->array;
                _n = other._n;
                this->array = new T[_n];
            }
            for (unsigned int i = 0; i < _n; i++)
                array[i] = other.array[i];
        }
        return *this;
    }
    ~Array() {
        delete[] array;
    }
    T &operator[](unsigned int index) {
        if (index >= _n)
            throw std::exception();
        return array[index];
    }
    const T &operator[](unsigned int index) const {
        if (index >= _n)
            throw std::exception();
        return array[index];
    }
    unsigned int size() const {
        return _n;
    }
};

#endif
