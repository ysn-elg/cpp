#include "Base.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    Base* obj = generate();
    identify(obj);
    identify(*obj);

    delete obj;
    return 0;
}
