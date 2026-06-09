#ifndef   SPAN_HPP
# define  SPAN_HPP

# include <vector>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> V;
public:
    Span();
    Span(unsigned int maxSize);
    Span(const Span& other);
    ~Span();
    
    Span &operator=(const Span& other);

    void addNumber(int num);

    template <typename It>
    void addNumbers(It begin, It end);

    long shortestSpan() const;
    long longestSpan() const;
};

template <typename It>
void Span::addNumbers(It begin, It end)
{
    while (begin != end)
    {
        addNumber(*begin);
        ++begin;
    }
}

#endif
