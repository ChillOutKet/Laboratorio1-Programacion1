#include "Gen_FBasic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int generica_init(eGenerica* list, int len)
{
    int estado;
    int i;
    if (list != NULL)
    {
        for (i=0; i<len; i++)
        {
            list[i].isEmpty = 0;
        }

        estado = 0;
    }
    else
    {
        estado = -1;
    }

    return estado;
}



void generica_inicializarEmployeesConDatos (eGenerica* list, int len)
{
    int id[5] = {1,2,3,4,5};
    char name[5][50] = {"Juan","Maria","Pedro","Susana","Luis"};
    char lastName[5][50] = {"Gonzales","Collins","Xeller","Rodriguez","Pedo"};
    float salary[5] = {1800,2500,2400,1000,2000};
    int sector[5] = {3,8,6,4,7};

    int i;
    for (i=0; i<5; i++)
    {
        list[i].id = id[i];
        strcpy (list[i].name, name[i]);
        strcpy (list[i].lastName, lastName[i]);
        list[i].salary = salary[i];
        list[i].sector = sector[i];
        list[i].isEmpty = 1; // OCUPADO.
    }
}



int generica_buscarEspacio (eGenerica* list, int len)
{
    int indice = -1;
    int i;

    for (i=0; i<len; i++)
    {
        if (list[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



int generica_findGenericById(eGenerica* list, int len, int id)
{
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==1 && list[i].id==id)
        {
            return i;
        }
    }

    return -1;
}



void generica_mostrarUno (eGenerica list)
{
    printf("%d -- %10s %15s %20f %10d\n\n", list.id, list.name, list.lastName, list.salary, list.sector);
}



int generica_mostrarTodos(eGenerica* list, int len)
{
    int i;
    printf("\n\nID -- \t NOMBRE \t APELLIDO \t SALARIO \t SECTOR\n\n");
    for(i=0; i<len; i++)
    {
        if (list[i].isEmpty == 1)
        {
            generica_mostrarUno(list[i]);
        }

    }
}



int generica_idAutoIncremental(eGenerica* list, int len)
{
    int retorno = 0;
    int i;
    if(len > 0 && list != NULL)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                if(list[i].id > retorno)
                {
                    retorno = list[i].id;
                }
            }
        }
    }
    return retorno+1;
}



int generica_add(eGenerica* list,int len)
{
    int retorno = -1;
    int i;
    int k;

    char auxiliarNombre[50];

    char auxiliarSalario[50];
    float salario;

    char auxiliarSector[50];
    int sector;

    int id;

    i = generica_buscarEspacio(list, len);
    id = generica_idAutoIncremental(list, len);

    if(i>=0)
    {
        //Pedir el nombre
        printf("Ingrese el nombre del empleado:");
        fflush(stdin);
        gets(auxiliarNombre);
        //Validar que se haya pedido el nombre.
        /*
        while(esSoloLetras(auxiliarNombre)==0)
        {
            printf("Usted ha ingresado un tipo de nombre incorrecto. Ingrese nuevamente: ");
            fflush(stdin);
            gets(auxiliarNombre);
        }
        */

        // ALGORITMO PARA VERIFICAR QUE NOMBRES NO SE REPITAN
        for (k=0; k<len; k++)
        {
            if (list[k].isEmpty == 1)
            {
                while (stricmp(list[k].name, auxiliarNombre) == 0)
                {
                    printf("Usted ha ingresado un tipo de nombre incorrecto. Ingrese nuevamente: ");
                    fflush(stdin);
                    gets(auxiliarNombre);
                }
            }
        }

        //stringToUpper(list[i].name); // LLAMADA A LA FUNCION PARA 1ER LETRA MAYUSCULA.
        strcpy(list[i].name, auxiliarNombre);


        //Pedir el apellido
        printf("Ingrese el apellido del empleado:");
        fflush(stdin);
        gets(list[i].lastName);
        //Validar que se haya pedido el apellido.
        /*
                while(esSoloLetras(list[i].lastName)==0)
                {
                    printf("Usted ha ingresado un tipo de apellido incorrecto. Ingrese nuevamente: ");
                    fflush(stdin);
                    gets(list[i].lastName);
                }
                stringToUpper(list[i].lastName); // LLAMADA A LA FUNCION PARA 1ER LETRA MAYUSCULA.
        */

        //Pedir un SALARIO
        printf("Ingrese el salario del empleado: ");
        fflush(stdin);
        gets(auxiliarSalario);
        //Validar que se haya ingresado un SALARIO correcto.
        /*
                while(esNumerico(auxiliarSalario)==0)
                {
                    printf("Usted ha ingresado un tipo de salario incorrecto. Ingrese nuevamente: ");
                    fflush(stdin);
                    gets(auxiliarSalario);
                }
        */
        salario=atoi(auxiliarSalario);
        list[i].salary = salario;

        //Pedir un SECTOR
        printf("Ingrese el SECTOR del empleado: ");
        fflush(stdin);
        gets(auxiliarSector);
        //Validar que se haya ingresado un PUESTO correcto.
        /*
                while(esNumerico(auxiliarSector)==0)
                {
                    printf("Usted ha ingresado un tipo de puesto incorrecto. Ingrese nuevamente: ");
                    fflush(stdin);
                    gets(auxiliarSector);
                }
        */
        sector=atoi(auxiliarSector);


        // ALGORITMO PARA VALIDAR SECTOR
        for (k=0; k<len; k++)
        {
            if (list[k].isEmpty == 1)
            {
                while (list[k].sector == sector)
                {
                    printf("Usted ha ingresado un tipo de sector incorrecto. Ingrese nuevamente: ");
                    scanf("%d", &sector);
                }
            }
        }

        list[i].sector=sector;

        //Forzar el estado a 1
        list[i].isEmpty=1;

        // ESTO LO QUE HACE, ES QUE ASIGNE UNA ID DE FORMA AUTOINCREMENTAL.
        list[i].id=id;

        retorno=0;
    }
    return retorno;
}



