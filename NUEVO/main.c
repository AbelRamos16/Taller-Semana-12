#include <stdio.h>
#include "funciones.h"


int main (int argc, char *argv[]) {

    char peliculas[10][4][40]={{"1","AvatarII","10:20","Fantasia"},
                               {"2","Jurassic-Park","12;30","Ciencia-Ficcion"},
                               {"3","Intensa-Mente","1:20","Animado"},
                               {"4","Godzilla","1:20","Ciencia-Ficcion"},
                               {"5","MegamenteII","2:50","Animado"},
                               {"6","Ted","3:00","Comedia"},
                               {"7","Up","3:00","Animado"},
                               {"8","Deadpool","4:20","Accion"},
                               {"9","Mision-Imposible","5:30","Accion"},
                               {"10","It","7:50","Terror"}};
    double precio[3]={7,3.5,3};
    char clientes[5][2][40]={{"",""},
                             {"Luis","123456788"},
                             {"",""},
                             {"",""},
                             {"",""}};

    int reserva[10][4] = {
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1}
    };
    int opcion1=0,opcion2=0,opcion3=0;
    do
    {
        printf("Escoja una opcion:\n1.Ingresar Cliente\n2.Ver Peliculas\n3.Buscar Pelicula\n4.Comprar Ticket\n5.Ver Compras\n>>");
        scanf("%d",&opcion2);
        switch (opcion2)
        {
        case 1:
            ingresarCliente(clientes);
            break;
        case 2:
            listarPeliculas(peliculas);
            break;
        case 3:
             printf("1.Por nombre\n2.Por Genero\n>>");
             scanf("%d",&opcion3);
            switch (opcion3)
             {
            case 1:
                buscarporNombre(peliculas);
                break;
             case 2:
                buscarporGenero(peliculas);
                break;
            default:
                break;
           }
           break;
        case 4:
            comprarTicket(peliculas,precio,clientes,reserva);
            break;
        case 5:
            verCompras(peliculas, precio, clientes, reserva);
            break;
        default:

            break;
        }
        printf("Desea escoger una nueva opcion: 1.Si/2.No\n>>");
        scanf("%d",&opcion1);
    } while (opcion1==1);
    return 0;
}