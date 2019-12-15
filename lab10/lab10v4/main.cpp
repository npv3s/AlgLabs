#include <stdio.h>
#include <math.h>

bool vowel(char letter) {
    bool out = false;
    char vowels[] = {'a', 'e', 'u', 'i', 'u'};
    for (char vowel : vowels) {
        if (vowel == letter) {
            out = true;
            break;
        }
    }
    return out;
}

bool alternating(char word[255]) {
    int end = 0;
    for (int i = 0; i < 255; i++) {
        if (word[i] == '\0') {
            end = i;
            break;
        }
    }
    bool flag_1 = true, flag_2 = true;
    for (int i = 0; i < end; i += 2) {
        flag_1 = flag_1 && vowel(word[i]);
    }
    for (int i = 1; i < end; i += 2) {
        flag_2 = flag_2 && vowel(word[i]);
    }
    return flag_1 or flag_2;
}

bool check_2(char word[255]) {
    int end = 0;
    for (int i = 0; i < 255; i++) {
        if (word[i] == '\0') {
            end = i;
            break;
        }
    }
    unsigned int is_2 = 0;

    for (int i = 0; i < end; i++) {
        for (int y = 0; y < end; y++) {
            if ((y != i) and (word[i] == word[y])) {
                is_2++;
                break;
            }
        }
    }
    return is_2 == end;
}

bool special(char letter) {
    bool out = false;
    char specials[] = {'.', ' ', ',', '!', '?'};
    for (char special : specials) {
        if (special == letter) {
            out = true;
            break;
        }
    }
    return out;
}

int main() {
    char text[] = "lala masamasa Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer nec odio. Praesent libero. Sed cursus ante dapibus diam. Sed nisi. Nulla quis sem at nibh elementum imperdiet. Duis sagittis ipsum. Praesent mauris. Fusce nec tellus sed augue semper porta. Mauris massa. Vestibulum lacinia arcu eget nulla. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Curabitur sodales ligula in libero. Sed dignissim lacinia nunc. Curabitur tortor. Pellentesque nibh. Aenean quam. In scelerisque sem at dolor. Maecenas mattis. Sed convallis tristique sem. Proin ut ligula vel nunc egestas porttitor. Morbi lectus risus, iaculis vel, suscipit quis, luctus non, massa. Fusce ac turpis quis ligula lacinia aliquet. Mauris ipsum. Nulla metus metus, ullamcorper vel, tincidunt sed, euismod in, nibh. Quisque volutpat condimentum velit. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Nam nec ante. Sed lacinia, urna non tincidunt mattis, tortor neque adipiscing diam, a cursus ipsum ante quis turpis. Nulla facilisi. Ut fringilla. Suspendisse potenti. Nunc feugiat mi a tellus consequat imperdiet. Vestibulum sapien. Proin quam. Etiam ultrices. Suspendisse in justo eu magna luctus suscipit. Sed lectus. Integer euismod lacus luctus magna. Quisque cursus, metus vitae pharetra auctor, sem masasam mattis sem, at interdum magna augue eget diam. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Morbi lacinia molestie dui. Praesent blandit dolor. Sed non quam. In vel mi sit amet augue congue elementum. Morbi in ipsum sit amet pede facilisis laoreet. Donec lacus nunc, viverra nec.";
    int text_len = sizeof(text)/ sizeof(*text);
    int words_len = 1;
    for (int i = 0; i < text_len; i++) {
        if (text[i] == ' ') {
            words_len++;
        }
    }
    char words[words_len][255];
    int text_index = 0;
    for (int i = 0; i < words_len; i++) {
        int index = 0;
        for (; !special(text[text_index]); text_index++, index++) {
            words[i][index] = text[text_index];
        }
        for (; index < 255; index++) {
            words[i][index] = '\0';
        }
        text_index++;
    }
    char out[words_len][255];
    int i;
    for (i = 0; i < words_len-1; i++) {
        if (words[i] != words[words_len-1] and alternating(words[i]) and check_2(words[i]) and words[i][0] != '\0') {
            printf("%s\n", words[i]);
        }
    }
    return 0;
}
