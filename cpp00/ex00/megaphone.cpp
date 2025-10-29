#include <iostream>

using namespace std;

int main(int ac, char **av)
{
    if (ac == 1) {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
        return 1;
    }
    for (int i = 1; av[i]; i++)
        for (int j = 0; av[i][j]; j++)
            cout << (char)toupper(av[i][j]);
    cout << endl;
return 0;
}
