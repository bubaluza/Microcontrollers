# HELLO WORLD
Flashing a LED on a micro aka. Hello World its the first step to do on any hardware. 
>Those who  blink a LED,  rule the world!

The structure of the software it's quite simple. Must set a HIGH sign on a pin which a LED its connected and them set a LOW sign at same pin, repeting the process infinitely. We need to put a delay between the state to the result be visible.

In assembly ( thats right, dont run from that), delay function are not ready onboard and we must do that(not considering timers).
The C language explain itself the code.

# Delay in Assembly

Delay are functions that spend machine time doing 'nothing'. The main idea for that it's use instructions in a way that the machine run-in-place. 

Every instruction that we use spend a 'cycles' to be perfomed. The time that a instructions takes to be perfomed it's directly related with the oscillator used on the system(because of the generated frequency)  plus the cycles the instruction requires. In most cases are used a crystal oscillator( and so this project). To know machine cycle frequency of a micro:

``machine cycle frequency=(1*BusMicro)/(frequency of the oscillator)``

Where BusMicro are the specific Bus number of the micro. In PIC16F877A this var are 4.

So every one cycle that a microprocessor run, it spend **machine cycle frequency**.

To know how much time takes a instruction:

``time spend=(machine cycle frequency)*(cycles of the instruction)``

Considering that the used crystal oscillator has 12Mhz, every cycle takes:

``machine cycle frequency=(1*BusMicro)/(frequency of the oscillator)``

``4/12E6 = 0.33us``

# Delay Assembly

The delays function on assembly program consist in waste 50 cycles times 250. This 12500 cycles are made 250 times resulting in 3125000 cycles. 3125000 * frequency = 3125000*0.33us grant us 1.03125 seconds.
