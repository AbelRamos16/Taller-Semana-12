#include <stdio.h>
#include "funciones.h"
#include <string.h>

void ingresarCliente(char clientes[][2][40]){

    for (int i = 0; i < 5; i++)
    {
        if(strcmp(clientes[i][0],"")==0){
            printf("Ingrese nombre del nuevo cliente: ");
            scanf("%s",clientes[i][0]);
            printf("Ingrese cedula del nuevo cliente: ");
            scanf("%s",clientes[i][1]);
            break;
        }
    } 
    imprimirClientes(clientes);
}

void imprimirClientes(char clientes[][2][40]){
    for (int i = 0; i < 5; i++)
    {
        printf("%s\t\t%s\n",clientes[i][0],clientes[i][1]);
    }   
}

void listarPeliculas(char peliculas[][4][40]){

    printf("Numero\t\tPelicula\t\t\tHora\t\tGenero\n");
    for (int i = 0; i < 10; i++)
    {
        printf("\n%s\t\t%s\t\t\t%s\t\t%s\n",peliculas[i][0],peliculas[i][1],peliculas[i][2],peliculas[i][3]);
    }

}

void buscarporNombre(char peliculas[][4][40]) {
    char pelicula[40];
    printf("\nIngrese el nombre de la pelicula que desea buscar: \n");
    scanf("%s", pelicula);
    printf("Numero\t\tPelicula\t\t\tHora\t\tGenero\n");
    for (int i = 0; i < 10; i++) {
        if (strcmp(peliculas[i][1], pelicula) == 0) {
            printf("%s\t\t%s\t\t\t%s\t\t%s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
        }
    }
}

void buscarporGenero(char peliculas[][4][40]){
    char genero[40];
    printf("\nIngrese el genero de la pelicula que desea buscar: \n");
    scanf("%s",genero);
    printf("Numero\t\tPelicula\t\t\tHora\t\tGenero\n");
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(peliculas[i][3], genero)==0)
        {
            printf("\n%s\t\t%s\t\t\t%s\t\t%s\n",peliculas[i][0],peliculas[i][1],peliculas[i][2],peliculas[i][3]);
        }
    }
}


void comprarTicket(char peliculas[][4][40], double precio[], char clientes[][2][40], int reserva[][4]) {
    char cedula[40];
    int NumPelicula, cantidad, tipoEntrada;
    int clienteIndex = -1;

    printf("Ingrese su cedula: ");
    scanf("%s", cedula);

    // Buscar cliente por cedula
    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][1], cedula) == 0) {
            clienteIndex = i;
            break;
        }
    }

    if (clienteIndex == -1) {
        printf("Cedula no encontrada.\n");
        return;
    }

    printf("Ingrese el numero de la pelicula: ");
    scanf("%d", &NumPelicula);

    if (NumPelicula < 1 || NumPelicula > 10) {
        printf("El numero de la pelicula no es el correcto.\n");
        return;
    }

    do {
        printf("Ingrese la cantidad de entradas (debe ser mayor que cero): ");
        scanf("%d", &cantidad);
    } while (cantidad <= 0);

    printf("Tipos de entrada: 0 - Normal ($%.2f), 1 - Ninos ($%.2f), 2 - Adulto mayor ($%.2f)\n",
           precio[0], precio[1], precio[2]);
    printf("Ingrese el tipo de entrada: ");
    scanf("%d", &tipoEntrada);

    if (tipoEntrada < 0 || tipoEntrada > 2) {
        printf("Tipo de entrada invalido.\n");
        return;
    }

    double precioEntrada = precio[tipoEntrada];
    double total = cantidad * precioEntrada;

    // Realizar la compra y almacenar en la reserva
    for (int i = 0; i < cantidad; i++) {
        for (int j = 0; j < 4; j++) {
            if (reserva[NumPelicula - 1][j] == -1) {
                reserva[NumPelicula - 1][j] = clienteIndex;
                reserva[NumPelicula - 1][j + 4] = tipoEntrada; // Almacenar el tipo de entrada en la posición siguiente
                break;
            }
        }
    }

    printf("Compra realizada exitosamente. Total: $%.2f\n", total);
}


void verCompras(char peliculas[][4][40], double precio[], char clientes[][2][40], int reserva[][4]) {
    char cedula[40];
    int clienteIndex = -1;

    printf("Ingrese su cedula: ");
    scanf("%s", cedula);

    // Buscar cliente por cedula
    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][1], cedula) == 0) {
            clienteIndex = i;
            break;
        }
    }

    if (clienteIndex == -1) {
        printf("Cedula no encontrada.\n");
        return;
    }

    printf("Compras realizadas por %s (Cedula: %s):\n", clientes[clienteIndex][0], clientes[clienteIndex][1]);
    int totalCompras = 0;
    double totalPrecio = 0.0;

    // Recorrer todas las películas
    for (int j = 0; j < 10; j++) {
        int cantidadReservas = 0;
        double precioEntrada = 0.0; // Precio de entrada para esta película

        // Verificar si el cliente tiene reservas para esta película
        for (int k = 0; k < 4; k++) {
            if (reserva[j][k] == clienteIndex) {
                cantidadReservas++;
                // Obtener el tipo de entrada para esta reserva desde la matriz reserva
                int tipoEntrada = reserva[j][k + 4]; // k representa el tipo de entrada almacenado en la reserva
                precioEntrada = precio[tipoEntrada];
            }
        }

        if (cantidadReservas > 0) {
            printf("  Pelicula: %s, Hora: %s, Genero: %s, Cantidad: %d\n",
                   peliculas[j][1], peliculas[j][2], peliculas[j][3], cantidadReservas);
            totalCompras += cantidadReservas;
            totalPrecio += cantidadReservas * precioEntrada;
        }
    }

    if (totalCompras == 0) {
        printf("No tiene reservas.\n");
    } else {
        printf("Total a pagar: $%.2f\n", totalPrecio);
    }
}