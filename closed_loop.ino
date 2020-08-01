
#include <stdio.h>
#include <math.h>
#include "functions.h"


#define MAX_RPM 3000
#define MAX_TEMP 100
#define AVG_MAX 30 //moving window width
#define PWM_MAX 230

//PID CONSTANTS BELOW

#define P_const 1
#define I_const 0.3
#define D_const 0.5



//PWM variables
int pwm_pinout = 9; //timer1 pinout                       
unsigned long pwmfreq = 1000; 
double PWM_output = 0;
double PWM_output_old = 0;
double PWM_output_diff = 0;
double pwm_real = 0;

//RPM variables
double rpm_actual = 0, rpm_wanted = 0;

//led freq measure variables - PIN 2
volatile int led_freq = 0;
volatile int led_mic_old = 0, led_mic_new = 0;
volatile int led_dt = 0;

//hall freq measure variables - PIN 3
volatile long hall_freq = 0;
volatile long hall_mic_old = 0, hall_mic_new = 0;
volatile long hall_dt = 0;

//temperature variables
double temp_actual = 0;
double temp_count = 0;
double temp_avg = 0;
double d_temp = 0;
double temp_old = 0;
double temp_new = 0;
int counter = AVG_MAX;
double avg_window[AVG_MAX]; //would not compile under C89, hopefully will on arduino platforms (newer standards)
double avg_sum = 0;
double average_temp = 0;

//PID variables

/////////////////////////////////
// double temp_wanted = 25 ; //will read values from another arduino eventually
////////////////////////////////

double k = 0;

double temp_now = 0;
double temp_prev = 0;
double temp_error = 0;
double prop = 0, integral = 0, deriv = 0;

double inter = 0;



void setup()
{
  Serial.begin(9600); 
 // Timer1_Initialize();

  attachInterrupt(digitalPinToInterrupt(2), isr_led, RISING);
  attachInterrupt(digitalPinToInterrupt(3), isr_hall, RISING);

  for(int i = 0; i < AVG_MAX; i++)
  
  { //fill the moving average window
    avg_window[i] = 0;
    Serial.write("Enter the desired temperature: ");
  }
  
}

void loop()
{
  int temp_wanted = 0 ;
  if (Serial.available())
{
 int temp_wanted=Serial.parseInt();
 Serial.print(temp_wanted);
   Serial.print(" ");
   Serial.print(" ");
   Serial.print(" ");
}
 

 
}

void isr_led(void) //D2 port
{
  led_mic_old = led_mic_new;
  led_mic_new = micros();
  led_dt = led_mic_new - led_mic_old;
  
}

void isr_hall(void)
{
  
  hall_mic_old = hall_mic_new;
  hall_mic_new = micros();
  hall_dt = hall_mic_new - hall_mic_old;
  
}







