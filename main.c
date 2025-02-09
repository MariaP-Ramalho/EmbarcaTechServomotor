#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22 // *PARA TESTAR NO LED ALTERE DE 22 PARA 12*
#define PWM_FREQ 50 // 50Hz -> Período de 20ms
#define PWM_WRAP 20000 // Para um clock de 1MHz, 20ms = 20000 ticks

int main() {
    stdio_init_all();
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);

    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 125.0f); // Ajuste para 1MHz (125MHz/125)
    pwm_config_set_wrap(&config, PWM_WRAP);
    pwm_init(slice_num, &config, true);
    
    // Controle de ângulo do servo
    printf("Movendo para 180 graus\n");
    pwm_set_gpio_level(SERVO_PIN, 2400);
    sleep_ms(5000);
    
    printf("Movendo para 90 graus\n");
    pwm_set_gpio_level(SERVO_PIN, 1470);
    sleep_ms(5000);
    
    printf("Movendo para 0 graus\n");
    pwm_set_gpio_level(SERVO_PIN, 500);
    sleep_ms(5000);

    // Movimentação periódica entre 0 e 180 graus
    while (true) {
        // Incrementa de 0 para 180 graus
        for (uint duty = 500; duty <= 2400; duty += 5) {
            set_pwm_duty(SERVO_PIN, duty);
            sleep_ms(10);
        }
        // Decrementa de 180 para 0 graus
        for (uint duty = 2400; duty >= 500; duty -= 5) {
            set_pwm_duty(SERVO_PIN, duty);
            sleep_ms(10);
        }
    }
}
