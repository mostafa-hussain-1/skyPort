#pragma once
template <typename D>

class skyPort_array {
private:
    D* data;
    int _size;
    int capacity;
public:
    skyPort_array() {
        _size = 0;
        capacity = 1;
        data = new D[capacity];
    }
    void push_back(D value) {
        if (_size == capacity)
        {
            capacity *= 2;
            D* newData = new D[capacity];
            for (int i = 0; i < _size; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[_size] = value;
        _size++;
    }
    void pop_back() {
        _size--;
    }
    bool empty() {
        return _size == 0;
    }
    void clear() {
        _size = 0;
    }
    void resize(int value) {
        _size = value;
    }
    D& operator[] (int index) {
        return data[index];
    }
    int size() {
        return _size;
    }
    void erase(int index) {
        D* newData = new D[capacity];
        int idx = 0;
        for (int i = 0; i < _size; i++, idx++)
        {
            if (i == index) idx++;
            newData[i] = data[idx];
        }
        delete[] data;
        data = newData;
        _size--;
    }
};