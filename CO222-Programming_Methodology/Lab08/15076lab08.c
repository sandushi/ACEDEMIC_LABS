#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100


int main(int argc,char **argv){
	
	FILE *inputfile;                          //Declare a file 
			  
	char string[SIZE];		          //Declare the string array
	int count,counter=0;                     //Initialize variables
        char str;
        int maximum_length=0;
        int word_length;
 	
        /*Check if whether number of arguments are correct*/
	if(argc!=3){
	 fprintf(stderr,"Usage: ./prog <width> <inputfile>\n");
         return 0;}
	

	int width=atoi(argv[1]);               //Convert the string input of width to int type
         

        /*Open the input file*/

        inputfile=fopen(argv[2],"r");


	/*Find the maiximum length of a word in the text file*/

        while(!feof(inputfile)){
           fscanf(inputfile,"%s",string);
           word_length=strlen(string);
           
	   if(word_length>maximum_length){
               maximum_length=word_length;}
           }

	/*The file is read one time.To read the file again*/

        rewind (inputfile);
            

	/*Check the width*/

	if(width<=maximum_length && width>=0){
	 fprintf(stderr,"Word length must be less than screen width\n");
	 fclose(inputfile);
	return 0;}
        
        /*Print the wrap text*/   

	else{
		while(!feof(inputfile)){      //Check the file is end

			if(fscanf(inputfile,"%s",string)==NULL){;
                            break;}
                          
			/*Get the count of strings in one word*/
                            count=strlen(string);
                                       
			/*To get the length of a line*/
			    
			     counter=counter+count;
			     
			/*Print the line in given width*/
                              
                            if(counter<=width){
                                        printf("%s",string);
                               		count=0;}
                                	
                            else{
                                	printf("\n");
                                 	printf("%s",string);
                                        counter=strlen(string);}
                                 	
                                 		

		            /*Initialize the string[0] to null charactor*/
			    string[0]='\0';
				
			   /*Get the next charactor */
			    str=fgetc(inputfile);

                            if(str==' '){
                                 printf(" ");
                                 counter=counter+1;}
                            else if(str=='\n'){
                                 printf("\n");
                                 counter=0;}
}


	
		                 
/*Close the input file*/
                       
fclose(inputfile);	

return 0;}}

