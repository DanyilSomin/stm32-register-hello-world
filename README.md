# stm32-register-hello-world
My version of blinky hello world for stm32f103 using CMSIS only.

This project used st-link v2 programator

Install drivers for st-link
https://freeelectron.ro/installing-st-link-v2-to-flash-stm32-targets-on-linux/	
	<br>note:
	<br>sudo cp etc/udev/rules.d/49-stlinkv* /etc/udev/rules.d/
	<br>This command in my case does not work due differ udev/rules.d/49-stlinkv* location.
	<br>Fixed by finding udev folder path and copied 49-stlinkv* files from it instead of ect/....

sudo apt-get install gcc-arm-none-eabi

Go to repo folder

make all
make install
