firmware-compile:
	arduino-cli compile --fqbn m5stack:esp32:m5stack_atom  firmware 

firmware-upload:
	arduino-cli upload -p /dev/cu.usbserial-8D560E3D92 --fqbn m5stack:esp32:m5stack_atom  firmware 

firmware: firmware-compile firmware-upload