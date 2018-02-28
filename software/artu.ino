#define BUTTON_FW 8
#define BUTTON_BW 9
#define MOTOR_B_DIR 10  //L9110_B_IA
#define MOTOR_B_PWM 11  //L9110_B_IB
#define GDN_PIN1 12
#define GDN_PIN2 7
#define PWM_FW 150
#define PWM_BW 75

void setup()
{
  pinMode(BUTTON_FW, INPUT_PULLUP);
  pinMode(BUTTON_BW, INPUT_PULLUP);
  pinMode(MOTOR_B_DIR, OUTPUT);
  pinMode(MOTOR_B_PWM, OUTPUT);
  pinMode(GDN_PIN1, OUTPUT);
  digitalWrite(GDN_PIN1, LOW);
  pinMode(GDN_PIN2, OUTPUT);
  digitalWrite(GDN_PIN2, LOW);
}

void loop()
{
  delay(5);
  int btn_fw = digitalRead(BUTTON_FW);
  delay(5);
  int btn_bw = digitalRead(BUTTON_BW);
  delay(5);
  
  if (btn_bw == LOW) {
    // move backward
    digitalWrite(MOTOR_B_DIR, HIGH);
    analogWrite(MOTOR_B_PWM, PWM_BW);
    digitalWrite(13, HIGH);
  } else if (btn_fw == LOW) {
    // move forward
    digitalWrite(MOTOR_B_DIR, LOW);
    analogWrite(MOTOR_B_PWM, PWM_FW);
    digitalWrite(13, HIGH);
  } else {
    // turn motor off
    digitalWrite(MOTOR_B_DIR, LOW);
    analogWrite(MOTOR_B_PWM, 0);
    digitalWrite(13, LOW);
  }
  delay(100);
}
