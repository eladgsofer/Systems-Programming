#pragma once
#include <iostream>
using namespace std;

class String{
    private:
    char* ptr;
    bool skip_spaces(const char* &current_ptr) const;
    int calc_alloc_length(const char* regular_string) const;

    public:
    String(): ptr(nullptr){}
    String(const char* regular_string);
    String(const String& other);
    ~String();
    String& operator =(const String& other);
    bool operator ==(const String& other) const;
    friend std::ostream& operator<<(std::ostream& os, const String& other);
};