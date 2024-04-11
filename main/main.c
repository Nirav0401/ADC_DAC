// Receive analog input

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "driver/dac.h"


#define pin25 GPIO_NUM_25

void app_main(void)
{
    uint32_t voltage;

    // Configure ADC1 capture width
    // 12 bit decimal value from 0 to 4095
    adc1_config_width(ADC_WIDTH_BIT_12); 
    // Configure the ADC1 channel (ADC1_CHANNEL_6 - pin 34), and setting attenuation (ADC_ATTEN_DB_11)
    adc1_config_channel_atten(ADC1_CHANNEL_6, ADC_ATTEN_DB_11);
 
    /********************************************DAC_VALUE_OUTPUT**********************************************/
    //dac channel and width configuration
    
    int voltage1 = 0;
    int delta = 10;
    
    gpio_pad_select_gpio(pin25);                    // Defines GPIO functionality for the pin
    gpio_set_direction(pin25, GPIO_MODE_OUTPUT);    // Pin input/output definition
    
    /***********************************************************************************************************/

    while (1) 
    {

        
        // Take an ADC1 reading on a single channel (ADC1_CHANNEL_6 pin 34)
        // 11dB attenuation (ADC_ATTEN_DB_11) gives full-scale voltage 0 - 3.9V
        // 4053 ~ 3.86V
        voltage = adc1_get_raw(ADC1_CHANNEL_6); 
        printf("%d\n", voltage);
        vTaskDelay(100 / portTICK_PERIOD_MS);

        /***********************************************DAC_VALUE_OUTPUT******************************************/

        dac_output_enable(DAC_CHANNEL_1);           // Enable analog output at pin 25
        dac_output_voltage(DAC_CHANNEL_1, voltage1); // Set analog level
        
        // Generate variable voltage number between 0 to 255 (3.3V)
        voltage1 = voltage1 + delta;
        if (voltage1>240 || voltage1<10) {
        delta=(-1)*delta;
        }
        printf("%d\n", voltage1);

        vTaskDelay(1000 / portTICK_PERIOD_MS);

        /**********************************************************************************************************/

    }
}

