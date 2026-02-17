#ifndef   MUTANTSTACK_HPP
# define  MUTANTSTACK_HPP

# include <deque>
# include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    typedef std::stack<T, Container> stack_type;
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    MutantStack();
    MutantStack(const MutantStack& other);
    ~MutantStack();

    MutantStack &operator=(const MutantStack& other);
    
    iterator        begin();
    const_iterator  begin() const;

    iterator        end();
    const_iterator  end() const;
    
};

#endif
