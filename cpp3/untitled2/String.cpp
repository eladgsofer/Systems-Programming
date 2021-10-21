#define EQUAL 0
#define SIZE 100
#include <iostream>
#include <string.h>
#include "String.h"
using namespace std;

String::String(const char* regular_string){
    ptr = new char[calc_alloc_length(regular_string)];

    char* tmp_ptr = ptr;
    skip_spaces(regular_string);   // skip unnecessary spaces at the beginning of the string
    while(*regular_string != '\0'){
        if(skip_spaces(regular_string)){  // if spaces were skipped
            if(*regular_string == '\0') // skipped unnecessary spaces at the end of the string
                break;
            *tmp_ptr++ = ' ';
        }
        *tmp_ptr++ = *regular_string++; // copy non-space and move on
    }
}

String::String(const String& other){
    ptr = new char[strlen(other.ptr)+1];
    strcpy(ptr, other.ptr);
}

String::~String(){
    delete[] ptr;
}

String& String::operator =(const String& other){
    if (this != &other){
        delete[] ptr;
        ptr = new char[strlen(other.ptr)+1];
        strcpy(ptr, other.ptr);
    }
    return *this;
}

bool String::operator ==(const String& other) const{
    return strcmp(ptr, other.ptr) == EQUAL;
}

std::ostream& operator<<(std::ostream& os, const String& other){
    if(other.ptr != nullptr)
        os << other.ptr;
    return os;
}

bool String::skip_spaces(const char* &current_ptr) const{
    if(*current_ptr != '\0' && (*current_ptr == ' ' || *current_ptr == '\t')){
        do {
            current_ptr++;
        } while (*current_ptr != '\0' && (*current_ptr == ' ' || *current_ptr == '\t'));
        return true;
    }
    return false;
}

int String::calc_alloc_length(const char* regular_string) const{
    int count = 0;
    skip_spaces(regular_string);  // dont count first spaces (skip them)
    while(*regular_string != '\0'){
        if(skip_spaces(regular_string)){  // if spaces were skipped
            if(*regular_string == '\0')  // dont count last spaces
                break;
            count++;
        }
        count++;    // reached a new non space
        regular_string++;
    }
    return count+1;
}

