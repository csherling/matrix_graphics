#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *i;
  struct matrix *iden;
  struct matrix *edges;

  i = new_matrix(4,4);
  iden = new_matrix(4,4);
  edges = new_matrix(4, 4);

  int r, c;
  
  for(r=0;r<4;r++){
    for(c=0;c<4;c++){
      i->m[r][c] = 2.0;
      edges->m[r][c] = r * c;
    }
  }
  ident(iden);
  print_matrix(iden);
  print_matrix(i);
  print_matrix(edges);

  scalar_mult(4.0, edges);

  print_matrix(edges);

  matrix_mult(i, edges);

  print_matrix(edges);

  matrix_mult(iden, edges);
    
  print_matrix(edges);
  
  free_matrix( edges );
}  
