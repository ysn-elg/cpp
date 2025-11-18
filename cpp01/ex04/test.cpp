#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

int main(int argc, char** argv)
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " filename s1 s2\n";
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: s1 must not be empty\n";
        return 1;
    }

    std::ifstream ifs(filename.c_str(), std::ios::in | std::ios::binary);
    if (!ifs) {
        std::cerr << "Error: could not open input file\n";
        return 1;
    }

    // read entire file into content
    std::string content;
    content.assign(std::istreambuf_iterator<char>(ifs),
                   std::istreambuf_iterator<char>());
    ifs.close();

    // replace all non-overlapping occurrences of s1 with s2
    std::size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content.replace(pos, s1.length(), s2);
        pos += s2.length(); // move past the replacement
    }

    std::string outname = filename + ".replace";
    std::ofstream ofs(outname.c_str(), std::ios::out | std::ios::binary);
    if (!ofs) {
        std::cerr << "Error: could not create output file\n";
        return 1;
    }
    ofs << content;
    ofs.close();

    return 0;
}
