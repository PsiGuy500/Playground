/*
  Name: Cyrus Young
  Student Number: XXXXXXXX
  Date: Nov 29, 2021
  Email: cysyoung21@gmail.com
  
  Lab 8 Simon game template
  Do not modify this template (circuit)
  
  Design choices:
  
  To signal the start of a new game, all lights will
  flash simultaneously and stay on for one second. 
  Then they will turn off for a second. 
  Then the first color will be displayed.
  
  A button will stay on as long as it is pressed.
  
  Once you finish a round successfuly the program will delay 
  for half a second.
  
  
*/

//preprocessor directives
//symbolic constants

int const WIN = 8;
int const LOSE = 13;

int const RED = 12;
int const YELLOW = 11;
int const BLUE = 10;
int const GREEN = 9;
int const RedButton = 7;
int const YellowButton = 6;
int const BlueButton = 5;
int const GreenButton = 4;

int RedButtonState = 0;
int YellowButtonState = 0;
int BlueButtonState = 0;
int GreenButtonState = 0;

//ColorArr stores the colors flashed as numbers

int ColorArr[5] = {0};

int val;

//function prototypes

void setup()
{
  pinMode(WIN, OUTPUT);
  pinMode(LOSE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RedButton, INPUT);
  pinMode(YellowButton, INPUT);
  pinMode(BlueButton, INPUT);
  pinMode(GreenButton, INPUT);
  randomSeed(analogRead(0));
}


//displays a color generated randomly 

int display()
{
  int rand = random(9,13);
  digitalWrite(rand,HIGH);
  delay(1000);
  digitalWrite(rand,LOW);
  delay(500);
  
//returns the "color" stored as an integer
  
  return rand;
}


/*Function used for pressing buttons. Returns
  color of button pressed as an integer*/

int press()
{
  int g = 0;
  while(g == 0){
    
    //reads the state of each button
    
    RedButtonState = digitalRead(RedButton);
    YellowButtonState = digitalRead(YellowButton);
    BlueButtonState = digitalRead(BlueButton);
    GreenButtonState = digitalRead(GreenButton);
    
    /*for each of the while loops below: The button is turned 
      on as long as the button is pressed*/
    
    while(RedButtonState == HIGH){
      RedButtonState = digitalRead(RedButton);
      g = RED;
      digitalWrite(RED,HIGH);
    }
     
    while(YellowButtonState == HIGH){
      YellowButtonState = digitalRead(YellowButton);
      g = YELLOW;
      digitalWrite(YELLOW,HIGH);
    }
    
    while(BlueButtonState == HIGH){
      BlueButtonState = digitalRead(BlueButton);
      g = BLUE;
      digitalWrite(BLUE,HIGH);
    }
    
    while(GreenButtonState == HIGH){
      GreenButtonState = digitalRead(GreenButton);
      g = GREEN;
      digitalWrite(GREEN,HIGH);
    }
    
 /* makes sure to turn buttons off as soon 
       as button is no longer pressed */
    
    digitalWrite(RED,LOW);
    digitalWrite(YELLOW,LOW);
    digitalWrite(BLUE,LOW);
    digitalWrite(GREEN,LOW);
    
  }
  
 //returns the color of the button pressed as a number
  
  return g;
}

/*generates random array of numbers, with 
  each array element representing a different color*/

int getstarted()
{
  for(int j = 0; j<5;j++)
  {
    ColorArr[j] = random(9,13);
  }
}

//flashes top green light 3 times if user guesses all colors correctly

void win()
{ 
  for(int m = 0;m<3;m++){
    digitalWrite(WIN,HIGH);
    delay(1000);
    digitalWrite(WIN,LOW);
    delay(500);
  }
}

//flashes top red light 3 times if user makes a mistake

void lose()
{
  for(int m = 0;m<3;m++){
    digitalWrite(LOSE,HIGH);
    delay(1000);
    digitalWrite(LOSE,LOW);
    delay(500);
  }
}

void loop()
{
  
/*Turns on all lights for 1 second to signal
    the start of a new game*/
  
  getstarted();
  
  digitalWrite(RED,HIGH);
  digitalWrite(YELLOW,HIGH);
  digitalWrite(BLUE,HIGH);
  digitalWrite(GREEN,HIGH);
  
  delay(1000);
    
  digitalWrite(RED,LOW);
  digitalWrite(YELLOW,LOW);
  digitalWrite(BLUE,LOW);
  digitalWrite(GREEN,LOW);
  
  delay(1000); //give some "rest time"
  
  
//indicates the length of first sequence is only 1 color
  
  int length = 1;
  
//continue as long as sequence length < 5
  
  while(length <= 5){
    
    for(int i = 0;i<length;i++)
    {
      digitalWrite(ColorArr[i],HIGH);
      delay(1000);
      digitalWrite(ColorArr[i],LOW);
      delay(1000);
    }
    
    for(int n = 0; n < length; n++)
    {
      //val represents the color of the button pressed
      
      val = press();
     
 //if value does not equal flashed color, exit loop
      
      if(val != ColorArr[n])
      {
        lose();
        return;
      }
        
    }
    
    length++; 
    
    delay(500); //for "rest" time
    
  }
  
  win();  
  
  delay(20);  //to improve simulation performance
  
}







