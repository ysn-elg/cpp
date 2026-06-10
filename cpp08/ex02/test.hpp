#ifndef TEST_HPP
#define TEST_HPP

# include <stack>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    typedef typename Container::iterator                iterator;
    typedef typename Container::const_iterator          const_iterator;
    typedef typename Container::reverse_iterator        reverse_iterator;
    typedef typename Container::const_reverse_iterator  const_reverse_iterator;

    MutantStack();
    MutantStack(const MutantStack& other);
    ~MutantStack();

    MutantStack &operator=(const MutantStack& other);

    iterator        begin();
    const_iterator  begin() const;

    iterator        end();
    const_iterator  end() const;

    reverse_iterator        rbegin();
    const_reverse_iterator  rbegin() const;

    reverse_iterator        rend();
    const_reverse_iterator  rend() const;
};

#endif
