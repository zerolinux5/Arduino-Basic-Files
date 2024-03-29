//Uses Celsius
const int RLED = 11;
const int GLED = 10;
const int BLED = 9;
const int TMP = 0;

//constants used for my personal room
const int LOWER = 21;
const int HIGHER = 28;

float val = 0;
int reading;

void setup()
{
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  Serial.begin(9600);
  //recommended from arduino tmp sensor tutorial
  analogReference(INTERNAL);
}

void loop()
{
  reading = analogRead(TMP);
  val = reading / 9.31;
  Serial.println(val);
  
  //3 cases for 3 different colors
  if(val < LOWER)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  } else if(val > HIGHER)
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  } else 
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }
}
    
    
