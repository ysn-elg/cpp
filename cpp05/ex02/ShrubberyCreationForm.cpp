#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
                : AForm("ShrubberyCreationForm", 145, 137), _target("x")
{ }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
                : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{ }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm&other)
                : AForm(other), _target(other._target)
{ }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm&other)
{
    if (this != &other)
        _target = other._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{ }

void ShrubberyCreationForm::beExecuted() const
{
    std::ofstream outFile((_target + "_shrubbery").c_str());
    if (!outFile.is_open())
    {
        std::cerr << "Error opening file: " << _target << "_shrubbery\n"; // TODO: throw error!
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
