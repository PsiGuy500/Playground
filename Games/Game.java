package com.example.helloworld;
import java.util.*;

class Person {
    int xpos=0;
    int ypos=0;
    int money=0;

    int arr[]={10,20,30,40,50,60};

    public void getpos(){
        System.out.println("("+xpos+", "+ypos+")");
    }
    public int changex(int amt){
        xpos+=amt;
        return xpos;
    }
    public int changey(int amt){
        ypos+=amt;
        return xpos;
    }
    public int getmoney(){
        for(int i = 0;i<arr.length;i++){
            if(xpos==arr[i] && ypos==arr[i+1]){
                System.out.println("You found the treasure!");
                money+=100;
                System.out.println("Total account: "+money);
            }
        }
        return money;
    }
}

public class Game {
    public static void main(String[] args) {
        Person bob = new Person();
        bob.changex(10);
        bob.changey(20);

        bob.getmoney();
        bob.getpos();
    }
}
