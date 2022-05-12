                                                                           
/**                                                                        
 * main - function that execute our shell                                  
 */                                                                        
#include <stdio.h>                                                         
#include <stdlib.h>                                                        
#include <unistd.h>                                                        
#include <signal.h>                                                        
#include <string.h>                                                        
#include <sys/wait.h>                                                      
char c = '\0';                                                             
                                                                           
                                                                           
                                                                           
int main(int argc, char *argv[], char *var[])                              
{                                                                          
        char c;                                                            
        char *val = (char *)malloc(sizeof(char) * 100);                    
        printf("IB_shell  ");                                              
        while(c != EOF) {                                                  
                c = getchar();                                             
                switch(c) {                                                
                        case '\n':  if(val[0] == '\0') {                   
                                           printf("IB_shell  ");           
                                   } else {                                
                                           if (fork() == 0)                
                                           {                               
                                                   int i;                  
                                                   i=execve(val,argv,var); 
                                        exit(1);                           
                                        if (i < 0)                         
                                                printf("Not found");       
                                           }else                           
                                                   wait(NULL);             
                                           };                              
                                    printf("IB_shell ");                   
                                   break;                                  
                        default: strncat(val, &c, 1);                      
                                 break;                                    
                }                                                          
        }                                                                  
        printf("\n");                                                      
        return 0;                                                          
} 