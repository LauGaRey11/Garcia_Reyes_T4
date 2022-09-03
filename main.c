/* Laura García Reyes  */

#include <stdio.h>
#include "fsl_gpio.h"
#include  "fsl_clock.h"
#include "fsl_port.h"

int main(void) {

	 gpio_pin_config_t gpio_output_config = {
			        kGPIO_DigitalOutput, 1,
	 };
	 gpio_pin_config_t gpio_input_config = {
	 			    kGPIO_DigitalInput, 1,
	 };

	 uint8_t input_sw2 = 0;
	 uint8_t input_sw3 = 0;

	 CLOCK_EnableClock(kCLOCK_PortA);
	 CLOCK_EnableClock(kCLOCK_PortB);
	 CLOCK_EnableClock(kCLOCK_PortC);
	 CLOCK_EnableClock(kCLOCK_PortE);

	 PORT_SetPinMux(PORTB, 21u, kPORT_MuxAsGpio);
	 	 GPIO_PinInit(GPIOB, 21u, &gpio_output_config);
	 PORT_SetPinMux(PORTB, 22u, kPORT_MuxAsGpio);
	 	 GPIO_PinInit(GPIOB, 22u, &gpio_output_config);
	 PORT_SetPinMux(PORTE, 26u, kPORT_MuxAsGpio);
	 	 GPIO_PinInit(GPIOE, 26u, &gpio_output_config);
	 PORT_SetPinMux(PORTA, 4u, kPORT_MuxAsGpio);
	 	 GPIO_PinInit(GPIOA, 4u, &gpio_input_config);
	 PORT_SetPinMux(PORTC, 6u, kPORT_MuxAsGpio);
	 	 GPIO_PinInit(GPIOC, 6u, &gpio_input_config);

	 while(1) {

		 input_sw2 = GPIO_PinRead(GPIOC, 6u);
		 input_sw3 = GPIO_PinRead(GPIOA, 4u);

		 if(( 0 != input_sw2 ) && ( 0 != input_sw3)){

			 GPIO_PortClear (GPIOB, 1 << 22);;
			 SDK_DelayAtLeastUs (100000, 21000000); //rojo
			 GPIO_PortSet (GPIOB, 1 << 22);;
			 SDK_DelayAtLeastUs (100000, 21000000);

			 GPIO_PortClear (GPIOE, 1 << 26);
			 SDK_DelayAtLeastUs (100000, 21000000);//verde
			 GPIO_PortSet (GPIOE, 1 << 26);
			 SDK_DelayAtLeastUs (100000, 21000000);

			 GPIO_PortClear (GPIOB, 1 << 21);
			 SDK_DelayAtLeastUs (100000, 21000000);//azul
			 GPIO_PortSet (GPIOB, 1 << 21);
			 SDK_DelayAtLeastUs (100000, 21000000);
		 }

		 else if(( 1 != input_sw3 ) && ( 0 != input_sw2 )){

			 GPIO_PortToggle (GPIOB, 1 << 21);
			 GPIO_PortToggle (GPIOB, 1 << 22);
			 GPIO_PortToggle (GPIOE, 1 << 26);
			 SDK_DelayAtLeastUs (100000, 21000000);
		 }

		 else if(( 0 != input_sw3 ) && ( 1 != input_sw2 )){

			 GPIO_PortClear (GPIOB, 1 << 22);;
			 SDK_DelayAtLeastUs (30000, 21000000); //rojo
			 GPIO_PortSet (GPIOB, 1 << 22);;
			 SDK_DelayAtLeastUs (30000, 21000000);

			 GPIO_PortClear (GPIOE, 1 << 26);
			 SDK_DelayAtLeastUs (30000, 21000000);//verde
			 GPIO_PortSet (GPIOE, 1 << 26);
			 SDK_DelayAtLeastUs (30000, 21000000);

			 GPIO_PortClear (GPIOB, 1 << 21);
			 SDK_DelayAtLeastUs (30000, 21000000);//azul
			 GPIO_PortSet (GPIOB, 1 << 21);
			 SDK_DelayAtLeastUs (30000, 21000000);
		 }

		 else{
			 GPIO_PortToggle (GPIOB, 1 << 21);
			 GPIO_PortToggle (GPIOB, 1 << 22);
			 GPIO_PortToggle (GPIOE, 1 << 26);
			 SDK_DelayAtLeastUs (30000, 21000000);
		 }
	 }

	 return 0 ;
}

