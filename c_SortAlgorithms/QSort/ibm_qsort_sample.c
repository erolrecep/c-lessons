/* CELEBQ01                                      

   This example sorts the arguments (argv) in ascending sequence, based on      
   the ASCII value of each character and string, and using the comparison       
   function compare() supplied in the example.                                  

 */                                                                             
#include <stdio.h>                                                              
#include <stdlib.h>                                                             
#include <string.h>                                                             
                                                                                
               /* Declaration of compare() as a function */                     
#ifdef __cplusplus                                                              
extern "C" int compare(const void *, const void *);                             
#else                                                                           
int compare(const void *, const void *);  /* macro is automatically */          
#endif                                    /* defined by the C++/MVS compiler  */
                                                                                
                                                                                
int main (int argc, char *argv[ ])                                              
{                                                                               
   int i;                                                                       
   argv++;                                                                      
   argc--;                                                                      
   qsort((char *)argv, argc, sizeof(char *), compare);                          
   for (i = 0; i < argc; ++i)                                                   
      printf("%s\n", argv[i]);                                                  
   return 0;                                                                    
}                                                                               
                                                                                
int compare (const void *arg1, const void *arg2)                                
{                                                                               
               /* Compare all of both strings */                                
   return(strcmp(*(char **)arg1, *(char **)arg2));                              
}                                                                               
