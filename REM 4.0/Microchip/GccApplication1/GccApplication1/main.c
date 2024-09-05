#define F_CPU 16000000UL  // Frecuencia del reloj en Hz

#include <avr/io.h>
#include <util/delay.h>


// Definir pines para los servomotores
#define SERVO1_PIN PB1
#define SERVO2_PIN PB2

void initServo() {
    // Configurar pines como salida
    DDRB |= (1 << SERVO1_PIN) | (1 << SERVO2_PIN);
}

void moveServo(uint8_t servoPin, uint8_t angle) {
    // Convertir el ángulo a un valor de tiempo en microsegundos
    uint16_t pulseWidth = 500 + (angle * 11);
    
    // Generar pulso PWM en el pin del servo
    PORTB |= (1 << servoPin);
    _delay_us(pulseWidth);
    PORTB &= ~(1 << servoPin);
    _delay_us(20000 - pulseWidth);  // Ciclo de trabajo de 20 ms (50 Hz)
}

int main(void) {
    initServo();

    while (1) {
        // Mover servo 1 de 0 a 180 grados
        for (uint8_t pos = 0; pos <= 180; pos++) {
            moveServo(SERVO1_PIN, pos);
            _delay_ms(15);
        }

        _delay_ms(1000);

        // Mover servo 1 de 180 a 0 grados
        for (uint8_t pos = 180; pos > 0; pos--) {
            moveServo(SERVO1_PIN, pos);
            _delay_ms(15);
        }

        _delay_ms(1000);

        // Mover servo 2 de 0 a 180 grados
        for (uint8_t pos = 0; pos <= 180; pos++) {
            moveServo(SERVO2_PIN, pos);
            _delay_ms(15);
        }

        _delay_ms(1000);

        // Mover servo 2 de 180 a 0 grados
        for (uint8_t pos = 180; pos > 0; pos--) {
            moveServo(SERVO2_PIN, pos);
            _delay_ms(15);
        }

        _delay_ms(1000);
    }

    return 0;
}

