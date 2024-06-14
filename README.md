Introduction to Computers - LABS ; Assembly, MSP430
Participants: Romi Lustig & Rotem Katzav

----------------------------------

This Git includes 6 files:
5 files represent different layers in the system. This makes the code portable, and able to switch between different MSP430x4xx, MSP430x2xx families. After investigating with Assembly commands, we were now able to differentiate the layers within the code.
(Switching the CPUs is done by changing the BSP layer)
1 file is a 'header', with all of the "define" used.
List of all files:
1. bsp.s43 - Board Support Package; configurate registers.
    * Includes a header file: bsplab5.h
2. hal.s43 - Hardware Abstraction Layer; inculdes routines in the system that control the interface with the peripheral components (registers).
3. hal_timer.s43 ; includes routines as well - related only to the timers.
4. api.s43 - Application Programming Interface; Higher level written code, where the access to the peripheral components is made only using the HAL layer.
5. main.s43 ; Top layer of the system. Controls all interruptions made due to timers.

----------------------------------

MAIN IDEA - 
This system has the ability to do the following tasks:
1. Display a timer in the order MM:SS, that counts to 2 minutes.
2. Display an cycle count for a given program.
(for PRE-LAB files)
These tasks are done when requestedd - using push buttons PB0, PB1. The main idea is performing interrupts, and using timers for both tasks.

----------------------------------

Enjoy!
