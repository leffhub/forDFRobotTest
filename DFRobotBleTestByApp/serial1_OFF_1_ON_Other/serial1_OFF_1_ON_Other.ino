String val = "";
boolean mark = LOW;

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);  //initial the Serial1
  pinMode(13, OUTPUT);
}

void loop() {
  while (Serial1.available()) {
    val += char(Serial1.read());
    delay(2);   // Can't be deleted for it needs time to read Serial1
    mark = HIGH;
  }

  if (val.length() == 1) {    //Send command without CR/ LF/ NL
    if (val == "1") {
      digitalWrite(13, HIGH); //turn on the LED on D13
      Serial1.println("LED is ON!");
      Serial.println("LED is ON!");

    }
    else if (val == "0") {
      digitalWrite(13, LOW);  //Trun off
      Serial1.println("LED is OFF!");

      Serial.println("LED is OFF!");
    }
  }

  if (mark == HIGH) {
    Serial1.print("Length: ");      Serial1.println(val.length());
    Serial1.print("Val: ");        Serial1.println(val); delay(50);
    Serial1.println("Done");       Serial1.println();
    Serial1.flush();
    Serial.print("Length: ");      Serial1.println(val.length());
    Serial.print("Val: ");        Serial1.println(val); delay(50);
    Serial.println("Done");       Serial1.println();
    Serial.flush();

    val = "";
    mark = LOW;
  }
}
