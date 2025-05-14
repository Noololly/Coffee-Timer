# Coffee-Timer

While on work experience I was given a task to make something with some neopixels using Simulink (the software that the company uses for a lot of prototyping).

I decided to make a coffee timer with a neopixel ring that decrements one LED - turning it to green every 5 minutes.

Before attempting this in Simulink, I wrote it in C++ with the arduino IDE.
I used the [Adafruit NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel) library to interface with the LED's, its very easy to use and massively versatile.

I used some logic to keep track of the time using `milis()` (the time since the arduino started in miliseconds) and used that value to calculate every time 5 minutes passed.

At the end of the timer, all of the lights will be green, and then they will flash to alert you to take a break, grab some coffee, and refresh your mind before you sit back down to resume working.

## Some photos

<img src="https://github.com/user-attachments/assets/96c32ca3-35f3-4f12-b15e-99fab9106c2f" width="200px"/>
<img src="https://github.com/user-attachments/assets/0649f82a-dd50-45ff-8b4f-bfe8bdc5e863" width="200px"/>
<img src="https://github.com/user-attachments/assets/1c4f832a-6be7-4de2-876d-ec3ca2c960b9" width="200px"/>
<img src="https://github.com/user-attachments/assets/c1238301-d077-4051-9cac-8ae47c131702" width="200px"/>

