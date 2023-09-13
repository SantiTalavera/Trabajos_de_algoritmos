#include <stdio.h>
#include <stdlib.h>

    //Modulos
        void sumavectores (int dim, int vector[], int pos, int*sum)
        {
            if (pos == dim)
            { 
                return;
            }
            else
            {
                *sum += vector[pos];
                sumavectores(dim,vector, pos +1, sum);
            }     
        }   

        void sumapares (int dim, int vector[], int pos, int*sum)
        {
            if (pos == dim)
            { 
                return;
            }
            else if (vector[pos] % 2 == 0)
            {
                *sum += vector[pos];
            }
            sumapares(dim,vector, pos +1, sum);
        }

         void sumapares_impares (int dim, int vector[], int pos, int*sum)
        {
            if (pos == dim)
            { 
                return;
            }
            else if (vector[pos] % 2 == 0)
            {
                *sum += vector[pos];
            }
            else if (vector[pos] % 2 == 1)
            {
                *sum += vector[pos];
            }
            sumapares_impares(dim,vector, pos +1, sum);
        }

        void promedio_notas_que_superan(int pos, int cantidad_notas, int notas_alumnos[], float *promedio, int *notas_que_superan)
    {
    if (pos == cantidad_notas)
    {
        *promedio = *promedio / cantidad_notas;
        return;
    }
    else
    {
        *promedio += notas_alumnos[pos];
    }

    promedio_notas_que_superan(pos + 1, cantidad_notas, notas_alumnos, promedio, notas_que_superan);//
    if (pos == 0)
    {
         return;
    }
    if (notas_alumnos[pos] > *promedio)
    {
        (*notas_que_superan)+= 1;
    }

    
}

int main()
{
    system ("cls");
    //Variables
        int dimension;
        int i, dato, not;
        int posicion;
        int sumatoria, sumatoria_pares, sumatoria_pares_impares;
        int cant_notas, sup;
        float prom;

    //hacer

        //carga de vector 1
        printf("Defina la dimension de su vector: \n");
        scanf("%d", &dimension);
        int vector [dimension];
        printf("Cargue los datos de su vector\n");
        for ( i = 0; i < dimension; i++)
        {
            printf("Ingrese el dato a cargar\n");
            scanf("%d", &dato);
            vector[i] = dato;
        }

        //Inciso a)
        sumatoria = 0;
        sumatoria_pares = 0;

        printf("Se hara la suma de los elementos del vector\n");

        sumavectores(dimension, vector, 0, &sumatoria);
        printf("La suma da un total de: %d", sumatoria);

        //inciso b)
        sumapares(dimension, vector, 0, &sumatoria_pares);
        printf("\nLa suma de los pares es de: %d\n", sumatoria_pares);

        //inciso c)
        sumapares_impares(dimension, vector, 0, &sumatoria_pares_impares);
        printf("La suma de los pares e impares es de: %d\n", sumatoria_pares_impares);

        //carga de vector notas
        printf("Ingrese la cantidad de notas a cargar de alumnos\n");
        scanf("%d", &cant_notas);
        int notas[cant_notas];
        printf("Cargue las notas de los alumnos ordenadamente\n");
        for ( i = 0; i < cant_notas; i++)
        {
            printf("Del alumno %d\n", i);
            scanf ("%d", &not);
            notas[i] = not;
        }

        //inciso d)
        prom = 0;
        sup = 0;

        printf("Se procedera a mostrar el promedio de notas y la cantidad de ellas que superan el mismo: \n");
        promedio_notas_que_superan(0, cant_notas, notas, &prom, &sup);
        printf("El promedio es de: %f\n", prom);
        printf("La cantidad de notas que superan el promedio es de: %d\n", sup);
        return 0;
    //fin hacer
}
