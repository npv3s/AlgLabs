#include <stdio.h>
#include <cstring>

int main() {
    //char text[2048];
    //gets(text);
    char text[2048] = "Hu1. Hu2 Hu3 Hu4.";
    printf("%s\n", text);
    char *pointer = strstr(text, ".") + 2;
    char *point  = strchr(pointer, '.');
    if (point != nullptr) {
        *(point) = '\0';
    }

    int space[2];
    int spacei = 0;
    for (int i=0; spacei < 2; i++) {
        if (pointer[i] == ' ') {
            space[spacei] = i;
            spacei++;
        }
    }

    int end = strlen(pointer);
    printf("%d %d %d\n", space[0], space[1], end);
    char word1[space[0]], word2[space[1]-space[0]-1], word3[end-space[1]-1];
    strcpy(word1, pointer);
    strcpy(word2, pointer+space[0]+1);
    strcpy(word3, pointer+space[1]+1);

    char out[2048] = {'\0'};
    strcat(out, word1);
    strcat(out, " ");
    strcat(out, word3);
    strcat(out, " ");
    strcat(out, word2);
    strcat(out, ".");

    strcpy(pointer, out);

    printf("%s\n", text);

    return 0;
}
