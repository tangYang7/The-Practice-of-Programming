#include "String.h"
#include <iostream>

String::String() {
    str_ = new char[1];
    str_[0] = '\0';
}

String::String(const char *s) {
    size_ = 0;
    while(s[size_] != '\0'){
        ++size_;
    }
    capacity_ = size_;
    str_ = new char[capacity_];
    for(int32_t i = 0; i < size_; ++i){
        str_[i] = s[i];
    }
}

String::String(const String &rhs) {
    str_ = new char[rhs.size_];
    for(int32_t i = 0; i < rhs.size_; ++i){
        str_[i] = rhs.str_[i];
    }
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;
}

String::~String() {
    // cout << "destructor" << ": "<< *this << endl;
    delete[] str_;
}

int32_t String::size() const {
    return size_;
}

char& String::operator[](int32_t index) {
    return str_[index];
}

const char& String::operator[](int32_t index) const {
    return str_[index];
}

const char* String::c_str() const {
    return str_;
}

void String::swap(String &rhs){
    if(this == &rhs){
        return;
    }
    std::swap(str_, rhs.str_);
    std::swap(size_, rhs.size_);
    std::swap(capacity_, rhs.capacity_);
}

void swap(String &lhs, String &rhs){
    lhs.swap(rhs);
} 

// noted the self-assignment
String& String::operator=(String rhs) {
    this->swap(rhs);
    return *this;
}

String& String::operator+=(const String &rhs) {
    if(rhs.size_ + size_ > capacity_){
        capacity_ = rhs.size_ + size_;
        char *tmp = new char[capacity_];
        for(int32_t i = 0; i < size_; ++i){
            tmp[i] = str_[i];
        }
        delete[] str_;
        str_ = tmp;
    }
    for(int32_t i = 0; i < rhs.size_; ++i){
        str_[size_+i] = rhs.str_[i];
    }
    size_ += rhs.size_;
    return *this;
}

std::ostream& operator<<(std::ostream &os, const String &s) {
    for(int32_t i = 0; i < s.size_; ++i){
        os << s.str_[i];
    }
    return os;
}

std::istream& operator>>(std::istream &is, String &s) {
    char tmp[100];
    is >> tmp;
    s = tmp;
    return is;
}

// ! if failed to do new(), but we already did delete[]
// Create a new one, so that we could delete[] the old one
void String::clear() {
    char *tmp = new char[1];
    delete[] str_;
    str_ = tmp;
    str_[0] = '\0';
    size_ = 0, capacity_ = 0;
}

String operator+(const String &lhs, const String &rhs) {
    String tmp(lhs);
    tmp += rhs;
    return tmp;
}

bool operator<(const String &lhs, const String &rhs) {
    for(int32_t i = 0; i < lhs.size() && i < rhs.size(); ++i){
        if(lhs[i] == rhs[i]){
            continue;
        }
        return lhs[i] < rhs[i];
    }
    return lhs.size() < rhs.size();
}

bool operator==(const String &lhs, const String &rhs) {
    if(lhs.size() != rhs.size()){
        return false;
    }
    for(int32_t i = 0; i < lhs.size(); ++i){
        if(lhs[i] == rhs[i]){
            continue;
        }
        return false;
    }
    return true;
}

bool operator>(const String &lhs, const String &rhs) {
    return rhs < lhs;
}

bool operator<=(const String &lhs, const String &rhs) {
    return !(lhs > rhs);
}

bool operator>=(const String &lhs, const String &rhs) {
    return !(lhs < rhs);
}

bool operator!=(const String &lhs, const String &rhs) {
    return !(lhs == rhs);
}
