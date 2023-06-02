#ifndef STRING_CPP__
#define STRING_CPP__

#include <iostream>
class String
{
public:
    friend std::ostream & operator << (std::ostream &os, const String &s);
    friend std::istream & operator >> (std::istream &is, String &s);

    String();
    String(const String &rhs);
    String(const char *str);
    ~String();
    int32_t size() const;
    const char* c_str() const;
    char& operator[](int32_t index) ;
    const char& operator[](int32_t index) const;
    String& operator+=(const String &rhs);
    void clear();
    String& operator=(String rhs);
    void swap(String &rhs);
    
private:
    char *str_ = nullptr;
    size_t size_ = 0, capacity_ = 0;
};

bool operator<(const String &lhs, const String &rhs);
bool operator>(const String &lhs, const String &rhs);
bool operator<=(const String &lhs, const String &rhs);
bool operator>=(const String &lhs, const String &rhs);
bool operator==(const String &lhs, const String &rhs);
bool operator!=(const String &lhs, const String &rhs);

String operator+(const String &lhs, const String &rhs);

#endif