MEMORY
{
 	FLASH(RX) : ORIGIN = 0X8000000    , LENGTH = 128k
	SRAM(RWX)  : ORIGIN = 0X20000000 , LENGTH =	20k

}

SECTIONS
{
	
	.text : 
	{
		*(.vectors*) *(.text*) *(.rodata)
	}> FLASH
	.data :
	{  
		*(.data*)

	}> FLASH
	.bss  :
	{    
		*(.bss*)
	}> SRAM

}