# Human-Sonar
Arduino program for a digital walking stick made for an engineering term project.

Welcome to the Human-Sonar wiki!

The idea behind this project was to create a digital walking stick that outputs a tone based on the distance that it reads from a sensor. In theory, a visually impaired person could then create a picture of the world around them using the proximity readings, and be able to navigate without the need to carry around a cane!

Essentially, what this program does is take the distance reading from the sensor that we threw on our Arduino. Then we apply a linear transformation to map the data onto an audible frequency range. After that, we invert the data so that the closer frequencies are higher to be more indicative of urgency. This all hooks in to the circuit that we built to integrate a push button switch and the laser sensor.

The end product ended up being somewhat ugly, our professor joking that it was the closest to an IDE that she had seen so far. People were skeptical at first, but ended up liking it quite a bit! The range was limited due to our budget sensor, but the proof of concept was solid, we even got some free flash drives off winning the entrepreneurial prize.

{Picture when I find it, it was a breadboard and an arduino bundled together with electrical tape, and a button and laser were sticking out of it}

(copied from wiki for redundancy)
