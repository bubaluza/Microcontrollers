# HELLO WORLD
Flashing a LED on a micro aka. Hello World its the first step to do on any hardware. 
>Those who  blink a LED,  rule the world!

The structure of the software it's quite simple. Must set a HIGH sign on a pin which a LED its connected and them set a LOW sign at same pin, repeting the process infinitely.

As the program are in assembly ( thats right, dont run from that), delay function are not ready onboard ( a least on the clean assembly for 8051) and we must do that.

# Delay in Assembly

Delay are functions that spend machine time doing 'nothing'. The main idea for that it's use instructions in a way that the machine run-in-place. 

Every instruction that we use spend a 'cycles' to be perfomed. The time that a instructions takes to be perfomed it's directly related with the oscillator used on the system(because of the generated frequency)  plus the cycles the instruction requires. In most cases are used a crystal oscillator( and so this project). To know machine cycle frequency of a micro:

``machine cycle frequency=(1*BusMicro)/(frequency of the oscillator)``

Where BusMicro are the specific Bus number of the micro. In 8051 this var are 12.

So every one cycle that a microprocessor run, it spend **machine cycle frequency**.

To know how much time takes a instruction:

``time spend=(machine cycle frequency)*(cycles of the instruction)``

Considering that the used crystal oscillator has 12Mhz, every cycle takes:

``machine cycle frequency=(1*BusMicro)/(frequency of the oscillator)``

``12/12E6 = 1us``

# Delay Program

The delays functions in the program are divided in 3 fuctions
* DELAY1S
* DELAY100
* DELAY1MS

### DELAY1S
Make 1 seconds delay. Call 10 times DELAY100.
### DELAY100
Make 100 milliseconds delay. Call 100 times DELAY1MS.
### DELAY1MS
Make 1 milliseconds delay. Using the instruction NOP that waste 1 cycle, we do 5 in a row, wasting 5 cycle and more 2 cycle with DJNZ. This repeat 150 times resulting in 1050 cycles. 1050 * frequency = 1050*1e-6 grant us 1.05ms.
