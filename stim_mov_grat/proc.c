#include <stdio.h>
#include <string.h>

#define INTO_SRC "->1;\n"
#define FILE_END "}\n"

int main(int argc, char *argv[]){

  int i,j,k;
  FILE *infile, *outfile;

  char line[256];
  char filename[25];

  if ( argc < 2 ) {
    printf("Usage: ./x /path/to/file \n");
    return -1;
  }

  for ( i = 1 ; i < argc ; i++ ) {

    infile = NULL;
    infile = fopen(argv[i], "r");
    if ( !infile ) {
      printf("Couldn't read file %s \n", argv[i]);
      continue;
    }
    
    memset(filename, '\0', 25);
    for ( j = 0, k = 0 ; j < strlen(argv[i]) ; j++ , k++ ) {
      
      if ( argv[i][j] == '.' ) {
	filename[k++] = '_';
	filename[k++] = 'p';
	filename[k++] = 'p';
      }
      
      filename[k] = argv[i][j];
    }

    outfile = NULL;
    outfile = fopen(filename, "w");
    if ( !outfile ) {
      printf("couldnt open file to write... \n");
      return -2;
    }

    j=0;
    memset(line, '\0', 256);
    while ( fscanf(infile, "%c", &line[j]) != EOF ) {
      if ( line[j++] != '\n' )
	continue;

      if ( strcmp(&line[j-strlen(INTO_SRC) > 0 ? j-strlen(INTO_SRC) : 0], 
		  INTO_SRC) ) {

       	if ( !strcmp(line, FILE_END) ) 
	  fprintf(outfile, "1 [style=filled,fillcolor=red]\n");
	
	fprintf(outfile, "%s", line);	
      }
	
      memset(line, '\0', 256);
      j = 0;
    }

  }

  fclose(infile);
  fclose(outfile);

  return 0;
}

    
