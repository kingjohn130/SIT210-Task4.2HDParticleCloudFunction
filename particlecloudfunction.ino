
int blue = D2;

int green = D3; // Instead of writing D0 over and over again, we'll write led1
// You'll need to wire an LED to this one to see it blink.

int red = D5; // Instead of writing D7 over and over again, we'll write led2
// This one is the little blue LED on your board. On the Photon it is next to D7, and on the Core it is next to the USB jack.

bool rON = false;
bool gON = false;
bool bON = false;
// Having declared these variables, let's move on to the setup function.
// The setup function is a standard part of any microcontroller program.
// It runs only once when the device boots up or is reset.

void setup() {

  // We are going to tell our device that D0 and D7 (which we named led1 and led2 respectively) are going to be output
  // (That means that we will be sending voltage to them, rather than monitoring voltage that comes from them)

  // It's important you do this here, inside the setup() function rather than outside it or in the loop function.

  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  Particle.function("setLED", setLED);

}

// Next we have the loop function, the other essential part of a microcontroller program.
// This routine gets repeated over and over, as quickly as possible and as many times as possible, after the setup function is called.
// Note: Code that blocks for too long (like more than 5 seconds), can make weird things happen (like dropping the network connection).  The built-in delay function shown below safely interleaves required background activity, so arbitrarily long delays can safely be done if you need them.

void loop() {
}


int setLED(String colour) {
    if(colour == "red")
    {
        if(rON == false)
        {
        digitalWrite(red, HIGH);
        rON = true;
        return 1;
        }
        
        digitalWrite(red, LOW);
        rON = false;
        return 0;
    }
    if(colour == "green")
    {
        
        if(gON == false)
        {
        
        gON = true;
        digitalWrite(green, HIGH);
        return 1;

        }
        
        digitalWrite(green, LOW);
        gON = false;
        return 0;
        
        
    }
    if(colour == "blue")
    {
        if(bON == false)
        {
        
        bON = true;
        digitalWrite(blue, HIGH);
        return 1;

        }
        
        digitalWrite(blue, LOW);
        bON = false;
        return 0;
        
    }
   
    return -1;

}