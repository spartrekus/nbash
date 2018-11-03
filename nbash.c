
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

void nsystem( char *mycmd )
{
   printf( "<CMD: %s>\n", mycmd );
   system( mycmd );
   printf( " Defunc CMD: %s>\n", mycmd );
}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
char *strremovelf(char *str)
{  
      char ptr[strlen(str)+1];
      int i,j=0;
      for(i=0; str[i]!='\0'; i++)
      {
        if (str[i] != '\n' && str[i] != '\n') 
        ptr[j++]=str[i];
      } 
      ptr[j]='\0';
      size_t siz = sizeof ptr ; 
      char *r = malloc( sizeof ptr );
      return r ? memcpy(r, ptr, siz ) : NULL;
}



/////////////////////////////////
/////////////////////////////////
/////////////////////////////////
int fexist(char *a_option)
{
  char dir1[PATH_MAX]; 
  char *dir2;
  DIR *dip;
  strncpy( dir1 , "",  PATH_MAX  );
  strncpy( dir1 , a_option,  PATH_MAX  );

  struct stat st_buf; 
  int status; 
  int fileordir = 0 ; 

  status = stat ( dir1 , &st_buf);
  if (status != 0) {
    fileordir = 0;
  }

  // this is compatible to check if a file exists
  FILE *fp2check = fopen( dir1  ,"r");
  if( fp2check ) {
  // exists
  fileordir = 1; 
  fclose(fp2check);
  } 

  if (S_ISDIR (st_buf.st_mode)) {
    fileordir = 2; 
  }
return fileordir;
/////////////////////////////
}





////////////////////////////
////////////////////////////
////////////////////////////
////////////////////////////
////////////////////////////
///// some cat!! 
#include <fcntl.h>
#include <unistd.h>
static int cat_fd(int fd) 
{
  char buf[4096];
  ssize_t nread;

  while ((nread = read(fd, buf, sizeof buf)) > 0) 
  {
    ssize_t ntotalwritten = 0;
    while (ntotalwritten < nread) {
      ssize_t nwritten = write(STDOUT_FILENO, buf + ntotalwritten, nread - ntotalwritten);
      if (nwritten < 1)
        return -1;
      ntotalwritten += nwritten;
    }
  }
  return nread == 0 ? 0 : -1;
}
/////////////////
static int ncat_static(const char *fname) 
{
  int fd, success;
  if ((fd = open(fname, O_RDONLY)) == -1)
    return -1;

  success = cat_fd(fd);

  if (close(fd) != 0)
    return -1;

  return success;
}
////////////////////////////
////////////////////////////
////////////////////////////
////////////////////////////
////////////////////////////








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



void printdir( char *chartext )
{
   DIR *dirp; int chr ;  
   struct dirent *dp;
   dirp = opendir( "." );

   if ( strcmp( chartext, "" ) == 0 ) 
    while  ((dp = readdir( dirp )) != NULL ) 
    {
        if (  strcmp( dp->d_name, "." ) != 0 )
        if (  strcmp( dp->d_name, ".." ) != 0 )
        {
             for ( chr = 0 ;  chr <= strlen(dp->d_name) ; chr++) 
               printf( "%c" , dp->d_name[chr] );
             printf( "\n" );
        }
    }

   else if ( strcmp( chartext, "" ) != 0 ) 
    while  ((dp = readdir( dirp )) != NULL ) 
    {
        if (  strcmp( dp->d_name, "." ) != 0 )
        if (  strcmp( dp->d_name, ".." ) != 0 )
        {
           if ( strstr( dp->d_name , chartext ) != 0 ) 
           {
             for ( chr = 0 ;  chr <= strlen(dp->d_name) ; chr++) 
               printf( "%c" , dp->d_name[chr] );
             printf( "\n" );
           }
        }
    }

   closedir( dirp );
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
      //char *base = ptr; 
      //return (base);
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

      //size_t siz = sizeof ptr ; 
      //char *r = malloc( sizeof ptr );
      //return r ? memcpy(r, ptr, siz ) : NULL;
      char *base = ptr; return (base);
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
       strncat( cmdi , "\" " , PATH_MAX - strlen( cmdi ) -1 );
       printf( "-> Command start: %s ...\n" , cmdi ) ; 
       system( cmdi );
       printf( "-> Command end: %s.>\n" , cmdi ) ; 
}




