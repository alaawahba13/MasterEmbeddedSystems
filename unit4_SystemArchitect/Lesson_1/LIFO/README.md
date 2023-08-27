# Stack Implementation using C 

### *Statically allocated stack*

```C
int main() {
	      
        u8 head[5];   
        u32 pop_value,stack_size=0,top_value;
        Stack my_stack = { 5, &head[0] }; 
        LIFO_status ret = NOK;
        ret = LIFO_init(&my_stack);
        
    	if (ret == OK) {
    	// push 5 values
    		for (u32 i = 0; i < 5; i++) {
    			LIFO_push(&my_stack, i);
    			printf("Value pushed %d\n", i);
    		}
    	//pop two values
    		for (u32 i = 0; i < 2; i++) {
    			LIFO_pop(&my_stack,&pop_value );
    		}
    	 //print the top
    		   LIFO_top(&my_stack, &top_value);
    	//print the size
    		   stack_size = LIFO_getSize(&my_stack);;
    		   printf("The stack size is: %d\n",stack_size);
      // print values
    		print_stack(&my_stack);
    	}
    	return 0;
     }

```
### Output


<img width="449" alt="Screenshot 2023-08-28 014240" src="https://github.com/alaawahba13/MasterEmbeddedSystems/assets/101985923/f9c56a5f-5a4b-4917-a25b-8ceda9c06f52">

### *Dynamically allocated stack*

   ###### It's the same code with this modification
    
```C
u8 *head = (u8 *)malloc(5);
```
