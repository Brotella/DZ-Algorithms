#include "Cube.hpp"
#include "Cross.hpp"
#include "Corners.hpp"
#include "Edges.hpp"
#include "OLL.hpp"
#include "PLL.hpp"
#include <iostream>
#include <fstream>
#include <cassert>
#include <ctime>

std::string format(std::string);

int main(int argc, char **argv) {
    if (argc < 2) {
        return 0;
    }
    
    std::ifstream fileIn(argv[1]);
    assert(fileIn);
    
    Cube::Cube myCube(false);
    int scrambleNum = 0;
    std::string argString;
    
    srand(time(0));
    
    while (std::getline(fileIn, argString)) {
        ++scrambleNum;
        std::string scramble = format(argString);
        std::cout << "Scramble #" << scrambleNum << ": ";
        myCube.moves(scramble);
        Cross::solveCross(myCube);
        std::cout << "Cross solved" << std::endl;
        Corners::solveCorners(myCube);
        std::cout << "Corners solved" << std::endl;
        Edges::solveEdges(myCube);
        std::cout << "Edges solved" << std::endl;;
        OLL::solveOLL(myCube);
        std::cout << "OLL solved" << std::endl;
        PLL::solvePLL(myCube);
        std::cout << "PLL solved" << std::endl;
    }
    
    std::cout << "Count of tests: " << scrambleNum <<  " Time = " << clock()/1000.0 << std::endl;
    
  return 0;
}

std::string format(std::string s) {
  std::string formatted;

  for (int i=0; i<s.length(); ++i) {
    if (s[i] == '\'') {
      formatted += s[i-1];
      formatted += s[i-1];
    }
    else if (s[i] == '2') {
      formatted += s[i-1];
    }
    else if (s[i] == ' ') {

    }
    else {
      formatted += s[i];
    }
  }

  return formatted;

}
