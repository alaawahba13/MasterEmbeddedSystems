/* author : alaa wahba */ 

.section .vectors

.word 0x020001000   // stack Pointer 
.word _reset    
.word  _vector_handler		/* NMI 		 */
.word  _vector_handler 		/* HARD FAULT 	 */ 
.word  _vector_handler		/* MM FAULT		 */ 
.word  _vector_handler		/* Bus fault 	 */
.word  _vector_handler		/* Usage fault 	 */ 
.word  _vector_handler		/* RESERVED 	 */
.word  _vector_handler 		/* RESERVED	 	 */
.word  _vector_handler		/* RESERVED 	 */
.word  _vector_handler		/* RESERVED		 */
.word  _vector_handler		/* SV call 		 */
.word  _vector_handler		/* Debug reserved  */ 
.word  _vector_handler		/* RESERVED 	 */
.word  _vector_handler		/* PendSV 		 */ 
.word  _vector_handler		/* SysTick 		 */
.word  _vector_handler		/* IRQ0 		 */
.word  _vector_handler		/* IRQ1  		 */
.word  _vector_handler		/* IRQ2 		 */

.section .text
_reset : 
	bl main
	b .


.thumb_func
_vector_handler:
	b _reset 
