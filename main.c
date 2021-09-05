#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    //uso de while y do while
    char seguir;
    seguir = 's'; //si no la declaramos, no es undefined, null, ni nada. Es basura que queda la memoria y en el transistor.

    while(seguir == 's'){
        printf("Quiere continuar?: ");
        fflush(stdin);
        scanf("%c", &seguir);
    }
    printf("Salimos del while \n");

    //ahora con do while. Ambos funcionan, este si entras una vez es mas acertado.
    //el do while entonces lo vamos a usar cuando queremos que entre por lo menos una vez

    char seguirConDo;
    do{
        printf("Quiere continuar?: ");
        fflush(stdin);
        scanf("%c", &seguirConDo);
    }while(seguirConDo == 's'); //obligatorio el ; al final de la condicion de do while
    printf("Salimos del do while \n");

    /********************* VACUNATORIO COMPLETO BIEN HECHO Y TESTEADO *****************
    *Tarea: Vacunatorio
    *Se necesita llevar el registro de un vacunatorio. Para ello se podrá registrar los datos de las personas vacunadas mientras el usuario quiera.
        De cada vacunado se solicita:
        -nombre (solo incial)
        -edad ( mayor o igual a 12)
        -vacuna (“r” para rusa, “c” para china, “a” para americana ).
        Si la edad esta entre 12 y 17 años ambos incluidos solo se permite la vacuna americana.
        -dosis (“p” en caso de ser la primer dosis o “s” en caso de ser la segunda dosis)
        -sexo( “f” o “m” )
    *Informar:
        a- Promedio de edad de los que se vacunaron con la rusa. Listo!
        b- Nombre y vacuna de la mujer con más edad. Listo!
        c- De las personas que recibieron la vacuna americana que porcentaje son mayores de edad.Listo!
        d- Porcentaje de los que están vacunados con 2 dosis sobre el total de vacunados. Listo!
        e- Vacuna menos inoculada. Listo!
    */

    char nombre; //al ser chars de tipo  '%c', no lleva vector[]
    int edad;
    char vacuna,
         dosis,
         sexo,
         seguirConDoWhile;
    //A
    float promedioEdadVacunaRusa;
    int contadorRusa = 0;
    int acumuladorEdadVacunadosRusa = 0;
    //B
    int flag = 1;
    char nombreMujerMayorEdad;
    char vacunaMujerMayorEdad;
    int mujerMayorEdad = 0;
    int hayMujeres = 0;
    //C
    int contadorAmericana = 0;
    int contadorAmericanaSoloMayores = 0;
    float porcentajeDeMayoresConAmericana = 0;
    //D
    int contadorTotalVacunados = 0;
    int contadorDosDosis = 0;
    float porcentajeDosDosis = 0;
    //E
    char vacunaMenosInoculada;
    int contadorChina = 0;

    do{
        //Pido datos y valido
        fflush(stdin);
        printf("Ingrese la inicial de su nombre: ");
        fflush(stdin);//fflush entre el printf y el scanf
        scanf("%c", &nombre);//no usa comilla siple aqui el %c. La variable si usa &.
        //No uso gets(nombre) porque es para string
        printf("su nombre es %c \n", nombre);

        printf("Ingrese su edad: ");
        scanf("%d", &edad);//&edad guarda el valor en la direccion de la RAM donde esta edad
        while(edad > 120 || edad < 12){
            printf("Imposible! Reingrese su edad \n");
            scanf("%d", &edad);
        }
        if(edad < 18){
            vacuna = 'a';
        }else{
            fflush(stdin);
            printf("Ingrese la inicial de su vacuna. r para rusa, c para china o a para amaericana: ");
            scanf("%c", &vacuna);
            vacuna = tolower(vacuna);
            //dentro de condicionales como if o while, comilla simple para el &c
            while(vacuna !='r' && vacuna !='c' && vacuna !='a'){
                printf("Incorrecto. Reingrese su vacuna, r, c o a: ");
                fflush(stdin);
                scanf("%c", &vacuna);
            }
        }

        fflush(stdin);
        printf("Ingrese su dosis. p para la primera, s para la segunda: ");
        scanf("%c", &dosis);
        dosis = tolower(dosis);

        while(dosis !='p' && dosis !='s'){
            fflush(stdin);
            printf("Incorrecto. Reingrese p o s: ");
            scanf("%c", &dosis);
        }

        //D)
        if(dosis == 's'){
            contadorDosDosis++;
        }
        contadorTotalVacunados++;

        printf("Ingrese su sexo, f o m: ");
        fflush(stdin);
        scanf("%c", &sexo);
        sexo = tolower(sexo);
        while(sexo !='f' && sexo !='m'){
            printf("Incorrecto. Reingrese f o m: ");
            fflush(stdin);
            scanf("%c", &sexo);
        }

        //B
        /*
        if(sexo == 'f'){
            if(flag == 1){
                nombreMujerMayorEdad = nombre;
                vacunaMujerMayorEdAD = vacuna;
                mujerMayorEdad = edad;
                flag = 0;
            }else{
                if(mujerMayorEdad < edad){
                    nombreMujerMayorEdad = nombre;
                    vacunaMujerMayorEdad = vacuna;
                }
            }
        }
        */
        //Esta version es mucho mejor. Mas clara de leer. Siemrpe debe ser f true &&
        // flag es true de por si porque vale 1 y es truly. Como luego la cambio a 0, se vuelve falsy
        //Luego, valido con or, ya que flag es falsie en la 2da iteracion, la mujer de mayor edad
        if(sexo == 'f' && (flag || edad > mujerMayorEdad))
            {
                nombreMujerMayorEdad = nombre;
                vacunaMujerMayorEdad = vacuna;
                mujerMayorEdad = edad;
                flag = 0;
                hayMujeres = 1;
            }

        //A)
        switch(vacuna){
            case 'r':
                acumuladorEdadVacunadosRusa = acumuladorEdadVacunadosRusa + edad;
                contadorRusa++;
            break;

            case 'c':
                contadorChina++;
            break;

            case 'a':
                if(edad >= 18){
                    contadorAmericanaSoloMayores++;
                }
                contadorAmericana++;
            break;
        }

        printf("Quiere continuar?: ");
        fflush(stdin);
        scanf("%c", &seguirConDoWhile);
        //seguirConDoWhile = getc();
        seguirConDoWhile = tolower(seguirConDoWhile);

    }while(seguirConDoWhile == 's');
    printf("Salimos del do while \n");

    //A)Importante castear. Lo hago distinto a 0 asi no me da error
    if(contadorRusa !=0){
        promedioEdadVacunaRusa = (float) acumuladorEdadVacunadosRusa / contadorRusa;
    }
    //C)
	porcentajeDeMayoresConAmericana = (float) (contadorAmericanaSoloMayores * 100) / contadorAmericana;

	//D)
	porcentajeDosDosis = (float) (contadorDosDosis * 100) / contadorTotalVacunados;

	//E)
	if(contadorRusa < contadorChina && contadorRusa < contadorAmericana){
        //vacunaMenosInoculada = 'r';
        vacunaMenosInoculada = contadorRusa;
	}
	else if(contadorChina <= contadorAmericana){
        //vacunaMenosInoculada = 'c';
	    vacunaMenosInoculada = contadorChina;
    }
    else{
        //vacunaMenosInoculada = 'a';
        vacunaMenosInoculada = contadorAmericana;
    }

    if(contadorRusa !=0){
        printf("A) El promedio de edad de los vacunados con la Sputnik V es de %.2f \n", promedioEdadVacunaRusa);
    }
    else{
        printf("A) No se registraron vacunados con Sputnik V \n");
    }

    if(hayMujeres !=0){
        printf("B) El nombre de la mujer de mayor edad vacunada es %c y su vacuna es %c \n", nombreMujerMayorEdad, vacunaMujerMayorEdad);
    }
    else{
        printf("B) No se registraron mujeres \n");
    }

    if(contadorAmericanaSoloMayores !=0){
        printf("C) El porcentaje de mayores de edad que se vacunaron con Pfizer es de %.2f %% \n", porcentajeDeMayoresConAmericana); //con %% imprimo el simbolo '%'
    }
    else{
        printf("C) Ningun mayor de edad se vacuno con Pfizer \n");
    }

    if(contadorDosDosis !=0){
        printf("D) El porcentaje de vacunados con dos dosis es de %.2f %% \n", porcentajeDosDosis);
    }
    else{
        printf("D) No hubo segundas dosis \n");
    }

    printf("E) La vacuna menos inoculada es ");

    //distintos if, con else if no funca porque es una unica condicion
    if(vacunaMenosInoculada == contadorRusa){
        printf(" la rusa ");
    }
    if(vacunaMenosInoculada == contadorChina){
        printf("la china ");
    }
    if(vacunaMenosInoculada == contadorAmericana){
        printf(" la americana ");
    }
    printf("\n");

    system("pause");
    return 0;
}
