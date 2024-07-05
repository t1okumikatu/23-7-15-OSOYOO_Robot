/*motor control*/
void  go_Back(int speed)  //Forward
{

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(ENA,speed);
}
 
void go_Advance(int speed)  //Forward
{

  digitalWrite(IN1, LOW);
  digitalWrite(IN2,HIGH);
  analogWrite(ENA,speed);
}
 
void turn(int angle)
{

  head_steer.write(angle);

}
 
void stop_Stop()    //Stop
{
  go_Back(300);
  delay(100);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2,LOW);
  analogWrite(ENA,0);
}
