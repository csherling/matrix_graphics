#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

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
  printf("\n identity matrix: matrix name: iden");
  print_matrix(iden);
  printf("matrix name: i");
  print_matrix(i);
  printf("matrix name: edges");
  print_matrix(edges);

  printf("========scalar multiplying 'edges' by 4.0========\n");
  scalar_mult(4.0, edges);

  printf("matrix name: edges");
  print_matrix(edges);

  printf("========matrix multiplying 'i' and 'edges'========\n");
  matrix_mult(i, edges);

  printf("matrix name: edges");
  print_matrix(edges);

  printf("========matrix multiplying identity matrix 'iden' and 'edges'========\n");
  printf("should produce the same answer\n");
  matrix_mult(iden, edges);

  printf("matrix name: edges");
  print_matrix(edges);

  printf("========FREEDOM TO THE MATRICES!!! (i, iden, edges)========\n");
  free_matrix( i );
  free_matrix( iden );
  free_matrix( edges );


  //============================actual test stuff===============================

  screen s;
  color color;
 
  
  color.red = MAX_COLOR;
  color.green = MAX_COLOR;
  color.blue = MAX_COLOR;

  clear_screen(s);  
  
  struct matrix *points;

  points = new_matrix(4,4);
  points->lastcol = 0;

  
  /* add_point(points,0,0,0); */
  /* add_point(points,100,100,0); */
  /* add_edge(points,0,100,0,100,0,0); */
  /* add_edge(points,123,100,0,100,100,0); */
  /* add_edge(points,400,200,0,200,400,0); */
  /* add_edge(points,300,300,0,300,350,0); */
  /* add_edge(points,400,400,0,350,300,0); */

  int x;
  double d;
  for(x = 0; x < 125; x++){
    /* c.red = x * 2; */
    /* c.green = (x*c.red+128) % 256; */
    /* c.blue = (x*c.green) % 256; */
    add_edge(points, 0,4*x,0, 500 - 4*x, 0,0);
    add_edge(points, 4*x,500,0, 0,4*x,0);    
    add_edge(points, 500,500-4*x,0, 4*x,500,0);
    add_edge(points, 500-4*x,0,0, 500, 500-4*x,0);
  }
  


  add_edge(points, 250, 250, 0, 250, 500, 0);
  add_edge(points, 250, 250, 0, 375, 500, 0);
  add_edge(points, 250, 250, 0, 500, 500, 0);
  add_edge(points, 250, 250, 0, 500, 375, 0);
  add_edge(points, 250, 250, 0, 500, 250, 0);
  add_edge(points, 250, 250, 0, 500, 125, 0);
  add_edge(points, 250, 250, 0, 500, 0, 0);
  add_edge(points, 250, 250, 0, 375, 0, 0);
  add_edge(points, 250, 250, 0, 250, 0, 0);
  add_edge(points, 250, 250, 0, 125, 0, 0);
  add_edge(points, 250, 250, 0, 0, 0, 0);
  add_edge(points, 250, 250, 0, 0, 125, 0);
  add_edge(points, 250, 250, 0, 0, 250, 0);
  add_edge(points, 250, 250, 0, 0, 375, 0);
  add_edge(points, 250, 250, 0, 0, 500, 0);
  add_edge(points, 250, 250, 0, 125, 500, 0);


  draw_lines(points, s, color);
  
  display(s);
  save_extension(s, "lines.png");


  free_matrix( points );
  printf("========FREEDOM TO THE MATRICES!!! (points)========\n");  
}  
