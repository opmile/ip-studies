#include <stdio.h>

float convertTemperatureToCelsius(float tempFh) {
    return 5 * (tempFh - 32) / 9; // equivalente a = 5 / 9 * ( F – 32 )
}

int main() {
    
    float tempBsbFh = 85, tempFh;

    printf("SUA TEMPERATAURA EM FAHRENHEIT = ");
    scanf("%f", &tempFh);

    printf("TEMPERATURA MÁX. EM BRASÍLIA = %.2f °C\n", 
        convertTemperatureToCelsius(tempBsbFh));

    printf("SUA TEMPERATURA = %.2f °C\n", 
        convertTemperatureToCelsius(tempFh));

    return 0;
}