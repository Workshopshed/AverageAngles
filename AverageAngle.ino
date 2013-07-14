#include<math.h>

void setup() { 
 //Initialize serial and wait for port to open:
  Serial.begin(9600); 
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
  // prints title with ending line break 
  Serial.println("Angle Test"); 
  
  double angleSet1[] = { 350, 10 };
  double angleSet2[] = { 90, 180, 270, 360};
  double angleSet3[] = { 10, 20, 30};
 
  Serial.print ("Mean Angle for 1st set ");
  Serial.print( meanAngle (angleSet1, 2));
  Serial.print(" degrees\nMean Angle for 2nd set ");
  Serial.print( meanAngle (angleSet2, 4));
  Serial.print(" degrees\nMean Angle for 3rd set ");
  Serial.print( meanAngle (angleSet3, 3));  
  Serial.print(" degrees\n");
} 
 
double meanAngle (double *angles, int size)
{
  double y_part = 0, x_part = 0;
  int i;
 
  for (i = 0; i < size; i++)
    {
      x_part += cos (angles[i] * M_PI / 180);
      y_part += sin (angles[i] * M_PI / 180);
    }
 
  return atan2 (y_part / size, x_part / size) * 180 / M_PI;
}
 
void loop() { 
  //Do nothing
}
