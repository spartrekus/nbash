
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h> 
#include <time.h>


char* scan_line(char* buffer, int buffer_size) 
{
   char* p = buffer;
   int count = 0;
   do {
       char c;
       scanf("%c", &c); // scan a single character
       // break on end of line, string terminating NUL, or end of file
       if (c == '\r' || c == '\n' || c == 0 || c == EOF) {
           *p = 0;
           break;
       }
       *p++ = c; // add the valid character into the buffer
   } while (count < buffer_size - 1);  // don't overrun the buffer
   // ensure the string is null terminated
   buffer[buffer_size - 1] = 0;
   return buffer;
}




char *strcut( char *str , int myposstart, int myposend )
{  
      char ptr[strlen(str)+1];
      int i,j=0;
      for(i=0; str[i]!='\0'; i++)
      {
        if ( ( str[i] != '\0' ) && ( str[i] != '\0') )
         if ( ( i >=  myposstart-1 ) && (  i <= myposend-1 ) )
           ptr[j++]=str[i];
      } 
      ptr[j]='\0';
      size_t siz = sizeof ptr ; 
      char *r = malloc( sizeof ptr );
      return r ? memcpy(r, ptr, siz ) : NULL;
}




char *strtrim(char *str)
{  
      // right side to to finish
      char ptr[strlen(str)+1];
      int strposmax = strlen( str );
      int lastposchar = strposmax;
      int i,j=0;
      int foundspace = 1;

      /// find last char
      foundspace = 1;
      for( i= strposmax-1 ; i >= 0 ; i--)
      {
         //printf( "|%d-%d-%c| ", i , lastposchar , str[i] );
	 // find where to space
         if ( foundspace == 1 ) 
         if ( str[i] == ' ' ) 
   	    lastposchar = i-1;

         if ( str[i] != ' ' ) 
           foundspace = 0;
      } 

      // add the content
      foundspace = 1;
      for(i=0; i <= lastposchar ; i++)
      {
        if ( foundspace == 1 ) 
         if ( ( str[i] != ' ' )  && ( str[i] != 9 ) ) //added! with 9 for a TAB!!
          foundspace = 0;

        if ( foundspace == 0 ) 
           ptr[j++]=str[i];
      } 
      ptr[j]='\0';

      size_t siz = sizeof ptr ; 
      char *r = malloc( sizeof ptr );
      return r ? memcpy(r, ptr, siz ) : NULL;
}






void runwith( char *thecmd , char *thefile )
{
       char cmdi[PATH_MAX];
       printf( "<CMD: %s>\n" , thecmd ) ; 
       printf( "<FILE: %s>\n" , thefile ) ; 
       strncpy( cmdi , "  " , PATH_MAX );
       strncat( cmdi , thecmd , PATH_MAX - strlen( cmdi ) -1 );
       strncat( cmdi , " \"" , PATH_MAX - strlen( cmdi ) -1 );
       strncat( cmdi , thefile , PATH_MAX - strlen( cmdi ) -1 );
       strncat( cmdi , "\"" , PATH_MAX - strlen( cmdi ) -1 );
       system( cmdi );
}


