# PIC18F4580 External Interrupts

A hands-on Embedded C project demonstrating external interrupts on the PIC18F4580 microcontroller using MPLAB C18 and Proteus simulation.

## Objectives
- Understand external interrupt handling.
- Configure INT0, INT1, and INT2.
- Learn interrupt registers and edge-trigger selection.
- Implement an Interrupt Service Routine (ISR) to toggle an LED.

## Hardware
- PIC18F4580 microcontroller
- Switch
- Pull-up resistor
- LED with current-limiting resistor

## Software Tools
- MPLAB IDE / MPLAB C18
- Proteus Design Suite

## Interrupt Register Reference

| Register | Function                                          |
|----------|---------------------------------------------------|
| RCON     | Enables or disables the interrupt priority system |
| INTCON   | Global interrupt control and INT0 control         |
| INTCON2  | External interrupt edge selection                 |
| INTCON3  | INT1 and INT2 enable, flag, and priority control  |

## Source Files
- `ext_intr0.c` — INT0 external interrupt
- `ext_intr1.c` — INT1 external interrupt
- `ext_intr2.c` — INT2 external interrupt

## Learning Outcomes
- Register-level microcontroller programming
- External interrupt configuration
- ISR implementation
- Hardware simulation and debugging

## Author
Raju Malekar

If you find this project useful, feel free to explore the source code and share your feedback.
