// -----------------
// Read temperature
// -----------------
Servo myservo1;
Servo myservo2;
// Create a variable that will store the temperature value
double temperature = 0.0;
double temperature2 = 0.0;

//int val ;

//int ledControl(String command);
void setup()
{
    Serial.begin(9600);
 
    while(!Serial.available()) SPARK_WLAN_Loop();
 
  Serial.println("hello");
  
  // Register a Spark variable here
  Spark.variable("temperature", &temperature, DOUBLE);

  // Connect the temperature sensor to A7 and configure it
  // to be an input
  pinMode(A7, INPUT);
  
 myservo1.attach(D0);  // attaches the servo on analog pin D0 to the servo object 
 myservo2.attach(D1);

//Spark.function("ledstate", ledControl);
}

void loop()
{
  int reading = 0;
  double voltage = 0.0;

  // Keep reading the sensor value so when we make an API
  // call to read its value, we have the latest one
  reading = analogRead(A7);

  // The returned value from the Core is going to be in the range from 0 to 4095
  // Calculate the voltage from the sensor reading
  voltage = (reading * 3.3) / 4095;

  // Calculate the temperature and update our static variable
  temperature = (voltage - 0.5) * 100;
  Serial.println(temperature);
  
  if(temperature2 < temperature + 2 && temperature2 > temperature - 2)
  {  myservo1.write(92); 
    myservo2.write(92);
  }
  
     else if ( temperature > 20) {   

    myservo1.write(600);
    myservo2.write(600);

//return 1;
  }
  

//return 1;
      
      else
      {
          myservo1.write(-508);
          myservo2.write(-508);
      }
      temperature2 = temperature;
      
delay(5000);
}

void end()
{
    Serial.end();
}
//GET /v1/devices/{Marty McSleeves}/temperature
//int ledControl(String command)


 //if and else will set on off functionality
 



    //else{
    //val = command.toInt(); //converts command to integer to be used for positional arrangement
    //val = map (val, 0, 99, 0, 179);
    //myservo1.write(val);
    //myservo2.write(val);
    



