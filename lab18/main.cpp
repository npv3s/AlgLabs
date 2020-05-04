#include <iostream>
#include "stack.h"

using namespace std;

#define DOWN 1
#define LEFT 2
#define UP 3
#define RIGHT 4
#define MAZE_X_SIZE 13
#define MAZE_Y_SIZE 12

int main() {

    short int maze[MAZE_Y_SIZE][MAZE_X_SIZE] =
            {{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
             {0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0},
             {0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0},
             {0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
             {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
             {0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0},
             {0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0},
             {0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0},
             {0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0},
             {0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
             {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0},
             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}};


    struct Spider {
        short int direction; // 1 - вниз, 2 - влево, 3 - вверх, 4 - вправо
        Location location;
    };

    Spider spider = {DOWN, {1, 0}};

    Node *top = nullptr;
    push(&top, spider.location);
    cout << "y: " << spider.location.y << " x: " << spider.location.x << endl;

    while (spider.location.y != MAZE_Y_SIZE - 1) {
        bool forwd, left, right;
        switch (spider.direction) {
            case DOWN:
                forwd = maze[spider.location.y + 1][spider.location.x];
                left = maze[spider.location.y][spider.location.x + 1];
                right = maze[spider.location.y][spider.location.x - 1];
                break;
            case LEFT:
                forwd = maze[spider.location.y][spider.location.x - 1];
                left = maze[spider.location.y + 1][spider.location.x];
                right = maze[spider.location.y - 1][spider.location.x];
                break;
            case UP:
                forwd = maze[spider.location.y + 1][spider.location.x];
                left = maze[spider.location.y][spider.location.x - 1];
                right = maze[spider.location.y][spider.location.x + 1];
                break;
            case RIGHT:
                forwd = maze[spider.location.y][spider.location.x + 1];
                left = maze[spider.location.y - 1][spider.location.x];
                right = maze[spider.location.y + 1][spider.location.x];
                break;
        }
        if (right) {
            switch (spider.direction) {
                case UP:
                    spider.direction = RIGHT;
                    spider.location.x++;
                    break;
                case DOWN:
                    spider.direction = LEFT;
                    spider.location.x--;
                    break;
                case LEFT:
                    spider.direction = UP;
                    spider.location.y--;
                    break;
                case RIGHT:
                    spider.direction = DOWN;
                    spider.location.y++;
                    break;
            }
        } else if (forwd) {
            switch (spider.direction) {
                case UP:
                    spider.location.y--;
                    break;
                case DOWN:
                    spider.location.y++;
                    break;
                case LEFT:
                    spider.location.x--;
                    break;
                case RIGHT:
                    spider.location.x++;
                    break;
            }
        } else if (left) {
            switch (spider.direction) {
                case UP:
                    spider.direction = LEFT;
                    spider.location.x--;
                    break;
                case DOWN:
                    spider.direction = RIGHT;
                    spider.location.x++;
                    break;
                case LEFT:
                    spider.direction = DOWN;
                    spider.location.y++;
                    break;
                case RIGHT:
                    spider.direction = UP;
                    spider.location.y--;
                    break;
            }
        } else {
            spider.direction -= 2;
            if (spider.direction == 0) spider.direction = 4;
            if (spider.direction == -1) spider.direction = 3;
        }
        push(&top, spider.location);

        cout << "y: " << spider.location.y << " x: " << spider.location.x << " direction: ";
        switch (spider.direction) {
            case UP:
                cout << "up";
                break;
            case DOWN:
                cout << "down";
                break;
            case LEFT:
                cout << "left";
                break;
            case RIGHT:
                cout << "right";
                break;
        }
        cout << endl;
        if (!maze[spider.location.y][spider.location.x]) {
            return 1;
        }
    }
    cout << "Выход есть!" << endl;

    while (top) {
        Location val = pop(&top);
        maze[val.y][val.x] = 2;
    }
    for (auto &y : maze) {
        for (int x : y) {
            switch (x) {
                case 0:
                    cout << 'N';
                    break;
                case 1:
                    cout << ' ';
                    break;
                default:
                    cout << '+';
                    break;
            }
        }
        cout << endl;
    }
    return 0;
}
