.global reset
reset:
   ldr sp,= 0x00011000
   bl main
stop: b stop