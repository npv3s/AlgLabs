#include <stdio.h>
#include <cstring>

int main() {
    char str[256];
    scanf("%256s", &str);
    int a = strlen(str);
    int halfa = a/2;
    bool flag = true;
    for (int i=0; i<halfa; i++) {
        if (str[i] != str[a-i-1]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}
