/** led_api.c
 *
 *  @Author :iWave Systems Technologies Pvt Ltd
 *
 *  This file contains api's for LED.
 *
 *  Copyright (c) 2012-2013 iWave System Technologies Pvt Ltd.
 *
 *  All rights reserved. Copying, compilation, modification, distribution
 *  or any other use whatsoever of this material is strictly prohibited
 *  except in accordance with a Software License Agreement with
 *  iWave Systems Technologies Pvt Ltd.
 **/
#include <stdio.h>
#include <fcntl.h>

/*enum for led on/off and led status*/
enum {
	LED_OFF = 20,
	LED_ON,
	LED_STATUS,
};

/*!
 * \brief
 *  Led initialization function.
 *
 * \details
 * This function is used to open the node created.
 *  
 *
 * \param  [out] fd 
 * Returns the frame descriptor value.
 *
 */
int led_init()
{
	int fd;
	fd = open("/dev/led1", O_RDWR, 0);
	if(fd < 0)
	{
		printf("cannot open device\r\n");
		return -1;
	}
	return fd;
}

void print_info (void)
{
	printf("\n\r Select one gpio pin number");

}


int main ()
{
	int dev_fd, gpio_direction;
	char usr_opt;
	int pin_no;
	dev_fd = led_init();	
	if (dev_fd < 0)
		return -1;

	do
	{
		/*display the menu*/
		printf("\r\n");
		printf("\r\n *******************");
		printf("\r\n     LED Test       ");
		printf("\r\n *******************");
		printf("\n\r A  LED ON		");
		printf("\n\r B  LED OFF		");
		printf("\n\r c  LED_STATUS      ");
		printf("\n\r X  Exit		");
		printf("\n\r Select your option:");
		
		/*store the option in usr_opt*/
		usr_opt = getchar ();
		getchar ();
		switch(usr_opt)
		{
			case 'A':
			case 'a':
				printf ("\nLED lights are ready to glow\r\n");
				print_info ();
				/*store the pin number in pin_no*/
				scanf("%d",&pin_no);
				getchar ();
				if(pin_no >=0 && pin_no<=99)
				{
					printf ("LED ON \r\n");
					ioctl (dev_fd, LED_ON, pin_no);
				}
				else
				{
					printf ("Enter the correct option\r\n");
				}

				break;

			case 'B':
			case 'b':
				printf ("\nLED lights are going to OFF \r\n");
				print_info ();
				/*store the pin number in pin_no*/
				scanf("%d",&pin_no);
				getchar ();
				if(pin_no >=0 && pin_no <=99)
				{
					printf ("LED OFF \r\n");
					ioctl (dev_fd, LED_OFF, pin_no);
				}
				else
				{
					printf ("Enter the correct option\r\n");
				}

				break;

			case 'C':
			case 'c':
				printf ("\nLED status going to display\r\n");
				print_info ();
				/*store the pin number in pin_no*/
				scanf("%d",&pin_no);
				getchar ();
				ioctl (dev_fd, LED_STATUS, pin_no);

				break;

			case 'X':
			case 'x':
				printf("\nUser Terminated the Application\r\n");
				//  DeInitialize the LED GPIO
				led_deinit(dev_fd);
				break;

			default:
				printf("Enter the correct option \r\n");
				return -1;
		}

	}
	while(usr_opt !='X' && usr_opt !='x');

	return 0;
}	

/*!
 * \brief
 *  Led de-initialization function.
 *
 * \details
 * This function is used to close the node created.
 *  
 * \param  [in] int dev_fd 
 * Device frame descriptor.
 *
 */

int led_deinit(int dev_fd)
{
	close(dev_fd);
}
