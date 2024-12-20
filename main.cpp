#include <bits/stdc++.h>
#include <boost/asio.hpp>
#include <cmath>
#include <curses.h>
#include <fstream>
#include <iostream>
#include <stdint.h>

std::vector<std::vector<int>> openInput(std::string filename) {
  std::ifstream f(filename);

  if (!f.is_open()) {
    std::cout << "Cant open file\n";
    std::abort();
  }

  std::string line;
  std::vector<std::vector<int>> input;

  while (std::getline(f, line)) {
    std::vector<int> row;
    for (int i = 0; i < line.size(); i++) {
      row.push_back(line[i] - '0');
    }
    input.push_back(row);
  }

  return input;
};

void start_ncruses(bool useRaw, bool useNoecho);

int main() {

  std::vector<std::vector<int>> map = openInput("level1");

  for (int r = 0; r < map.size(); r++) {
    for (int c = 0; c < map[r].size(); c++) {
      std::cout << map[r][c];
    }
    std::cout << "\n";
  }

  int c;

  return 0;
}
