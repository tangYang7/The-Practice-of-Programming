#ifndef STRING_CPP__
#define STRING_CPP__

#include <iostream>
class String
{
public:
    // B. operator <<, >>
    friend std::ostream & operator << (std::ostream &os, const String &s);
    friend std::istream & operator >> (std::istream &is, String &s);
    // 1. default constructor
    String();
    // 2. copy constructor
    String(const String &rhs);
    // 3. constructor with one parameter with type const char *
    String(const char *str);
    // 4. destructor
    ~String();
    // 5. size()
    int32_t size() const;
    // 6. c_str()
    const char* c_str() const;
    // 7. operator []
    char& operator[](int32_t index) ;
    const char& operator[](int32_t index) const;
    // 8. operator +=
    String& operator+=(const String &rhs);
    // 9. clear()
    void clear();
    // 10. operator =
    String& operator=(String rhs);
    // 11. swap()
    void swap(String &rhs);
    
private:
    char *str_ = nullptr;
    size_t size_ = 0, capacity_ = 0;
};

// A. relational operators (<, >, <=, >=, ==, !=)
bool operator<(const String &lhs, const String &rhs);
bool operator>(const String &lhs, const String &rhs);
bool operator<=(const String &lhs, const String &rhs);
bool operator>=(const String &lhs, const String &rhs);
bool operator==(const String &lhs, const String &rhs);
bool operator!=(const String &lhs, const String &rhs);

// C. operators +
String operator+(const String &lhs, const String &rhs);

#endif