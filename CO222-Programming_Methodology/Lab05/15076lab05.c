#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET		0
#define BRIGHT 		1

#define BLACK 		0
#define RED		1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

void textcolor(int attr, int fg, int bg);

void textcolor(int attr, int fg, int bg)
{	char command[13];

	/* Command is the control command to the terminal */

	/* textcolor(BRIGHT,BLACK,WHITE) will have characters printed in
	black in white background */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}
 

int donutShape=0; /*declare and initialize two global variables */
int checkerShape=0;
 

int checkErrors(int argc);
int checkErrors(int argc){

/* check whether number of arguments are enough or too much */

 if(argc<4){
  printf("Not enough arguments\n");
  return -1;}
 else if(argc>4){
  printf("Too many arguments\n");
  return -1;}
 else{
  return 1;}
}


void printChecker(int bg,int fg);
void printChecker(int bg,int fg){

/* make an array of size 8x8 */
 char arr[8][8];

 for(int i=0;i<8;i++){

   if(i%2==0){
      for(int t=0;t<8;t++){
        for(int j=0;j<8;j++){
           if(j%2==0){
              textcolor(BRIGHT,bg,fg);
              printf("        ");}
           else{
              textcolor(BRIGHT,fg,bg);
              printf("        ");}}
              textcolor(RESET,fg,bg);
        printf("\n");}}

   else{
       for(int s=0;s<8;s++){
         for (int k=0;k<8;k++){
            if(k%2==0){
              textcolor(BRIGHT,fg,bg);
              printf("        ");}
            else{
              textcolor(BRIGHT,bg,fg);
              printf("        ");}}
       textcolor(RESET,fg,bg);
       printf("\n");}}}

 textcolor(RESET, WHITE, BLACK);
}


void printDonut(int bg,int fg);
void printDonut(int bg,int fg){

  double d1,d2;
  scanf("%lf",&d1);/* get the diameter from user */
  d2=d1/2; /* calculate the inner diameter */
  double i,j;
      for( i=-d1/2;i<d1/2;i++){
        for(j=-d1/2;j<d1/2;j++){
           if((i*i+j*j<(d1/2)*(d1/2)) && (i*i+j*j>(d2/2)*(d2/2))){
             textcolor(BRIGHT,bg,fg);
             printf(" ");}
           else{
             textcolor(BRIGHT,fg,bg);
             printf(" ");}
        textcolor(RESET,fg,bg);}
      printf("\n");}

  textcolor(RESET, WHITE, BLACK);
}


int checkBgColor(char arg[]);
int checkBgColor(char arg[]){

  int a;

  int bg0=strcmp(arg,"black");/* compare the input  backgroundcolors with given colors */
  int bg1=strcmp(arg,"red");
  int bg2=strcmp(arg,"green");
  int bg3=strcmp(arg,"yellow");
  int bg4=strcmp(arg,"blue");
  int bg5=strcmp(arg,"magenta");
  int bg6=strcmp(arg,"cyan");
  int bg7=strcmp(arg,"white");


/* give the numbers for background colors */
  if(bg0==0){
    a=0;}
  else if(bg1==0){
    a=1;}
  else if(bg2==0){
    a=2;}
  else if(bg3==0){
    a=3;}
  else if(bg4==0){
   a=4;}
  else if(bg5==0){
   a=5;}
  else if(bg6==0){
   a=6;}
  else if(bg7==0){
   a=7;}
  else{
   a=8;}
return a;}


int checkFgColor(char arg[]);
int checkFgColor(char arg[]){

  int b;

  int fg0=strcmp(arg,"black");/* compare the input foregrount colors with given colors */
  int fg1=strcmp(arg,"red");
  int fg2=strcmp(arg,"green");
  int fg3=strcmp(arg,"yellow");
  int fg4=strcmp(arg,"blue");
  int fg5=strcmp(arg,"magenta");
  int fg6=strcmp(arg,"cyan");
  int fg7=strcmp(arg,"white");

/* give the numbers for foreground colors */
  if(fg0==0){
    b=0;}
  else if(fg1==0){
    b=1;}
  else if(fg2==0){
    b=2;}
  else if(fg3==0){
    b=3;}
  else if(fg4==0){
    b=4;}
  else if(fg5==0){
    b=5;}
  else if(fg6==0){
    b=6;}
  else if(fg7==0){
    b=7;}
  else{
    b=8;}

return b;}


int colorAvailability(int bg,int fg);
int colorAvailability(int bg,int fg){
  if(bg==8){
    printf("Background color is not available\n");
    return -1;}
  else if(fg==8){
    printf("Foreground color is not available\n");
    return -1;}
  else{
    return 1;} 
}


int checkFigure(char arg[]);
int checkFigure(char arg[]){
 /* check whether the input figure is "donut" or "checker" */
  int p=strcmp(arg,"donut");
  int q=strcmp(arg,"checker");

/* return values for each shapes */
  if(p==0){
    donutShape=1;}
  else if(q==0){
    checkerShape=1;}
  else{
    printf("Requested figure is not available\n");
    return -1;}
 
}


int main(int argc, char **argv){
 

  int rvalue1=checkErrors(argc);
   if(rvalue1==-1){
    return 0;}
  
  int rvalue2=checkFigure(argv[1]);
   if(rvalue2==-1){
    return 0;}
  
/* get the suitable values for background color and foreground color */  
  
  int bg_color=checkBgColor(argv[2]);
  int fg_color=checkFgColor(argv[3]);

  int rvalue3=colorAvailability(bg_color,fg_color); /*check the colors are matching with given colors */
    if(rvalue3==-1){
     return 0;}
    else if(donutShape==1){
     printDonut(bg_color,fg_color);} /* print the donut shape */
    else {
     printChecker(bg_color,fg_color);} /* print the checker shape */
	
	
return 0;}

   
