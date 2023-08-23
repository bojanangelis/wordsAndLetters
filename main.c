#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int hasDuplicateLetters(char *word) {
    int i, j;
    for (i = 0; i < strlen(word); i++) {
        int counter = 0;
        for (j = 0; j < strlen(word); j++) {
            if (tolower(word[i]) == tolower(word[j])) {
                ++counter;
            }
        }
        if (counter >= 3) return 1;
    }
    return 0;
}

int main() {
    FILE *f = fopen("/Users/bojanangjeleski/CLionProjects/untitled134/text.txt", "r");
    int counter = 0;
    char word[101];
    while (fgets(word, 100, f) != NULL) {
        if (hasDuplicateLetters(word)) {
            puts(word);
            ++counter;
        }
    }
    printf("Vkupno %d zborovi.", counter);
    fclose(f);
    return 0;
}
/*
Задача 5
Да се напише програма која за дадена текстуална датотека zborovi.txt ќе ги отпечати на екран сите зборови во кои се појавуваат повеќе од две исти букви (некоја буква се појавува три или повеќе пати). Да не се прави разлика помеѓу мали и големи букви. На крајот треба да се отпечати и бројот на зборови што го задоволуваат условот.
Секој ред во датотеката содржи по еден збор (зборовите се разделени меѓу себе со знак за нов ред). Секој збор е составен само од букви. Максималната должина на зборовите е 20 знаци.

Пример
Ако датотеката zborovi.txt ја има следнава содржина:

banana
jabolko
Obratnoto
binarnata
dekadniot
Kopakabana

тогаш програмата треба да отпечати:

banana
Obratnoto
binarnata
Kopakabana
Vkupno 4 zborovi.
 */