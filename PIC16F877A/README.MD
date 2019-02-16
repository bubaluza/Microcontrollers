#  PIC16F877A
   This directory its exclusive for programs that run in PIC16F877A. 
   
   ![PIC16F877A](https://i1.wp.com/microcontrollerslab.com/wp-content/uploads/2015/08/PIC16F877A-microcontroller.jpg?resize=300%2C225)
# Uploading code
To put a programmed software on PIC requires:
   - The hex code of the programmed sofware
   - Hardware to make the bridge across hex file and PIC (upload)
#### Hex code
The hex code can be obtained from a software designed to program PIC or a compiler that can produce a hex **to microprocessors PIC**.
The main reason that not any compiler can be used it's 'cause PIC programms have particularities with the hardware, like configure bits. The compiler must be setup to the chosen PIC 'cause these configuration bits can be different from PIC to PIC. I used IDEs which produced my hex files ( MIKROC, MBLAB, MikroProg).

#### Hardware upload
Uploading a PIC program can be made with differents ways. Using a PICKIT its the most easy but have the inconvenience of buy that item. Considering it and that I have a arduino on my hands, i found the project **Ardpicprog** that teach how to make the bridge to upload PIC programs using a arduino. With the help of my teacher, we changed the provide file from the project to make it work more appropriately. The file can be found [here](https://github.com/bubaluza/Microcontrollers/blob/master/PIC16F877A/arduinoPic.ino).
For more information about the Ardpicprog project(e.g electric schematic, suggested PCB) see at [ardpicprog](http://rweather.github.io/ardpicprog).

# Hello World
Like every beginning on a languague, we need to make the famous "Hello World". In hardware, the hello world  it's made intented to blink a LED on visible frequency. Was programmed in assembly and C.

# Voltmeter
The need to measure physical quantity made a branch technology. A voltmeter it's a device that can measure the Voltage on a eletrical cable. The program covers the voltage measure on a potenciometer on a range of o to 5 Volts and show on a LCD display. Programmed in C.


