#include <iostream>
#include <ncurses.h>

class Player {
public:
  Player(int y, int x, int height, int width, char playerChar, WINDOW *win) {
    mapWin = win;
    yPos = y;
    xPos = x;
    mapHeight = height;
    mapWidth = width;
    player = playerChar;
    keypad(mapWin, true);
  }

  int getMove() {
    int c = wgetch(mapWin);

    switch (c) {
    case KEY_UP:
      moveUp();
      break;
    case KEY_DOWN:
      moveDown();
      break;
    case KEY_LEFT:
      moveLeft();
      break;
    case KEY_RIGHT:
      moveRight();
      break;
    default:
      break;
    }
    return c;
  }

  void moveUp() {
    if (yPos > 0) {
      yPos--;
    }
  }
  void moveDown() {
    if (yPos < mapHeight - 1) {
      yPos++;
    }
  }
  void moveLeft() {
    if (xPos > 0) {
      xPos--;
    }
  }
  void moveRight() {
    if (xPos < mapWidth - 1) {
      xPos++;
    }
  }

  void display() { mvwaddch(mapWin, yPos + 1, xPos + 1, player); }

private:
  int xPos;
  int yPos;
  int mapHeight;
  int mapWidth;
  char player;
  WINDOW *mapWin;
};
