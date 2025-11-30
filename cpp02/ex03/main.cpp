#include "Point.hpp"

int main() {
    Point a(1.0f, 2.0f);
    Point b(2.0f, 5.0f);
    Point c(6.0f, 3.0f);

    Point p[] = {   Point(3.0f, 3.5f), Point(1.0f, 2.0f),
                    Point(2.0f, 3.0f), Point(4.0f, 4.0f),
                    Point(5.0f, 3.0f), Point(5.0f, 2.5f) };

    for (int i = 0; i < 6; i++)
    {
        std::cout << "---------------------------------------\n";
        std::cout << "Test number " << i+1 << "\t->";
        std::cout << "\t( " << p[i].GetX() << ", " << p[i].GetY() << " )\n";
        if (bsp(a, b, c, p[i]) == true)
		    std::cout << "Inside !" << std::endl;
	    else
		    std::cout << "Outside" << std::endl;
    }

    return 0;
}

