
unsigned int level = 0; // 音量等級
unsigned int step = 0;  // 目前腳本步驟

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // D13
  pinMode(3, OUTPUT);           // D3
  pinMode(5, OUTPUT);           // D5
  pinMode(7, OUTPUT);           // D7
  Serial.begin(9600);           //開始輸出訊息到監控視窗
}

void loop()
{

  step = (step + 1) % 100;
  // Serial.println(step);

  int sensorValue = analogRead(A0); // 讀取A0的值

  if (sensorValue > 35 && level == 0)
  {
    step = 0;
    level = 1;
    digitalWrite(LED_BUILTIN, HIGH); // 燈亮
    Serial.println(sensorValue);     // 在監控視窗顯示讀取的值

    switch (random(1, 4))
    {
    case 1:
      digitalWrite(3, HIGH);
      break;
    case 2:
      digitalWrite(5, HIGH);
      break;
    case 3:
      digitalWrite(7, HIGH);
      break;
    }
  }
  if (step > 10)
  {
    level = 0;
    digitalWrite(LED_BUILTIN, LOW); // 燈滅
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
  }
  delay(10);
}
