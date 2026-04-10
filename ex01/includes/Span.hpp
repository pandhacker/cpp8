#ifndef SPAN_HPP

# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <exception>
# include <iostream>

class Span {
    private:
        std::vector<int> _values;
    
    public:
        Span();
        Span(const unsigned int length);
        ~Span();
        Span(const Span& src);
        Span& operator=(const Span& src);

        void addNumber(const int i);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

        template <typename Iter>
        void addRange(Iter begin, Iter end);

        class NoSpan: public std::exception{
            public:
                virtual const char *what() const throw(){
                    return ("No span aviable.");
                }
        };

        class NoCapacity: public std::exception{
            public:
                virtual const char *what() const throw(){
                    return ("No more capacity.");
                }
        };

        class InvalidIterators: public std::exception{
            public:
                virtual const char *what() const throw(){
                    return ("I think you should swap iterators.");
                }
        };
};

template <typename Iter>
void    Span::addRange(Iter begin, Iter end){
    if (std::distance(begin, end) < 0)
        throw (Span::InvalidIterators());
    if (static_cast<unsigned long>(std::distance(begin, end)) > _values.capacity() - _values.size())
        throw (Span::NoCapacity());

    _values.insert(_values.end(), begin, end);
}

#endif