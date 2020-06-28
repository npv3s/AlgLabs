#include <string.h>
#include <stdio.h>

int main() {
    char str1[10] = "abc";
    char str2[] = "dfg";
    char tmp[10] = "abc";
    printf("%s\n", strcat(tmp, str2));
    strcpy(tmp, "abc");
    printf("%s\n", strncat(tmp, str2, 2));
    printf("%s\n", strchr(str1, 'b'));
    printf("%d\n", strcmp(str1, str2));
    tmp[10] = {'\0'};
    strcpy(tmp, str1);
    printf("%s\n", tmp);
    tmp[10] = {'\0'};
    strncpy(tmp, "1234", 3);
    printf("%s\n", tmp);
    printf("%zu\n", strlen(str1));
    printf("%s\n", strstr(str1, "b"));
    tmp[10] = {'\0'};
    strtok(tmp, str1);
    printf("%s\n", tmp);
    return 0;
}