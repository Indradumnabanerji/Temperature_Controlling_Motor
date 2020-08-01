int ledblue=7;
const int analogOutPin = 9; // Analog output pin to PWM control
int outputValue = 0;        // value output to the PWM (analog out)
String readString;
  
  
int tx=1;
int rx=0;
char inSerial[15];


void setup(){
Serial.begin(9600);
pinMode(ledblue, OUTPUT);

pinMode(tx, OUTPUT);
pinMode(rx, INPUT);
allpinslow();
}

void loop(){
int i=0;
int m=0;
delay(500);
if (Serial.available() > 0) {
while (Serial.available() > 0) {
inSerial[i]=Serial.read();
i++;
}
inSerial[i]='\0';
Check_Protocol(inSerial);
}}
void allpinslow()
{
digitalWrite(ledblue, HIGH);
digitalWrite(ledblue, LOW);
}
void Check_Protocol(char inStr[]){
int i=0;
int m=0;
Serial.println(inStr);
if(!strcmp(inStr,"7off")){ //Led Off
allpinslow();
digitalWrite(ledblue, LOW);
Serial.println("Blue Off");
for(m=0;m<11;m++){
inStr[m]=0;}
i=0;}
if(!strcmp(inStr,"7on")){ //Led on
allpinslow();
digitalWrite(ledblue, HIGH);
Serial.println("Blue on");
for(m=0;m<11;m++){
inStr[m]=0;}
i=0;}
else{
for(m=0;m<11;m++)
{
inStr[m]=0;
}
i=0;

while (Serial.available()) { //Check the availability of the serial port
    delay(3);                  // through a loop
    char c = Serial.read();  // The characters that enter the port are read
    readString += c;         //each of the characters are accumulated in readString
    outputValue = map(readString.toInt(), 0, 1023, 0, 255); 
  }
 if (readString.length() >0) { //verified that the variable contains information
    Serial.println(readString.toInt());  //send what has the variable
    analogWrite(analogOutPin,outputValue ); 
    readString=""; // Variable is cleared 
  } 
         
   // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);                     
} }
