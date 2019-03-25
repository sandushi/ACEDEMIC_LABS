/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package e15076lab01q2;

import java.util.Scanner;

/**
 *
 * @author User
 */
public class E15076lab01q2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
         Scanner keyboard = new Scanner(System.in); //For get input from the keyboard
        System.out.print("Enter the color: ");      //Getting input from the user
        int red = keyboard.nextInt();          // Put the input to the vaariables
        int green = keyboard.nextInt();
        int blue = keyboard.nextInt();
       
        
        int new_red = 255-red;       //Update the values of colors for get the complement
        int new_green = 255-green;
        int new_blue = 255-blue;
        
        /*Check whether the differences of all three modify color numbers with their given numbers are between 32*/
        if(((new_red-red<=32 && new_red-red>0 )|| (red-new_red<=32 && red-new_red>0)) && ((new_blue-blue<=32 && new_blue-blue>0) ||(blue-new_blue<=32 && blue-new_blue>0)) &&  ((new_green-green<=32 && new_green-green>0  ) ||(green-new_green<=32 && green- new_green>0))) {
             if(new_red-red<=32 && new_red-red>0) {      //Check whether the difference is less od equal to 32 of color red
            new_red = red + 128;}                   // Update the value of color
        else  if(red-new_red<=32 && red-new_red>0){
            
                new_red=red-128;}
             if(new_green-green<=32 && new_green-green>0  ){     //Check whether the difference is less od equal to 32 of color green
            new_green = green+ 128;}                           //Update the value of color
  else if(green-new_green<=32 && green- new_green>0){
                new_green=green-128;}
             if(new_blue-blue<=32 && new_blue-blue>0){             //Check whether the difference is less od equal to 32 of color blue
            new_blue = blue + 128;}                              //Update the value of the color
            else if(blue-new_blue<=32 && blue-new_blue>0){     
                new_blue=blue-128;}
            
        }
        System.out.println("The complement: "+ new_red+" "+new_green+" "+new_blue);  //Print the complement of the colors
    }
    
}

   
    

