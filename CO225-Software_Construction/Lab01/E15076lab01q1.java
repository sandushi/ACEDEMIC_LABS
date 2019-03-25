/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package e15076lab01q1;

import java.util.Scanner;

/**
 *
 * @author User
 */
public class E15076lab01q1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
         Scanner keyboard = new Scanner(System.in);  //For get input from the keyboard
        System.out.print("Enter a number: ");       //Get inputs from the user
        int number=keyboard.nextInt();             //Put the input value to the variable
        int werid = 0;                            //Initialize  variables
        int special = 0;
        int big = 0;
        
        if(number%15 == 0){                      //Check whether the number is exactly devide by 5
            special = 1;}                        
        if(number>999){                         //Check whether the number is more than 999
            big = 1;}
        if(number%5==0 && number%6==0 && number%18!=0){  //Check whether the number is exactly devided by 5 and 6 and not divided by 18
            werid = 1;}
        
        if((special==1) && (big==0) && (werid==0)){                 //Check the output 
            System.out.println(number+" is special,but not scary.");}  //Display the output
        if((special==1) && (big==1) && (werid==0)){
            System.out.println(number+" is special,big and scary but not werid.");}
        if((special==1) && (big==0) && (werid==1)){
            System.out.println(number+" is special,werid and scary but not big.");}
        if((special==1) && (big==1) && (werid==1)){
            System.out.println(number+" is special,werid,big ,scary.");}
        if((special==0) && (big==0) && (werid==0)){
            System.out.println(number+" is  not scary.");}
        if((special==0) && (big==1) && (werid==0)){
            System.out.println(number+" is big and scary but not werid ");}
        if((special==0) && (big==0) && (werid==1)){
            System.out.println(number+" is werid and scary but not big");}
        if((special==0) && (big==1) && (werid==1)){
            System.out.println(number+" is werid,big and scary ");}
                    
        
    
    }
    
}
