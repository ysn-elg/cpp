#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    Base* obj = generate();
    identify(obj);
    identify(*obj);

    delete obj;
    return 0;
}
