#include <stdio.h>

int long_word(char text[255]) {
    int i, last_len = 0;
    for (i = 0; i < 255; i++) {
        if (text[i] == ' ') { break; }
    }
    last_len = i;
    i++;
    int max_len = 0;
    for (; text[i] != '\0'; i++) {
        if (text[i] != ' ') {
            max_len++;
        } else {
            if (last_len < max_len) {
                last_len = max_len;
            }
            max_len = 0;
            i++;
        }
    }
    if (last_len > max_len) {
        return last_len;
    } else {
        return max_len;
    }
}

int main() {
    char word1[255] = "abc cda dffff h", word2[255] = "hahaha";
    //fgets(word1, 255, stdin);
    //fgets(word2, 255, stdin);
    printf("%d", long_word(word1));
    return 0;
}
