#include <stdio.h>
#include <limits.h>
#include <string.h>

int main () {
    char fileName[UCHAR_MAX];
    char text[UCHAR_MAX] = "\0";
    char *aux = NULL;
    FILE * f;
    // Recibe nombre del archivo a leer o crear
    fflush(stdin);
    fgets(fileName, UCHAR_MAX, stdin);  
    fileName[strcspn(fileName, "\n")] = '\0';
    strcat(fileName, ".txt");
    // Lee o crea en su defecto el archivo .txt
    f = fopen(fileName, "r"); 
    if (f == NULL) {
        f = fopen(fileName, "w");
        fclose(f); 
        f = fopen(fileName, "r");
    }
    // Imprime el contenido del archivo en la consola
    printf("\n");
    do {
        aux = fgets(text, UCHAR_MAX, f);
        if (aux != NULL)
        {
            printf("%s", text);
        }
    } while (aux != NULL);
    fclose(f);
    system("pause");
    return 0;
    // nueva linea para ver como se actualiza en github
}