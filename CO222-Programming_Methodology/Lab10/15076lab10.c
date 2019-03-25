#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 250

/*Create a node*/
typedef struct node{
	int length;
	struct node * next;
	char  str[SIZE];
}

node_t;


/*Input words to the list*/

node_t * createLinkedlist(FILE * inputfile){

	node_t * list = NULL;
	list = malloc(sizeof(node_t)); //Allocate memory for the list

        node_t * head = list;
         
	
	char  string[SIZE]; //Declare variables
	int word_length;
	
	int length;

	while((!feof(inputfile))){               //open the file and read until the file is null
		fscanf(inputfile,"%s",string);   //Get word by word from the file
		
		length=strlen(string);

		if(string[length-1]=='.'){        //Remive the dot charactor from the
			string[length-1]='\0';}
		
		word_length=strlen(string);      //Get the length of the word
		strcpy(list->str,string);        //copy the word to list
		list->length=word_length;        //Store the word length in the list
		list->next=malloc(sizeof(node_t));//memory allocation for the next in the list
		list=list->next;
	}
	
return head;
}

/*Find the maximum legth of the words*/

int maximum_length(node_t * list){


	node_t * current=list;
	
	int max_length;             //Declare a variable
	max_length=current->length; //Initialize the variable

	while(current->next!=NULL){
		if(max_length < current->next->length){    //Check the maximum length 
			max_length=current->next->length;}
		current=current->next;}
return max_length;}


/*Print the sorted list*/

void print_sortedList(node_t * list, int max_length){

	node_t * current=list;
	int length=max_length;  //Initialize the variable

	while(length>0){

		while(current->next!=NULL){
			if(current->length==length){
				printf("%s\n",current->str);
				
			break;}			//If the first word is printed from one length,the loop stops
		current=current->next;         //Update the current list
		}

	length=length-1;		
	current=list;
	}	
}



int main(int argc, int **argv){

	FILE *inputfile;	 //Declare the file
	node_t * wordList=NULL;  //Create a list type of node
	int max_length;          //Declare a variable
	wordList=malloc(sizeof(node_t));//Allocate a memory for the list

	if(argc!=2){
		printf("Usage:./prog <inputfile>");
		return 0;}


	inputfile=fopen(argv[1],"r");   //Open the  file

	wordList=createLinkedlist(inputfile); //Create the word list

	max_length=maximum_length(wordList);  //Find the maximum length of the words
	
	print_sortedList(wordList,max_length); //Print the sorted list


return 0;}

  

