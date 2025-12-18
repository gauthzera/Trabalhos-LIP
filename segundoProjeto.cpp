
void setup()
{
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  pinMode(5, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  if (analogRead(A1) > 81) {
    if (analogRead(A0) == 1018) {
      analogWrite(5, 1);
      analogWrite(11, 102);
      analogWrite(9, 255);
      analogWrite(10, 153);
    } else {
      analogWrite(5, 180);
      analogWrite(11, 51);
      analogWrite(9, 51);
      analogWrite(10, 255);
    }
  } else {
    analogWrite(5, 255);
    analogWrite(11, 255);
    analogWrite(9, 255);
    analogWrite(10, 255);
  }
  delay(10); 
}