#include <iostream>

using namespace std;

#define DOWN 1
#define LEFT 2
#define UP 3
#define RIGHT 4
#define MAZE_X_SIZE 13
#define MAZE_Y_SIZE 12

int main() {

    bool maze[MAZE_Y_SIZE][MAZE_X_SIZE] =
            {{false, true, false, false, false, false, false, false, false, false, false, false},
             {false, true, false, true, true, true, true, true, false, true, true, false},
             {false, true, false, true, false, false, false, true, false, false, true, false},
             {false, true, false, true, true, true, false, true, true, true, true, false},
             {false, true, false, false, false, true, false, false, false, false, false, false},
             {false, true, false, true, true, true, false, true, false, true, true, false},
             {false, true, false, true, true, false, false, true, true, true, true, false},
             {false, true, false, true, true, true, false, true, false, false, true, false},
             {false, true, false, true, false, true, true, true, false, true, true, false},
             {false, true, false, false, false, false, false, true, false, true, false, false},
             {false, true, true, true, true, true, true, true, false, true, true, false},
             {false, false, false, false, false, false, false, false, false, false, true, false}};

    struct Location {
        short int x;
        short int y;
    };

    struct Spider {
        short int direction; // 1 - вниз, 2 - влево, 3 - вверх, 4 - вправо
        Location location;
    };

    unsigned int len = 0;
    Location history[1024];

    Spider spider = {DOWN, {1, 0}};

    history[len++] = spider.location;
    cout << "y: " << spider.location.y << " x: " << spider.location.x << endl;

    while (spider.location.y != MAZE_Y_SIZE-1) {
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
        history[len++] = spider.location;
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

    int map[MAZE_Y_SIZE][MAZE_X_SIZE] = {0};
    for (int y = 0; y < MAZE_Y_SIZE; y++) {
        for (int x = 0; x < MAZE_X_SIZE; x++) {
            if (!maze[y][x]) map[y][x] = 1;
        }
    }
    for (int i = 0; i < len; i++) {
        map[history[i].y][history[i].x] = 2;
    }
    for (auto &y : map) {
        for (int x : y) {
            switch (x) {
                case 0:
                    cout << ' ';
                    break;
                case 1:
                    cout << 'N';
                    break;
                case 2:
                    cout << '+';
                    break;
            }
        }
        cout << endl;
    }
    return 0;

}
