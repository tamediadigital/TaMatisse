#  TaMatisse

TaMatisse aka the Tamedia Robo-Painter is a small Arduino painting robot that has been developed for the Zukunftstag 2017 at Tamedia.
The Zukunftstag is a special day in Switzerland where 10-12 year old kids join their parents at work to get an impression of what their working day looks like.

The name of this project is inspired by [Henri Matisse](https://en.wikipedia.org/wiki/Henri_Matisse) - so our bots have somebody to look up to.

For this project, we designed the robots from scratch, 3D-printed the chassis and the wheels and powered them with an Arduino board and motors. We went through a number of iterations starting from [a very rudimental version](https://drive.google.com/open?id=1XHYLBMp3aTwPATsHcA2afbOtKss3Xp65) which gave some [first promising results](https://drive.google.com/open?id=1dIKPrNfxLv_RLu-L1qv47xOSfsh7SLXa).

That wasn't enough of course!

So we continued improving the design until we [finalized the chassis](https://drive.google.com/open?id=1kGrtJrTfS0Q7jIdkaZlRN-G9279_aEaJ) and printed the various components as you can see [here](https://drive.google.com/open?id=0BwoCo__hMSJ6NEFHOGhoUWRwV2ZKOFBrdkJ0M2RfVTFDbWM0) and [here](https://drive.google.com/open?id=0BwoCo__hMSJ6SFZKb2V2S29RN1BaV2FIQ3VYTy1DRmxQTV9F). Overall, it was [a lot of work](https://drive.google.com/open?id=0BwoCo__hMSJ6SUVaUnR0QjBXb0xCNW9nZUJrU2hhVGdiVzZz) but we are very proud of [the functioning protoype](https://drive.google.com/open?id=0BwoCo__hMSJ6RV90MGFNMHpCRGxlZ05hVXpPWWNkQTBjVlBn).

We were particularly impressed by the [precision](https://drive.google.com/open?id=0BwoCo__hMSJ6eWh6UDM4QzQtRDBOaHNTTVJySDduU3U4T1pR) in the first test run and so we started getting creative, teaching TaMatisse a lot of [new patterns](https://drive.google.com/open?id=1D4qrHpUrIhioHyt2ebI3qsHQg5HWzTjb) to draw more and more complicated pictures.

We've created a small library that holds some geometrical primitives (straight line, curve,....) that can be used to draw larger, more complex drawings.

We want to have the kids figure out the right sequence and parameters for these primitives in order to produce shapes as simple as squares and circles up to more complex ones such as stars or flowers.

The extra challenge in this version of TaMatisse is that the marker never leaves the paper so you really need to figure out the optimal path to obtain a clean shape!

# Technical Specs

If you're interested to build TaMatisse and try it out for yourself, here's what you need:

* Access to a 3D printer to print the chassis and the wheels
* An Arduino Nano (sold in many online stores, https://store.arduino.cc/arduino-nano)
* 2 x 28BYJ-48 5V Stepper motors with 2 x Uln2003 driver board (buy the board and the board in one package)
* On/Off Switch (we used Universal Car Styling 16A 12V LED Dot Light Car Boat Round Rocker ON/OFF SPST Switch https://www.aliexpress.com/item/32829587850.html?spm=a2g0s.9042311.0.0.649d4c4dOiJ8gw)
* Battery-holder (4 x AA, next to each other. We used https://www.aliexpress.com/item/32818907820.html?spm=a2g0s.9042311.0.0.649d4c4dOiJ8gw)
* Some Dupont Cable 20cm 2.54mm Female-Female - best with color codes.
* Soldering iron to combine 5V and ground pins of the two stepper motor boards, the Arduino and the battery pack / power switch. 
* 2 x Rubber bands for around the wheels
* 4 x AA Batteries
* Whiteboard markers (size is optimized for the lyreco brand)
* PlatformIO-IDE - an opensource IoT platform for compiling the git-repo and upload the code to the bot.
* For beginners, please refer to [this visual guide](HOWTO.md).

Happy painting!
