/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package e15076ball;

import static java.lang.Math.cos;
import static java.lang.Math.sin;

/**
 *
 * @author User
 */
public class E15076Ball {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Ball b1=new Ball(0.0,1.0,10.0,45.0);  //Create the object for ball 1
        b1.updateTime(5.0);                   //Update the time by 5
        Ball b2=new Ball(0.0,1.0,20.0,45.0);  //Create the object for ball 2
        b2.updateTime(5.0);                   //Update the time by 5
       
        
        boolean r1 = b2.willCollide(b1);       //Check whether the balls b1 and b2 are collide
        
        if(r1==true)
            System.out.println("B1 and B2 will collide");
        else
            System.out.println("B1 and B2 won't collide");
        
        Ball b3=new Ball(-10.0,5.0,3.0,30.0);   //Create the object for ball 3
        b3.updateTime(20.0);                 //Update the time by 20
        
        boolean r2=b3.willCollide(b2);          //Check wheher balls b2 and b3 are collide
        
            if(r2==true)
                    System.out.println("B2 and B3 will collide");
            else
                    System.out.println("B2 and B3 won't collide");
                
       
    }
}
     
class Ball{
       double x;       //present x position
       double y;       //present y position
       double speed;   //speed of the ball
       double angleOfSpeedWithX;   //angk=le of the speed
       static double globalTime=0;  //system clock time
       double time;       //Time amount that time updatet at once
       double new_X;      //new position of x
        double new_Y;//new position of y
    
    Ball(double x,double y,double speed,double angleOfSpeedWithX){
        this.x=x;                                   //get the variables to global the variables
        this.y=y;
        this.speed=speed;
        this.angleOfSpeedWithX=angleOfSpeedWithX;
        
    }
    
    void updateTime(double time){
        this.time=time;
        globalTime=globalTime+time;  //update the time of the system
        
        
    }
    
    boolean willCollide(Ball b){
       
       new_X=(this.speed*cos((3.14*this.angleOfSpeedWithX)/180)*(this.time)) + this.x; //find the new positions of the balls
       new_Y=(this.speed*sin((3.14*this.angleOfSpeedWithX)/180)*(this.time)) + this.y;
      

       if((b.speed*cos((3.14*b.angleOfSpeedWithX)/180)*(globalTime)+b.x)==new_X  && (b.speed*sin((3.14*b.angleOfSpeedWithX)/180)*(globalTime)+b.y)==new_Y){
         return true;
     }
     else{
        return false;}
    }
     }