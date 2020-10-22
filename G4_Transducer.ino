#define sensor A0
#define sensor1 A1

int SIZE = 20;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  float pressure_sensor_arr[SIZE];
  float pressure_sensor1_arr[SIZE];
  
  for (int i =0; i<SIZE; i++){
    float sensorVal = analogRead(sensor);
    float sensorVal1 = analogRead(sensor1);
    //Serial.print("Sensor Value: ");
    //Serial.print(sensorVal);
    
    float voltage = (sensorVal*5.0)/1024.0;
    float voltage1 = (sensorVal1*5.0)/1024.0;
    //    Serial.print("Volts: ");
    //    Serial.print(voltage);
     
    float pressure_pascal = (3.0*((float)voltage-0.475))*1000000.0;
    float pressure_pascal1 = (3.0*((float)voltage1-0.475))*1000000.0;//calibrate here
    //float pressure_pascal = (voltage / 16.6675) * 1000000.0;
    float pressure_bar = pressure_pascal/10e5;
    float pressure_bar1 = pressure_pascal1/10e5;
    float pressure_psi = pressure_bar*14.5038;
    float pressure_psi1 = pressure_bar1*14.5038;
  
    pressure_sensor_arr[i] = pressure_psi;
    pressure_sensor1_arr[i] = pressure_psi1;
  }

  float s = 0.0;
  float s1 = 0.0;

  for(int i = 0; i<SIZE; i++){
    s = s + pressure_sensor_arr[i];
    s1 = s1 + pressure_sensor1_arr[i];
  }

  float pressure_s_ave = s/SIZE;
  float pressure_s1_ave = s1/SIZE;

  Serial.print(pressure_s_ave);
  Serial.print("\t");
  Serial.println(pressure_s1_ave);

  delay(100);

}
