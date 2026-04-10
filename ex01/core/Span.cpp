#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <iostream>

Span::Span(){
}

Span::Span(const unsigned int length){
    if (length > 0){
        _values.reserve(length);
    }
}

Span::~Span(){
}

Span::Span(const Span& src){
    if (src._values.capacity() > 0){
        _values.reserve(src._values.capacity());
        for (unsigned int i = 0; i < src._values.size(); i++)
            _values[i] = src._values[i];
    }
}

Span& Span::operator=(const Span& src){
    if (&src == this)
        return(*this);
    else if (src._values.capacity() > 0){
        _values.reserve(src._values.capacity());
        _values.insert(_values.end(), src._values.begin(), src._values.end());
    }
    else
        std::vector<int>().swap(_values);

    return (*this);
}

void Span::addNumber(const int i){
    if (_values.capacity() != _values.size())
        _values.push_back(i);
    else
        throw(Span::NoCapacity());
}

unsigned int Span::shortestSpan() const{

    if (_values.size() < 2)
        throw(Span::NoSpan());

    int res = INT_MAX;
    unsigned int sizeMax = _values.size() - 1;
    std::vector<int> temp(_values);
    std::sort(temp.begin(), temp.end());

    for(unsigned int i = 0; i < sizeMax; i++){
        if (temp[i + 1] - temp[i] < res)
            res = temp[i + 1] - temp[i];
    }

    return (res);
}

unsigned int Span::longestSpan() const{
    if (_values.size() < 2)
        throw(Span::NoSpan());

    std::vector<int> temp(_values);
    std::sort(temp.begin(), temp.end());

    return (temp[temp.size() - 1] - temp[0]);
}
