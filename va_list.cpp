#include <stdio.h>  
#include <stdlib.h>  
#include <stdarg.h>  

void printf_diy(char *fmt,...) {  
	va_list arg;  
	char c;  

	va_start(arg, fmt);  

	do {  
		c = *fmt;  
		if(c != '%'){  
			putchar(c); //输出  
		}  
		else {  
			fmt++;  
			switch(*fmt) {  
			case 'd':  
				printf("%d", *((int*)arg));  
				break;  
			case 'x':  
				printf("%#x", *((int*)arg));  
				break;  
			case 'f':  
				printf("%f", *((double*)arg));  
                printf("%f", *((float *)arg)); 
			default:  
				break;  
			}  
 
		}  

		++fmt;  

	} while (*fmt != '\0');  

	va_end(arg);  
	return;  
}  

int main(int argc, char **argv) {  
	int i = 1234;  
	int j = 5678;  
	float f = 13.9;  

	float *pp=&f;
	char *tt;
	tt=(char *)pp;

	printf_diy("i = %d\n", i);  
	printf_diy("j = %d\n", j);  
	printf_diy("f = %f\n", f);  
	printf("%f",*(float  *)tt);
    printf("%f",*(double *)tt);
	return 0;  
}  
