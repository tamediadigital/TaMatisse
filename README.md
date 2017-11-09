#  TaMatisse

TaMatisse aka the Tamedia Robo-Painter is a small Arduino painting robot that has been developed for the Zukunftstag 2017 at Tamedia. 
The Zukuntfstag is a special day in Switzerland where 10-12 year old kids join their parents at work to get an impression of what their working day looks like.

The name of this project is inspired by [Henri Matisse](https://en.wikipedia.org/wiki/Henri_Matisse) - so our bots have somebody to look up to.

For this project, we designed the robots from scratch, 3D-printed the chassis and the wheels and powered them with an Arduino board and motors. We went through a number of iterations starting from [a very rudimental version](https://drive.google.com/open?id=1XHYLBMp3aTwPATsHcA2afbOtKss3Xp65) which gave some [first promising results](https://drive.google.com/open?id=1dIKPrNfxLv_RLu-L1qv47xOSfsh7SLXa). 

That wasn't enough of course!

So we continued improving the design until we [finalized the chassis](https://drive.google.com/open?id=1kGrtJrTfS0Q7jIdkaZlRN-G9279_aEaJ) and printed the various components as you can see [here](https://drive.google.com/open?id=0BwoCo__hMSJ6NEFHOGhoUWRwV2ZKOFBrdkJ0M2RfVTFDbWM0) and [here](https://drive.google.com/open?id=0BwoCo__hMSJ6SFZKb2V2S29RN1BaV2FIQ3VYTy1DRmxQTV9F). Overall, it was [a lot of work](https://drive.google.com/open?id=0BwoCo__hMSJ6SUVaUnR0QjBXb0xCNW9nZUJrU2hhVGdiVzZz) but we are very proud of [the functioning protoype](https://drive.google.com/open?id=0BwoCo__hMSJ6RV90MGFNMHpCRGxlZ05hVXpPWWNkQTBjVlBn).

We were particularly impressed by the [precision](https://drive.google.com/open?id=0BwoCo__hMSJ6eWh6UDM4QzQtRDBOaHNTTVJySDduU3U4T1pR) in the first test run and so we started getting creative, teaching TaMatisse a lot of [new patterns](https://drive.google.com/open?id=1D4qrHpUrIhioHyt2ebI3qsHQg5HWzTjb) to draw more and more complicated pictures.

We've created a small library that holds some geometrical primitives (straight line, curve,....) that can be used to draw larger, more complex drawings.

We want to have the kids figure out the right sequence and parameters for these primitives in order to produce shapes as simple as squares and circles up to more complex ones such as stars or flowers.

The extra challenge in this version of TaMatisse is that the marker never leaves the paper so you really need to figure out the optimal path to obtain a clean shape!

# Technical Specs

If you're intersted to build TaMatisse and try it out for yourself, here's what you need:

* A 3D printer (we'll post some printable STL's of the TaMatisse chassis and wheels at a later stage)
* Some electronics (we'll provide further details of what we used)
* Rubber bands
* Batteries
* Whiteboard markers (size is optimized for the lyreco brand)
* Arduino Primitives. You can use the PlatformIO-IDE (based on Atom) to modify, compile and upload the project to an Arduino. You will find the designs we used in the repository.

Happy painting! 


