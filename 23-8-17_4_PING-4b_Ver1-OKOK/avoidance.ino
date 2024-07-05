void auto_avoidance(){

  ++numcycles;
  if(numcycles>=LPT){ //Watch if something is around every LPT loops while moving forward 
     stop_Stop();
    String obstacle_sign=watchsurrounding(); // 5 digits of obstacle_sign binary value means the 5 direction obstacle status
      Serial.print("begin str=");
        Serial.println(obstacle_sign);
                    if( obstacle_sign=="00000"){
     Serial.println("FORWARD");
     turn(FRONT);
     go_Advance(SPEED);//前進
 
      delay(forwardtime);
      go_Back(STOP_SPEED);
      delay(stoptime);
      stop_Stop();
    }
 
    else if( obstacle_sign=="01000" || obstacle_sign=="11000" || obstacle_sign=="10000"  ){
     Serial.println("hand right");
           turn(SHARP_RIGHT);//右
     go_Advance(FAST_SPEED);
      delay(turntime);
      stop_Stop();
      turn(FRONT);
    } 
    
    else if( obstacle_sign=="00010" ||obstacle_sign=="00011" ||obstacle_sign=="00001"  ){
    Serial.println("hand left");
          turn(SHARP_LEFT);//左
     go_Advance(FAST_SPEED);
      delay(turntime);
      stop_Stop();
      turn(FRONT);
    }
 
    else if( obstacle_sign=="00111" ||   obstacle_sign=="01111" ||  obstacle_sign=="10111" || obstacle_sign=="11111"  || obstacle_sign=="00110" || obstacle_sign=="01010"  || obstacle_sign=="00101" ){
    Serial.println("hand back right");
     turn(RIGHT);//バック右
     
          stop_Stop();
          turn(FRONT);
     } 
         else if(obstacle_sign=="00100"  || obstacle_sign=="10100"  || obstacle_sign=="01100" || obstacle_sign=="11100" || obstacle_sign=="11011"  ||    obstacle_sign=="11101"  ||  obstacle_sign=="11110"  || obstacle_sign=="01110"  ){
    Serial.println("hand back left");
      turn(LEFT);//バック左
     go_Back(FAST_SPEED);
       delay(backtime);
          stop_Stop();
          turn(FRONT);
     }    
  
      else Serial.println("no handle");
    numcycles=0; //Restart count of cycles
    } else {
             turn(FRONT);//前進
     go_Advance(SPEED);
        delay(backtime);
          stop_Stop();
         
  }
  
  //else  Serial.println(numcycles);
  
  distance = watch(); // use the watch() function to see if anything is ahead (when the robot is just moving forward and not looking around it will test the distance in front)
  if (distance<distancelimit){ // The robot will just stop if it is completely sure there's an obstacle ahead (must test 25 times) (needed to ignore ultrasonic sensor's false signals)
 Serial.println("final go back");
       turn(SHARP_RIGHT);
     go_Back(FAST_SPEED);
  delay(backtime*3/2);
  turn(FRONT);
      ++thereis;}
  if (distance>distancelimit){
      thereis=0;} //Count is restarted
  if (thereis > 25){
  Serial.println("final stop");
    stop_Stop(); // Since something is ahead, stop moving.
    thereis=0;
  }
}
 
