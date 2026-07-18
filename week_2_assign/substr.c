#include <stdio.h>

int find_substring(const char *haystack, const char *needle) {

    int i = 0;

    while (haystack[i] != '\0') {

        int j = 0;

        while (needle[j] != '\0' &&
               haystack[i + j] == needle[j]) {
            j++;
        }

        if (needle[j] == '\0')
            return i;

        i++;
    }

    return -1;
}

int main() {

    char haystack[] = "Embedded Systems";
    char needle[] = "bed";

    int index = find_substring(haystack, needle);

    if(index != -1) printf("Substring found at: %d\n", index);
    else printf("Substring not found: %d\n", index);

    return 0;
}
