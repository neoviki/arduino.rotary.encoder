/* DC Motor Rotary Encoder for arduino
 * 
 * 
 * Author: Viki (a) Vignesh Natarajan [ https://vikiworks.io ]
 */


/* A DC Motor's number of rotation and driection of rotation 
 * are computed using reading from rotary encoder signal pin. 
 * The encoder I am using has 2 signal pins. Such encodres with 2 signal pins are called as 
 * Quadrature Encoder. The signal pins are marked as  "Signal Pin or CH.A/CH.B or C1/C2" 
 */
#define CHANNEL_A 4 //Signal Pin 1
#define CHANNEL_B 5 //Signal Pin 2

int counter = 0;
int a_current = 0; // Current  reading of channel a
int a_previous = 0; // Previous reading of channel a
int b_current = 0; // Current  reading of channel b

void setup() {
  Serial.begin(9600);
  pinMode (CHANNEL_A, INPUT);
  pinMode (CHANNEL_B, INPUT);
  a_current = digitalRead(CHANNEL_A);
}

void loop() {
    a_previous = a_current;
    a_current = digitalRead(CHANNEL_A);

    /* If previous reading and current reading is not same. 
     * This implies pulse has occured ( motor spin has occured )
     */
    if(a_current != a_previous){
        /*Channel B reading*/
        int b_current = digitalRead(CHANNEL_B);

        /* According to the datasheet, 
         * If current value of channel a and channel b are same, 
         * motor is spinning anticlockwise. otherwise motor is spinning
         * clockwise.
         */
        if(a_current == b_current){ //Anti-Clockwise
            counter -= 1;
        }else{                      //Clockwise
            counter += 1;
        }
    }
    
    Serial.print("Shaft Position = ");
    Serial.println(counter);
}
