# How To TaMatisse

## Hardware and software requirements
- A laptop with a [USB-A port](doc/images/usb-a-port.jpg)
- [USB-A to USB mini B](doc/images/usb-a-to-usb-mini-b.jpg) cable
- A copy of this repository
- [VSCode](https://code.visualstudio.com/) or [Atom](https://atom.io/) text editors, with the [PlatformIO plugin](https://platformio.org/platformio-ide) installed
- A functioning TaMatisse bot.

## Step by step guide to building and uploading the software

__1. Start your editor (VSCode/Atom) and launch the PlatformIO pluign__
![1](/doc/images/platformio-1.png)

__2. Open your project in PlatformIO__ 
![2](/doc/images/platformio-2.png)
![3](/doc/images/platformio-3.png)

__3. Install the "Atmel AVR" platform__ 
![4](/doc/images/platformio-4.png)

__4. Build the project__
![5](/doc/images/platformio-5.png)
![6](/doc/images/platformio-6.png)

__5. Upload to the Arduino (Atmel AVR)__
![7](/doc/images/platformio-7.png)

__5.1. If uploading doesn't work, change the upload target port__

PlatformIO automatically tries to detect which USB serial port to upload to. Sometimes this doesn't work, therefore we have to specify the port in the platformio.ini file.

Find the correct port:
![8](/doc/images/platformio-8.png)

Set new port in platformio.ini:
![9](/doc/images/platformio-9.png)

__5.2. Successful upload:__
![10](/doc/images/platformio-10.png)
