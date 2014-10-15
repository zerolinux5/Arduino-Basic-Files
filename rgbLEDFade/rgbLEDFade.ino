const int BLUELED = 9;
const int GREENLED = 10;
const int REDLED = 11;
const int BUTTON = 2;

boolean lastButton = LOW;
boolean currentButton = LOW;
int ledMode = 0;

void setup()
{
  pinMode(BLUELED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
  pinMode(REDLED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(BUTTON);
  if (last != current)
  {
    delay(5);
    current = digitalRead(BUTTON);
  }
}

void setMode(int mode)
{
  switch (mode){
    case 1:
      digitalWrite(REDLED, HIGH);
      digitalWrite(BLUELED, LOW);
      digitalWrite(GREENLED, LOW);
      Serial.println("RED");
      break;
    case 2:
      digitalWrite(REDLED, LOW);
      digitalWrite(BLUELED, LOW);
      digitalWrite(GREENLED, HIGH);
      Serial.println("GREEN");
      break;
    case 3:
      digitalWrite(REDLED, LOW);
      digitalWrite(BLUELED, HIGH);
      digitalWrite(GREENLED, LOW);
      Serial.println("BLUE");
      break;
    case 4:
      analogWrite(REDLED, 127);
      analogWrite(BLUELED, 127);
      analogWrite(GREENLED, 0);
      Serial.println("PURPLE");
      break;
    case 5:
      analogWrite(REDLED, 0);
      analogWrite(BLUELED, 127);
      analogWrite(GREENLED, 127);
      Serial.println("TEAL");
      break;
    case 6:
      analogWrite(REDLED, 127);
      analogWrite(BLUELED, 0);
      analogWrite(GREENLED, 127);
      Serial.println("ORANGE");
      break;
    case 7:
      analogWrite(REDLED, 85);
      analogWrite(BLUELED, 85);
      analogWrite(GREENLED, 85);
      Serial.println("WHITE");
      break;
    default:
      digitalWrite(REDLED, LOW);
      digitalWrite(BLUELED, LOW);
      digitalWrite(GREENLED, LOW);
      Serial.println("NONE");
      break;
  }
}

void loop()
{
  currentButton = debounce(lastButton);
  //debugging
  //Serial.println(currentButton);
  if (lastButton == LOW && currentButton == HIGH)
  {
    ledMode++;
  }
  lastButton = currentButton;
  if(ledMode == 8) ledMode = 0;
  setMode(ledMode);
}
