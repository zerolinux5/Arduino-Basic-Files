const int RLED = 11;
const int GLED = 10;
const int BLED = 9;
const int LIGHT = 0;
const int STAGE_1=100;
const int STAGE_2=300;
const int STAGE_3=1000;


int val = 0;

void setup()
{
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(LIGHT);
  Serial.println(val);
  if(val <= STAGE_1)
  {
    analogWrite(RLED, 255);
    analogWrite(GLED, 255);
    analogWrite(BLED, 255);
  }else if( val <= STAGE_2)
  {
    analogWrite(RLED, 127);
    analogWrite(GLED, 127);
    analogWrite(BLED, 127);
  } else 
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }  
}
    
    
