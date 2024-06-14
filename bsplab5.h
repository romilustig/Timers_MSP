#ifndef _bsp_H_
#define _bsp_H_

//#include  <msp430.h>          // MSP430x2xx
#include  <msp430g2553.h>  // MSP430G2553

#define  DataSegStart      0x200
#define  CodeSegStart      0xC000
#define  StackTosStart     0x0400

#define   debounceVal      250
#define   delay62_5ms      0xFFFF

// LEDs abstraction
#define LEDsArrPort        &P1OUT
#define LEDsArrPortDir     &P1DIR
#define LEDsArrPortSel     &P1SEL

// PushButtons abstraction
#define PBsArrPort	   &P1IN 
#define PBsArrIntPend	   &P1IFG 
#define PBsArrIntEn	   &P1IE
#define PBsArrIntEdgeSel   &P1IES
#define PBsArrPortSel      &P1SEL 
#define PBsArrPortDir      &P1DIR
#define PB0                0x01
#define PB1                0x02
#define PB2                0x04
#define PB3                0x08


// Port specific defines
#define   LCD_Data_PortSel  &P2SEL
#define   LCD_Data_PortDir  &P2DIR
#define   LCD_Data_Port     &P2OUT

#define   LCD_Control_Port      &P1OUT
#define   LCD_Control_PortSel   &P1SEL
#define   LCD_Control_PortDir   &P1DIR

// E pin of lcd connected to pin5
// RS Pin is connected to pin6
// RW Pin is connected to pin7
#define LCD_E_PIN  0x20
#define LCD_RS_PIN 0x40
#define LCD_RW_PIN 0x80

// Timer specific defines
#define CAPTURE_TIMER_DIR       &P2DIR 
#define CAPTURE_TIMER_SELECT    &P2SEL

#define pull_up_debounce 150

delay     MACRO  cycles
             LOCAL  L
             mov.w  cycles,R15     
L            dec.w  R15                     
             jnz    L
             ENDM
               
               
delay_ms_m MACRO
LOCAL delay_rotuine
          mov #10, r12
delay_rotuine:          
          delay #31
          dec r12
          cmp #0, r12
          jne delay_rotuine
          delay #20

          ENDM

delay_ms_loop MACRO count
LOCAL inner_delay_routine
          mov #count, r11
inner_delay_routine:
          delay_ms_m
          dec r11
          cmp #0, r11
          jne inner_delay_routine
          ENDM

#endif

