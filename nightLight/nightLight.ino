const int RLED = 11;
const int GLED = 10;
const int BLED = 9;
const int LIGHT = 0;
const int MIN_LIGHT=200;
const int MAX_LIGHT=900;


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
  val = analogRead(TMP);
  Serial.println(val);
}
    
    
