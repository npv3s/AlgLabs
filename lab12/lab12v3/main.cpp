#include <cstdio>

int long_word(char text[256]) {
    int local_max = 0, max = 0;
    for (int i = 0; i < 256; i++) {
        if (text[i] == '\0') break;
        else if (text[i] == ' ') {
            if (local_max > max)
                max = local_max;
            local_max = 0;
        } else if (text[i] != '\n')
            local_max++;
    }
    if (local_max > max)
        max = local_max;

    return max;
}

int main() {
    //char word1[255] = "abc cda dffff h", word2[255] = "hahaha";
    char word1[256], word2[256];
    printf("Введите предложения\n");
    fgets(word1, 255, stdin);
    fgets(word2, 255, stdin);
    int l1 = long_word(word1);
    int l2 = long_word(word2);
    if (l1 > l2)
        printf("В первом предложении слово больше. Его длина %d символов", l1);
    else
        printf("В втором предложении слово больше. Его длина %d символов", l2);
    return 0;
}