void cmd_interpreter( char *mystring )
{
  char fetchline[PATH_MAX];
  char fetchlinetmp[PATH_MAX];
  char inputfield[PATH_MAX];
  int linecounter = 1; int fetchi = 0; 
  strncpy( fetchlinetmp, mystring, PATH_MAX );

  int foundcmd = 0;
  for( fetchi = 0 ; ( fetchi <= strlen( fetchlinetmp ) ); fetchi++ )
     if ( fetchlinetmp[ fetchi ] != '\n' )
      fetchline[fetchi]=fetchlinetmp[fetchi];

              // cd 
              if ( fetchline[0] == 'c' )
              if ( fetchline[1] == 'd' )
              if ( fetchline[2] == ' ' )
              if ( foundcmd == 0 )
              {
                 chdir( strtrim( strcut( fetchline, 2+2, strlen( fetchline ))) );
                 foundcmd = 1;
              }

              // cat 
              if ( fetchline[0] == 'c' )
              if ( fetchline[1] == 'a' )
              if ( fetchline[2] == 't' )
              if ( fetchline[3] == ' ' )
              if ( foundcmd == 0 )
              {
                 runwith( " catfile  " , strtrim( strcut( fetchline, 3+2, strlen( fetchline ))) );
                 foundcmd = 1;
              }


              // bash
              if ( fetchline[0] == 'b' )
              if ( fetchline[1] == 'a' )
              if ( fetchline[2] == 's' )
              if ( fetchline[3] == 'h' )
              if ( fetchline[4] == ' ' )
              if ( foundcmd == 0 )
              {
                 runwith( " bash  " , strtrim( strcut( fetchline, 4+2, strlen( fetchline ))) );
                 foundcmd = 1;
              }

              // bash (none)
              if ( fetchline[0] == 'b' )
              if ( fetchline[1] == 'a' )
              if ( fetchline[2] == 's' )
              if ( fetchline[3] == 'h' )
              if ( foundcmd == 0 )
              {
                 system( " bash  " );
                 foundcmd = 1;
              }

              // nfind 
              if ( fetchline[0] == 'n' )
              if ( fetchline[1] == 'f' )
              if ( fetchline[2] == 'i' )
              if ( fetchline[3] == 'n' )
              if ( fetchline[4] == 'd' )
              if ( fetchline[5] == ' ' )
              if ( foundcmd == 0 )
              {
                 runwith( " nfind  " , strtrim( strcut( fetchline, 5+2, strlen( fetchline ))) );
                 foundcmd = 1;
              }


              // lst 
              if ( fetchline[0] == 'l' )
              if ( fetchline[1] == 's' )
              if ( fetchline[2] == 't' )
              if ( foundcmd == 0 )
              {
                 system( " lst  " );
                 foundcmd = 1;
              }

              // vim 
              if ( fetchline[0] == 'v' )
              if ( fetchline[1] == 'i' )
              if ( fetchline[2] == 'm' )
              if ( fetchline[3] == ' ' )
              if ( foundcmd == 0 )
              {
                 runwith( " vim  " , strtrim( strcut( fetchline, 3+2, strlen( fetchline ))) );
                 foundcmd = 1;
              }



              // tc 
              if ( fetchline[0] == 't' )
              if ( fetchline[1] == 'c' )
              if ( foundcmd == 0 )
              {
                 system( " tc  " );
                 foundcmd = 1;
              }


              // echo 
              if ( fetchline[0] == 'e' )
              if ( fetchline[1] == 'c' )
              if ( fetchline[2] == 'h' )
              if ( fetchline[3] == 'o' )
              if ( fetchline[4] == ' ' )
              if ( foundcmd == 0 )
              {
                 strncpy( inputfield, strtrim( strcut( fetchline, 4+2, strlen( fetchline ))) , PATH_MAX );
 	         printf( "%s\n", inputfield );
                 foundcmd = 1;
              }


              // ls 
              if ( fetchline[0] == 'l' )
              if ( fetchline[1] == 's' )
              if ( foundcmd == 0 )
              {
                 system( " nls " );
                 foundcmd = 1;
              }

              // dir 
              if ( fetchline[0] == 'd' )
              if ( fetchline[1] == 'i' )
              if ( fetchline[2] == 'r' )
              if ( foundcmd == 0 )
              {
                 system( " nls " );
                 foundcmd = 1;
              }

}


int main( int argc, char *argv[])
{
    char cwd[PATH_MAX]; int i ; 

    ////////////////////////////////////////////////////////
    if ( argc >= 2)
    if ( strcmp(argv[1], "--arg" ) == 0)
    {
          for( i = 1 ; i < argc ; i++) 
	     printf( "%d/%d: %s\n", i, argc-1 ,  argv[ i] );
          return 0;
    }
    
    FILE *fp; 
    char string[PATH_MAX];
    int gameover = 0;
    printf( "Welcome to nbash! \n");
    while( gameover == 0 )
    {
       strncpy( string, "" , PATH_MAX );
       //printf("Enter a string: ");
       printf( "[%s]$ ", getcwd( cwd, PATH_MAX ) );
       scan_line( string , PATH_MAX);
       //printf("got: \"%s\"\n\n", string );
       //fp = fopen( "soleil.txt" , "ab+"); 
       // fputs( string ,  fp );
       // fputs( "\n", fp );
       //fclose( fp );
       cmd_interpreter( string ); 

       if      ( strcmp( string, "quit" ) == 0 )  gameover = 1;
       else if ( strcmp( string, "exit" ) == 0 ) gameover = 1;
       else if ( strcmp( string, "bye" )  == 0 )  gameover = 1;


    }
    printf( "Bye!\n" );
    return 0;
}




