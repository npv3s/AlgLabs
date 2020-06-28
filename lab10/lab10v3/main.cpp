#include <cstdio>

int main() {
    char text[256];
    fgets(text, 255, stdin);
    int point[2] = {-1, -1};
    for (int i=0; i < 256; i++) {
        if (text[i] == '.') {
            point[0] = i;
            break;
        }
    }
    if (point[0] == -1) { return -1; }
    for (int i=point[0]+1; i < 256; i++) {
        if (text[i] == '.') {
            point[1] = i;
            break;
        }
    }
    if (point[1] == -1) { return -1; }
    int space[2] = {-1, -1};
    for (int i=point[0]+2; i < 256; i++) {
        if (text[i] == ' ') {
            space[0] = i;
            break;
        }
    }
    if (space[0] == -1) { return -1; }
    for (int i=space[0]+1; i < 256; i++) {
        if (text[i] == ' ') {
            space[1] = i;
            break;
        }
    }
    if (space[1] == -1) { return -1; }

    char word1[space[1]-space[0]];
    char word2[point[1]-space[1]];

    for (int i=0; i < space[1]-space[0]-1; i++) {
        word1[i] = text[i+space[0]+1];
    }
    word1[space[1]-space[0]-1] = '\0';

    for (int i=0; i < point[1]-space[1]-1; i++) {
        word2[i] = text[i+space[1]+1];
    }
    word2[point[1]-space[1]-1] = '\0';

    int i=space[0]+1;
    for (int y=0; y < point[1]-space[1]-1; y++, i++) {
        text[i] = word2[y];
    }
    text[i] = ' ';
    i++;
    for (int y=0; y < space[1]-space[0]-1; y++, i++) {
        text[i] = word1[y];
    }
    text[i] = '.';

    printf("%s\n", text);
    return 0;
}