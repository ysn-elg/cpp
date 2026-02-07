#ifndef   SPAN_HPP
# define  SPAN_HPP

// #include 

class Span {
private:
    int _stored;
    int _shortestSpan;
    int _longestSpan;
    int _updated;
    std::vector<int> V;
public:
    Span();
    Span(const Span& other);
    ~Span();
    
    Span &operator=(const Span& other);

    void addNumber(int num);
    shortestSpan();
    longestSpan();
};

#endif
