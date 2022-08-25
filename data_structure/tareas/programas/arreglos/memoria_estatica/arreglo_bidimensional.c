#include <stdio.h>
#include <string.h>

typedef struct
{
    char nombre[25];
    int edad;
    int calificacion;
}Arreglo;


int main()
{
    Arreglo a[20];
    int n, i;
    float pE, cG;

    printf("Numero de alumnos(No debe ser mayor a 20)>");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Nombre(%d): ", i+1);
        fflush(stdin);
        fgets(a[i].nombre, 25, stdin);
        a[i].nombre[strcspn(a[i].nombre, "\n")] = 0;
        printf("Edad(%d): ", i+1);
        scanf("%d", &a[i].edad);
        printf("Calificacion(%d): ", i+1);
        scanf("%d", &a[i].calificacion);
        pE += (float)a[i].edad;
        cG += (float)a[i].calificacion;
    }

    pE = pE/(float)n;
    cG = cG/(float)n;

    printf("|-------------------------|----|------------|\n");
    printf("|Nombre                   |Edad|Calificacion|\n");
    printf("|-------------------------|----|------------|\n");


    //no tenía idea que se podía formatear los espacios en C 
    for(i = n-1; i >= 0; i--)
    {
        printf("|%-25s|",a[i].nombre);
        printf("%-4i|", a[i].edad);
        printf("%-12i|\n", a[i].edad);
    }
    printf("|-------------------------|----|------------|\n");

    printf("Edad promedio: %.2f\n", pE);
    printf("Calificacion grupal: %.2f", cG);
    


    return 0;
}
