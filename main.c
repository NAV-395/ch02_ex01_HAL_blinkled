#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"

int main(void)
{
    cy_rslt_t result;

    result = cybsp_init() ;
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    __enable_irq();

    cyhal_gpio_init(CYBSP_USER_LED , CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG , 1); //inicializo CYBSP_USER_LED como salida

    for (;;)
    {
    	cyhal_gpio_write(CYBSP_USER_LED, 0); //esta funcion lleva al pin CYBSP_USER_LED a estado logico bajo
    	cyhal_system_delay_ms(250);          //funcion que produce retardo en ms
    	cyhal_gpio_write(CYBSP_USER_LED, 1);
    	cyhal_system_delay_ms(250);
    }
}


