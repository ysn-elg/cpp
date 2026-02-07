#ifndef   INTERN_HPP
# define  INTERN_HPP

# include "AForm.hpp"
# include <string>

class Intern
{
public:
    Intern();
    Intern(const Intern& other);
    ~Intern();

    Intern &operator=(const Intern& other);

    AForm*    makeForm(const std::string formName, const std::string target) const;

    // TODO: add exception in case of invalid form name!
};

#endif
