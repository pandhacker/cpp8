#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    Span sp = Span(5);
    Span sp4(sp);
    Span sp2 = Span(10000);
    
    std::vector<int> mirror = std::vector<int>(10000);
    srand(time(NULL));

    for (int i = 0; i < 10000; i++)
    {
        const int value = rand();
        mirror[i] = value;
    }

    try{
        std::cout << sp4.shortestSpan() << std::endl;
    }
    catch (const std::exception& e){
        std::cout << e.what() << std::endl;
    }

    sp4.addNumber(6);

    try{
        std::cout << sp4.longestSpan() << std::endl;
    }
    catch (const std::exception& e){
        std::cout << e.what() << std::endl;
    }

    sp4.addNumber(3);
    sp4.addNumber(17);
    sp4.addNumber(9);
    sp4.addNumber(11);

    try{
        sp4.addNumber(11);
    }
    catch (const std::exception& e){
        std::cout << e.what() << std::endl;
    }

    sp = sp4;
    std::cout << sp4.shortestSpan() << std::endl;
    std::cout << sp4.longestSpan() << std::endl;

    sp2.addRange(mirror.begin(), mirror.end());

    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;

    Span sp3 = Span(10000);


    try{
        sp3.addRange(mirror.end(), mirror.begin());
    }
    catch (const std::exception& e){
        std::cout << e.what() << std::endl;
    }

    try{
        sp3.addNumber(3);
        sp3.addRange(mirror.begin(), mirror.end());
    }
    catch (const std::exception& e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}