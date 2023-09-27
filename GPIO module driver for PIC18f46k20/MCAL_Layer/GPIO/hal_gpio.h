/* 
 * File:   hal_gpio.h
 * Author: Mohamed Magdy 
 *
 * Created on September 20, 2023, 9:40 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/*Section : Includes*/

#include "../include/proc/pic18f4620.h"
#include"../mcal_std_types.h"
#include "../../MCAL_Layer/device_config.h"
#include "hal_gpio_cfg.h"

/*Section : Macro Declarations*/

#define BIT_MASK            (uint8)1 /*All operations are done with uint8 data type*/
#define PORT_PIN_MAX_NUMBER   8
#define PORT_MAX_NUMBER       5 

#define PORTC_MASK 0xFF







/*Section : Macro Functions Declarations*/
#define HWREG8(_X) (*((volatile uint8*)(_X)))

#define SET_BIT(REG,BIT_POSN) (REG |= (BIT_MASK<<BIT_POSN)) 
#define CLEAR_BIT(REG,BIT_POSN) (REG &= (~(BIT_MASK<<BIT_POSN))) 
#define TOGGLE_BIT(REG,BIT_POSN) (REG ^= (BIT_MASK<<BIT_POSN)) 
#define READ_BIT(REG,BIT_POSN) ((REG>>BIT_POSN)&BIT_MASK) 

#define MOHAMED_SET_2_BITS(REG,BIT_1ST_POSN,BIT_2ND_POSN)  (REG |= ( (BIT_MASK <<BIT_1ST_POSN) | (BIT_MASK <<BIT_2ND_POSN) ))

#define MOHAMED_CLEAR_2_BITS(REG,BIT_1ST_POSN,BIT_2ND_POSN)  (REG &= ~(( (BIT_MASK <<BIT_1ST_POSN) | (BIT_MASK <<BIT_2ND_POSN) )) )  

#define MOHAMED_TOGGLE_2_BITS(REG,BIT_1ST_POSN,BIT_2ND_POSN)  (REG ^= ( (BIT_MASK <<BIT_1ST_POSN) | (BIT_MASK <<BIT_2ND_POSN) ))  



/*Section : Data Type Declarations*/

typedef enum 
{
   GPIO_LOW=0,
   GPIO_HIGH     
}logic_t;

typedef enum 
{
   GPIO_DIRECTION_OUTPUT=0,
   GPIO_DIRECTION_INPUT     
}direction_t;

typedef enum 
{
   PIN0=0,
   PIN1,
   PIN2,
   PIN3,
   PIN4,
   PIN5,
   PIN6,
   PIN7
}pin_index_t;

typedef enum 
{
   PORTA_INDEX=0,
   PORTB_INDEX,
   PORTC_INDEX,
   PORTD_INDEX,
   PORTE_INDEX
   
}port_index_t;

typedef struct
{
    uint8 port      :3 ; /*@ref port_index_t */ /*values to use to configure the pins*/
    uint8 pin       :3 ; /*@ref pin_index_t */
    uint8 logic     :1 ; /*@ref logic_t */
    uint8 direction :1 ; /*@ref direction_t */
}pin_config_t;

/*Section : Functions Declarations*/

Std_ReturnType gpio_pin_direction_intialize (const pin_config_t *_pin_config) ;
Std_ReturnType gpio_pin_get_direction_status (const pin_config_t *_pin_config,direction_t *direction_status ) ;
Std_ReturnType gpio_pin_write_logic (const pin_config_t *_pin_config,logic_t logic) ;
Std_ReturnType gpio_pin_read_logic (const pin_config_t *_pin_config,logic_t *logic) ;
Std_ReturnType gpio_pin_toggle_logic (const pin_config_t *_pin_config) ;
Std_ReturnType gpio_pin_intialize (const pin_config_t *_pin_config) ;


Std_ReturnType gpio_double_pin_write_logic (const pin_config_t *_pin_config1,const pin_config_t *_pin_config2,logic_t logic) ;
Std_ReturnType gpio_double_pin_read_logic (const pin_config_t *_pin_config1,const pin_config_t *_pin_config2,logic_t *logic1,logic_t *logic2) ;
Std_ReturnType gpio_double_pin_toggle_logic (const pin_config_t *_pin_config1,const pin_config_t *_pin_config2) ;

Std_ReturnType gpio_port_direction_intialize (port_index_t port,uint8 direction) ;
Std_ReturnType gpio_port_get_direction_status (port_index_t port,uint8 *direction_status ) ;
Std_ReturnType gpio_port_write_logic (port_index_t port,uint8 logic) ;
Std_ReturnType gpio_port_read_logic (port_index_t port,uint8 *logic) ;
Std_ReturnType gpio_port_toggle_logic (port_index_t port) ;







#endif	/* HAL_GPIO_H */
 
  