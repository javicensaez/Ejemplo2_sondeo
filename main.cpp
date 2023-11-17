/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define WAIT_TIME_MS 1 //Etiqueta con la constante del tiempo de espera entre iteración del while

DigitalOut led(D5); //Diodo led conectado en el pin D5
DigitalIn boton(D4); //Boton conectado en el pin D4, de tipo interrupcion



int main()
{
    int valorAnteriorBoton=0; //Variable para guardar cuanto valia el boton en la interaccion anterior
    int valorBoton=0; // variable para guardar el valor actual del boton
    printf("Hola mundo\n"); //Mensaje de comienzo de programa



    while (true) // Bucle para que se ejecute constantemente
    {
        valorBoton=boton; //Guardo el valor actual del boton
        if(valorAnteriorBoton&&!valorBoton){ //Se ejecuta en el flanco de bajada del boton. cuando ahora el voton sea 0 y antes fuese 1.
            led=!led; //En el momento que suelto el boton cambio el valor actual del led.
            printf("cambio\n");
        }


        valorAnteriorBoton=valorBoton; //Almaceno cuanto valia el boton y espero un tiempo antes de volver a mirar
        thread_sleep_for(WAIT_TIME_MS); //Dentro del bucle no hacemos nada, funciona por interrupciones.
    }
}
