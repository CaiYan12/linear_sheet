#pragma once
#include <iostream>
#include <algorithm>

template<typename _type>
class LinearSheet {
private:
    int len;
    int capacity;
    _type* data;
    
    void resize_capacity(int new_capacity) {
        _type* new_data = new _type[new_capacity];
        for (int i = 0; i < len; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    LinearSheet() : len(0), capacity(0), data(nullptr) {}
    
    LinearSheet(int length) : len(length), capacity(length) {
        data = new _type[capacity];
    }
    
    ~LinearSheet() {
        delete[] data;
    }

    _type operator[](int index) const {
        if (index < 0 || index >= len) {
            std::cerr << "Index out of bounds!" << std::endl;
            exit(1);
        }
        return data[index];
    }
    
    int length() const {
        return len;
    }
    
    bool empty() const {
        return len == 0;
    }

    void push_back(_type value) {
        if (len >= capacity) {
            resize_capacity(capacity == 0 ? 1 : capacity * 2);
        }
        data[len++] = value;
    }
    
    void push_front(_type value) {
        if (len >= capacity) {
            resize_capacity(capacity == 0 ? 1 : capacity * 2);
        }
        for (int i = len; i > 0; i--) {
            data[i] = data[i - 1];
        }
        data[0] = value;
        len++;
    }
    
    void pop_back() {
        if (len > 0) len--;
    }
    
    void pop_front() {
        if (len == 0) return;
        for (int i = 0; i < len - 1; i++) {
            data[i] = data[i + 1];
        }
        len--;
    }
    
    void insert_at(_type value, int index) {
        if (index < 0 || index > len) return;
        if (len >= capacity) {
            resize_capacity(capacity == 0 ? 1 : capacity * 2);
        }
        for (int i = len; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        len++;
    }
    
    void erase_at(int index) {
        if (index < 0 || index >= len) return;
        for (int i = index; i < len - 1; i++) {
            data[i] = data[i + 1];
        }
        len--;
    }

    void sort_in_range(int start, int end) {
        if (start < 0 || end >= len || start > end) return;
        std::sort(data + start, data + end + 1);
    }
    
    void reverse_in_range(int start, int end) {
        if (start < 0 || end >= len || start > end) return;
        std::reverse(data + start, data + end + 1);
    }

    void print() const {
        for (int i = 0; i < len; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};