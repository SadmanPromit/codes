int i4 = 7;
int i3 = 6;
int i2 = 5;
int i1 = 4;
int o4 = 13;
int o3 = 12;
int o2 = 11;
int o1 = 10;
int val4 = 0;
int val3 = 0;
int val2 = 0; 
int val1 = 0;

void setup() {
  pinMode(o4, OUTPUT);
  pinMode(o3, OUTPUT);
  pinMode(o2, OUTPUT);
  pinMode(o1, OUTPUT);
  pinMode(i4, INPUT);
  pinMode(i3, INPUT);
  pinMode(i2, INPUT);
  pinMode(i1, INPUT);
}

void loop() {
  val4 = ((!digitalRead(i2) && digitalRead(i3) && !digitalRead(i4)) || (digitalRead(i2) && !digitalRead(i3) && !digitalRead(i4)) || (!digitalRead(i1) && digitalRead(i2) && digitalRead(i4)) || (digitalRead(i1) && digitalRead(i3) && digitalRead(i4)));
  digitalWrite(o4, val4);
  val3 = ((!digitalRead(i1) && !digitalRead(i2) && !digitalRead(i3) && !digitalRead(i4)) || (digitalRead(i3) && digitalRead(i4)) || (digitalRead(i2) && digitalRead(i4)) || (!digitalRead(i1) && digitalRead(i2) && digitalRead(i3)));
  digitalWrite(o3, val3);
  val2 = ((digitalRead(i2) && !digitalRead(i4)) || (digitalRead(i3) && !digitalRead(i4)) || (digitalRead(i1) && digitalRead(i2)) || (!digitalRead(i1) && !digitalRead(i2) && digitalRead(i4)) || (!digitalRead(i2) && !digitalRead(i3) && digitalRead(i4)));
  digitalWrite(o2, val2);
  val1 = ((!digitalRead(i2) && !digitalRead(i3)) || (!digitalRead(i1) && !digitalRead(i3) && !digitalRead(i4)) || (digitalRead(i1) && !digitalRead(i2) && !digitalRead(i4)) || (digitalRead(i1) && !digitalRead(i3) && digitalRead(i4)));
  digitalWrite(o1, val1);
}