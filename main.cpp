#include <bits/stdc++.h>
#include <boost/asio.hpp>
#include <cmath>
#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <stdint.h>

#include "player.cpp"

std::vector<std::vector<char>> openInput(std::string filename) {
  std::ifstream f(filename);

  if (!f.is_open()) {
    std::cout << "Cant open file\n";
    std::abort();
  }

  std::string line;
  std::vector<std::vector<char>> input;

  while (std::getline(f, line)) {
    std::vector<char> row;
    for (int i = 0; i < line.size(); i++) {
      row.push_back(line[i]);
    }
    input.push_back(row);
  }

  return input;
};

int main() {
  initscr();
  cbreak();
  curs_set(0);
  noecho();

  std::vector<std::vector<char>> map = openInput("level1");

  int maxY, maxX;
  getmaxyx(stdscr, maxY, maxX);
  int mapHeight, mapWidth;
  mapHeight = map.size();
  mapWidth = map[0].size();

  WINDOW *mapWin =
      newwin(mapHeight + 2, (mapWidth + 2), (maxY / 2) - ((mapHeight + 2) / 2),
             (maxX / 2) - (mapWidth + 2) / 2);

  box(mapWin, 0, 0);
  refresh();
  wrefresh(mapWin);

  Player player = Player(0, 0, mapHeight, mapWidth, '@', mapWin);

  int c;
  while (c != 'q') {
    for (int r = 0; r < mapHeight; r++) {
      for (int c = 0; c < mapWidth; c++) {
        mvwaddch(mapWin, r + 1, c + 1, map[r][c]);
      }
    }

    player.display();
    c = player.getMove();
    wrefresh(mapWin);
  }

  endwin();

  return 0;
}
