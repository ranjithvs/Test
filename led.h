/** led.h
 *
 *  @Author     : iWave Systems Technologies Pvt Ltd
 *
 *  This file contains header implementation for led driver.
 *
 *  Copyright (c) 2012-2013 iWave System Technologies Pvt Ltd.
 *
 *  All rights reserved. Copying, compilation, modification, distribution
 *  or any other use whatsoever of this material is strictly prohibited
 *  except in accordance with a Software License Agreement with
 *  iWave Systems Technologies Pvt Ltd.
 */
/*************************************************************************
 * Change log:
 *  10/10/13: Initial file creation
**************************************************************************/

#ifndef __LED_H__
#define __LED_H__

#include <linux/device.h>
#include <linux/gpio.h>
#include <linux/cdev.h>

#define DRV_NAME        "led"
#define DEVICE_NAME     "led"

/* Major number assigned to our device driver */
static int led_major_no = 0;
dev_t led_dev_no;

static struct cdev *led_chardev = 0;

struct class *led_char_class = 0;

#define LED_OFF		20
#define LED_ON		21
#define PIN_STATUS	22

#define GPIO0_PIN_29	29
#define GPIO0_PIN_28    28
#define GPIO1_PIN_14    14
#define GPIO1_PIN_13    13
#define GPIO0_PIN_23    23
#define GPIO0_PIN_24    24
#define GPIO1_PIN_19    19
#define GPIO1_PIN_27    27

#endif
