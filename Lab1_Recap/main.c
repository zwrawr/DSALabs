#include <stdio.h>

int main(void)
{
    int c;
    FILE *file;
    errno_t err = fopen_s(&file, "README.txt", "r");
    
    if (file)
    {
        while ((c = getc(file)) != EOF)
        {
            putchar(c);
        }
        
        fclose(file);
    }
    
    printf("\nPRESS ANY KEY TO EXIT");
    getchar();
}