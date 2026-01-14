#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
                : AForm("PresidentialPardonForm", 72, 45), _target("x")
{ }

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
                : AForm("PresidentialPardonForm", 72, 45), _target(target)
{ }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm&other)
                : AForm(other), _target(other._target)
{ }

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm&other)
{
    if (this != &other)
        _target = other._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{ }

void PresidentialPardonForm::beExecuted() const
{
    std::ofstream outFile((_target + "_shrubbery").c_str());
    if (!outFile.is_open())
    {
        std::cerr << "Error opening file: " << _target << "_shrubbery\n" // TODO: throw error!
        // TODO: throw std::runtime_error("Failed to create shrubbery file");
        return;
    }

    outFile <<
        "                     / / /                                         \n"
        "                   /        /  /     //    /                       \n"
        "                /                 /         /  /                   \n"
        "                                /                                  \n"
        "                         @O@   /       @        //                 \n"
        "               /         O/O          @/@             /            \n"
        "               /         O $'/,        /               /           \n"
        "               /              'b      *o                           \n"
        "                /              '$    //                //          \n"
        "               /    /           $:   /:               /            \n"
        "             //      /  //      */  #):      ()/   / /             \n"
        "                          /     :#,#):   ,/**:'   /                \n"
        "              /      @/,@       :##*: //**'      /   /             \n"
        "                       '/o/    /:(#'/#*  @/O                       \n"
        "               /  /       'bq,//:,##*'   O,*@    / /               \n"
        "                          ,p$q8,:#)'  /p*'      /                  \n"
        "                   /     '  / '##pp##*'    /  /                    \n"
        "                    /  / //    y7'.'     /  /                      \n"
        "                              :#):.                                \n"
        "                             .:#:'.                                \n"
        "                           .::(#:.                                 \n";

    outFile.close();
}
