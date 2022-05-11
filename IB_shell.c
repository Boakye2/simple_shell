                                                                           
/**                                                                        
 * main - function that execute our shell                                  
 */                                                                        
#include <stdio.h>                                                         
#include <stdlib.h>                                                        
#include <unistd.h>                                                        
#include <signal.h>                                                        
#include <string.h>                                                        
char c = '\0';                                                             
                                                                           
                                                                           
                                                                           
int main()                                                                 
{                                                                          
        char c;                                                            
        char *val = (char *)malloc(sizeof(char) * 100);                    
        printf("IB_shell  ");                                              
        while(c != EOF) {                                                  
                c = getchar();                                             
                switch(c) {                                                
                        case '\n':  if(val[0] == '\0') {                   
                                           printf("IB_shell  ");           
                                   } else {;};                             
                                   break;                                  
                        default: strncat(val, &c, 1);                      
                                 break;                                    
                }                                                          
        }                                                                  
        printf("\n");                                                      
        return 0;                                                          
}    