/**
int removeEmployee(Employee* list, int len, int id)
{
    int i;

    char auxiliarID[50];
    int scanID;

    int opcion;

    int estado = -1; // No se encontro ID

    printEmployees(list, len);


    printf("Ingrese la ID del empleado a remover: ");
    fflush(stdin);
    gets(auxiliarID);
    while(esNumerico(auxiliarID)==0)
    {
        printf("Usted ha ingresado un tipo de ID incorrecta. Ingrese nuevamente: ");
        fflush(stdin);
        gets(auxiliarID);
    }
    scanID=atoi(auxiliarID);


    for(i=0; i<len; i++)
    {
        if(scanID==list[i].id)
        {
            printf("\nDesea dar de baja el usuario? Ingrese 1 para SI // Ingrese 2 para NO.\n");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                list[i].isEmpty = 0;
                list[i].id= 0;
                estado = 0; // Se modifico el empleado.
                break;

            case 2:
                estado = -2; // Se cancelo la baja.
                break;

            default:
                printf("\n\nUsted ingreso una opcion invalida. Vuelva a intentarlo nuevamente.\n");
                estado = -2;
                break;
            }

        }

    }

    return estado;
}



int modificacionDeEmpleado(Employee* listaEmployee, int len)
{
    int id;
    int indice;
    int rt;

    int retorno=-2;

    char auxiliarID[20];

    if(len > 0 && listaEmployee != NULL)
    {
        retorno=-1;

        printEmployees(listaEmployee, len);

        printf("Ingrese la ID del empleado: ");
        fflush(stdin);
        gets(auxiliarID);
        while(esNumerico(auxiliarID)==0)
        {
            printf("Usted ha ingresado un tipo de ID incorrecta. Ingrese nuevamente: ");
            fflush(stdin);
            gets(auxiliarID);
        }
        id=atoi(auxiliarID);



        indice=findEmployeeById(listaEmployee, len, id);


        if(indice>=0)
        {
            rt=menuModificacion(listaEmployee,indice);
            retorno=rt;
        }
        else
        {
            retorno = -2;
        }
    }
    return retorno;
}



int menuModificacion(Employee* listaEmployee, int indice)
{
    char auxiliarOpcion[30];
    int opcion;

    char auxiliarNombre[30];
    char auxiliarApellido[30];
    char auxiliarSalario[30];
    char auxiliarSector[30];

    float salario;
    int sector;


    int retorno=-1;


    printf("\nINGRESE QUE DESEA MODIFICAR: \n::::::::::::::::::::\n(1) Nombre\n(2) Apellido\n(3) Salario\n(4) Sector\n::::::::::::::::::::\n");
    printf("Ingrese la opcion: ");
    fflush(stdin);
    gets(auxiliarOpcion);


    while(esNumerico(auxiliarOpcion)==0)
    {
        printf("Usted ha ingresado una opcion incorrecta. Ingrese nuevamente: ");
        fflush(stdin);
        gets(auxiliarOpcion);
    }
    opcion=atoi(auxiliarOpcion);



    if(opcion>=1&&opcion<=6)
    {
        switch(opcion)
        {
        case 1:

            printf("Ingrese el nuevo nombre del empleado:");
            fflush(stdin);
            gets(auxiliarNombre);
            while(esSoloLetras(auxiliarNombre)==0)
            {
                printf("Usted ha ingresado un tipo de nombre incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxiliarNombre);
            }

            stringToUpper(auxiliarNombre);
            strcpy(listaEmployee[indice].name, auxiliarNombre);
            printf("\n\nEL EMPLEADO HA SIDO MODIFICADO!\n\n");
            retorno=indice;
            break;

        case 2:

            printf("Ingrese el nuevo apellido del empleado:");
            fflush(stdin);
            gets(auxiliarApellido);
            while(esSoloLetras(auxiliarApellido)==0)
            {
                printf("Usted ha ingresado un tipo de apellido incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxiliarApellido);
            }

            stringToUpper(auxiliarApellido);
            strcpy(listaEmployee[indice].lastName, auxiliarApellido);
            printf("\n\nEL EMPLEADO HA SIDO MODIFICADO!\n\n");
            retorno=indice;
            break;

        case 3:

            printf("Ingrese el nuevo salario del empleado:");
            fflush(stdin);
            gets(auxiliarSalario);
            while(esNumerico(auxiliarSalario)==0)
            {
                printf("Usted ha ingresado un tipo de salario incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxiliarSalario);
            }

            salario = atoi(auxiliarSalario);
            listaEmployee[indice].salary = salario;
            printf("\n\nEL EMPLEADO HA SIDO MODIFICADO!\n\n");
            retorno=indice;
            break;

        case 4:

            printf("Ingrese el nuevo sector del empleado:");
            fflush(stdin);
            gets(auxiliarSector);
            while(esNumerico(auxiliarSector)==0)
            {
                printf("Usted ha ingresado un tipo de sector incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxiliarSector);
            }
            sector = atoi(auxiliarSector);
            listaEmployee[indice].sector = sector;
            printf("\n\nEL EMPLEADO HA SIDO MODIFICADO!\n\n");
            retorno=indice;
            break;

        default:
            retorno = -3;
            break;
        }
    }
    else
    {
        retorno = -3;
    }

    return retorno;
}



int sortEmployees(Employee* list, int len, int order)
{
    Employee auxiliarEmpleado;
    int i;
    int j;

    char auxiliarOpcion[50];
    int opcion;


    printf("\n\nComo desea ordenar la lista? 1 - POR APELLIDO / 2 - POR SECTOR: \n");
    fflush(stdin);
    gets(auxiliarOpcion);


    while(esNumerico(auxiliarOpcion)==0)
    {
        printf("Usted ha ingresado una opcion incorrecta. Ingrese nuevamente: ");
        fflush(stdin);
        gets(auxiliarOpcion);
    }
    opcion=atoi(auxiliarOpcion);


    switch(opcion)
    {
    case 1:
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {

                if(strcmp(list[i].lastName,list[j].lastName)>order)
                {
                    auxiliarEmpleado=list[i];
                    list[i]=list[j];
                    list[j]=auxiliarEmpleado;
                }

            }
        }
        break;

    case 2:
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {

                if(list[i].sector > list[j].sector)
                {
                    auxiliarEmpleado=list[i];
                    list[i]=list[j];
                    list[j]=auxiliarEmpleado;
                }

            }
        }
        break;

    default:
        printf("\n\nNO SE REALIZARON MODIFICACIONES. Se mostrara la lista sin ordenar.\n");
        break;

    }
}
**/
