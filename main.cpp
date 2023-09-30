#include "mbed.h"
#include "arm_book_lib.h"

 int main(){
    BusIn pines(D2,D3,D4,D5,D6,D7);
    pines.mode(PullDown);
    BusOut salida(LED1,LED2,LED3);

    while(true){
        /* BUS IN
        La logica en esta parte es hacer un shifteo y luego una and con 1 si me devuelve 1
        es porque esta en valor alto esa entrada. Esta funcion pines.read() devuelve una mascara 
        en funcion de como fue definida, pero como invertida, porque seria algo asi,
        en la posicion 0 te devuelve el valor de D2, D7D6D5D4D3D2.     
        */

         /* BUS OUT
         Media parecida a bus in, la funcion salida.write(), escribe en la mascara de bits
         segun como la hayas definido en este caso seria LED3LED2LED1.
         Luego agrege ese printF que me sirvio para debugger el codigo y lo deje.
        */
        if ( pines.read()  & 1 || (pines.read() >> 1) & 1 ) {
            salida.write(1);
            printf("%s\n", "ON");
        }

        if ( (pines.read() >> 2) & 1 && (pines.read() >> 3) & 1 && !((pines.read() >> 4) & 1) && !((pines.read() >> 5) & 1)) {
            salida.write(0);
            printf("%s\n", "OFF");
        }
    }

} 

/*     while(true){
        //Aca pude notar que toma los ints en binario asi que para prender los leds
        //Segun como los tengo definidos serian 1(001),2(010)y 4(100);
        salida.write(1);
        delay(250);
        salida.write(2);
        delay(250);
        salida.write(4);
        delay(250);
        //std::cout << std::hex << pines.read() << std::endl;
        printf("%s\n", "Hello World");
        printf("Número hexadecimal en minúsculas: %x\n", pines.read());
        if ((pines.read() >> 1) & 1) {
        printf("El Segundo elemento está en valor alto (1).\n");
            } else {
        printf("El Segundo elemento no está en valor alto (0).\n");
            }

    } */