//////////////////////////////////////////////////
void cmd_interpreter( char *mystring )
{
  char fetchline[PATH_MAX];
  char fetchlinetmp[PATH_MAX];
  char inputfield[PATH_MAX];
  char currentdir[PATH_MAX];
  char cwd[PATH_MAX];
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

              // vim 
              if ( fetchline[0] == 'v' )
              if ( fetchline[1] == 'i' )
              if ( fetchline[2] == 'm' )
              if ( fetchline[3] == ' ' )
              if ( foundcmd == 0 )
              {
                 runwith( " vim ", strcut( fetchline, 3+2, strlen( fetchline )) );
                 foundcmd = 1;
              }

              // eps 
              if ( fetchline[0] == 'e' )
              if ( fetchline[1] == 'p' )
              if ( fetchline[2] == 's' )
              if ( fetchline[3] == ' ' )
              if ( foundcmd == 0 )
              {
                 runwith( " epsedit ", strcut( fetchline, 3+2, strlen( fetchline )) );
                 foundcmd = 1;
              }

              // sys 
              if ( fetchline[0] == 's' )
              if ( fetchline[1] == 'y' )
              if ( fetchline[2] == 's' )
              if ( fetchline[3] == ' ' )
              if ( foundcmd == 0 )
              {
                 nsystem(   strcut( fetchline, 3+2, strlen( fetchline )) )  ;
                 foundcmd = 1;
              }


              // cat 
              if ( fetchline[0] == 'c' )
              if ( fetchline[1] == 'a' )
              if ( fetchline[2] == 't' )
              if ( fetchline[3] == ' ' )
              if ( foundcmd == 0 )
              {
                 ncat_static( strtrim( strcut( fetchline, 3+2, strlen( fetchline ))) );
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


              ////////////////////////////
              if ( fetchline[0] == 'U' )
              if ( fetchline[1] == 'S' )
              if ( fetchline[2] == 'E' )
              if ( fetchline[3] == 'R' )
              if ( foundcmd == 0 )
              {
                 printf( "%s\n", getenv( "USER") );
                 foundcmd = 1;
              }
              ////////////////////////////
              if ( fetchline[0] == 'T' )
              if ( fetchline[1] == 'E' )
              if ( fetchline[2] == 'R' )
              if ( fetchline[3] == 'M' )
              if ( foundcmd == 0 )
              {
                 printf( "%s\n", getenv( "TERM") );
                 foundcmd = 1;
              }


              // find dir, which allows to find a given text in filename 
              if ( fetchline[0] == 'f' )
              if ( fetchline[1] == 'i' )
              if ( fetchline[2] == 'n' )
              if ( fetchline[3] == 'd' )
              if ( fetchline[4] == ' ' )
              if ( foundcmd == 0 )
              {
                 strncpy( inputfield, strcut( fetchline, 4+2, strlen( fetchline )) , PATH_MAX );
                 printdir( inputfield );
                 foundcmd = 1;
              }

              // lsf dir, which allows to find a given text in filename 
              if ( fetchline[0] == 'l' )
              if ( fetchline[1] == 's' )
              if ( fetchline[2] == 'f' )
              if ( fetchline[3] == ' ' )
              if ( foundcmd == 0 )
              {
                 strncpy( inputfield, strcut( fetchline, 3+2, strlen( fetchline )) , PATH_MAX );
                 printdir( inputfield  );
                 foundcmd = 1;
              }


              // ls dir 
              if ( fetchline[0] == 'l' )
              if ( fetchline[1] == 's' )
              if ( fetchline[2] == ' ' )
              if ( foundcmd == 0 )
              {
                 strncpy( currentdir, getcwd( cwd, PATH_MAX ) , PATH_MAX );
                 chdir( strcut( fetchline, 2+2, strlen( fetchline )));
                 printdir( "" );
                 chdir( currentdir );
                 foundcmd = 1;
              }

              // ls 
              if ( fetchline[0] == 'l' )
              if ( fetchline[1] == 's' )
              if ( foundcmd == 0 )
              {
                 printdir( "" );
                 foundcmd = 1;
              }
              // pwd 
              if ( fetchline[0] == 'p' )
              if ( fetchline[1] == 'w' )
              if ( fetchline[2] == 'd' )
              if ( foundcmd == 0 )
              {
                 printf( "%s\n", getcwd( cwd, PATH_MAX ));
                 foundcmd = 1;
              }





}





int main( int argc, char *argv[])
{
    char cwd[PATH_MAX]; int i ; 

    ////////////////////////////////////////////////////////
    if ( argc >= 2)
    if ( strcmp(argv[1], "--args" ) == 0)
    {
          for( i = 1 ; i < argc ; i++) 
	     printf( "%d/%d: %s\n", i, argc-1 ,  argv[ i] );
          return 0;
    }

    
    ////////////////////////////////////////////////////////
    /// rescue and debugging function
    ////////////////////////////////////////////////////////
    if ( argc == 3)
      if ( strcmp( argv[1] , "--cat" ) ==  0 ) 
      if ( fexist( argv[2] )  == 1 )
      {
         ncat_static( argv[ 2 ] );
         return 0;
      }




    ////////////////////////////////////////////////////////
    if ( argc == 2)
      if ( strcmp( argv[1] , "" ) !=  0 )
       {
          chdir( argv[ 1 ] );
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
       printf( "\n");

       if      ( strcmp( string, "quit" ) == 0 )  gameover = 1;
       else if ( strcmp( string, "exit" ) == 0 ) gameover = 1;
       else if ( strcmp( string, "bye" )  == 0 )  gameover = 1;


    }
    printf( "Bye!\n" );
    return 0;
}




