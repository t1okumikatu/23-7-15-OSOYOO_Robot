String watchsurrounding(){
/*  obstacle_status is a binary integer, its last 5 digits stands for if there is any obstacles in 5 directions,
 *   for example B101000 last 5 digits is 01000, which stands for Left front has obstacle, B100111 means front, right front and right ha
 */
 
int obstacle_status =B100000;//binaryのB
  centerscanval = watch();
  if(centerscanval<distancelimit){
    stop_Stop();
    
    obstacle_status  =obstacle_status | B100;//"00100"
    }
  head.write(SENSOR_LEFT);//左斜め
  delay(100);
  ldiagonalscanval = watch();
  if(ldiagonalscanval<distancelimit){
    stop_Stop();
    
     obstacle_status  =obstacle_status | B1000;//"01000"
    }
  head.write(SENSOR_FAR_LEFT); //左Didn't use 180 degrees because my servo is not able to take this angle
  delay(100);
  leftscanval = watch();
  if(leftscanval<sidedistancelimit){
    stop_Stop();
    
     obstacle_status  =obstacle_status | B10000;//B100000 || B10000  =  "10000"
    }

  head.write(SENSOR_FRONT); //use 90 degrees if you are moving your servo through the whole 180 degrees
  delay(100);
  centerscanval = watch();
  if(centerscanval<distancelimit){
    stop_Stop();
    　　　　　　　　　　　//        00000  | B100   00100　
    obstacle_status  =obstacle_status | B100;//"00100" 論理和
    }
  head.write(SENSOR_RIGHT);//右斜め
  delay(100);
  rdiagonalscanval = watch();
  if(rdiagonalscanval<distancelimit){
    stop_Stop();
    
    obstacle_status  =obstacle_status | B10;//"00010"
    }
  head.write(SENSOR_FAR_RIGHT);//右
  delay(100);
  rightscanval = watch();
  if(rightscanval<sidedistancelimit){
    stop_Stop();
  
    obstacle_status  =obstacle_status | 1;//"00001"
    }
  head.write(SENSOR_FRONT); //Finish looking around (look forward again)
  delay(100);
   String obstacle_str= String(obstacle_status,BIN);
  obstacle_str= obstacle_str.substring(1,6);//0 1 2 3 4 5 6 
                                            //  1 2 3 4 5   取得
  return obstacle_str; //return 5-character string standing for 5 direction obstacle status
}
