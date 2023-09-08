#include "mbed.h"
#include "arm_book_lib.h"

//main de prueba
int main(){

    BusIn pines(D2,D3,D4,D5,D6,D7);
    pines.mode(PullDown);
    pines.operator[](D2);

    PortOut salida( PortB, LED1);

}
/* int main()
{
    DigitalIn gasDetector(D2);
    DigitalIn overTempDetector(D3);
    DigitalIn aButton(D4);
    DigitalIn bButton(D5);
    DigitalIn cButton(D6);
    DigitalIn dButton(D7);

    DigitalOut alarmLed(LED1);

    gasDetector.mode(PullDown);
    overTempDetector.mode(PullDown);
    aButton.mode(PullDown);
    bButton.mode(PullDown);
    cButton.mode(PullDown);
    dButton.mode(PullDown);

    alarmLed = OFF;

    bool alarmState = OFF;

    while (true) {

        if ( gasDetector || overTempDetector ) {
            alarmState = ON;
        }

        alarmLed = alarmState;

        if ( aButton && bButton && !cButton && !dButton) {
            alarmState = OFF;
        }
    }
} */