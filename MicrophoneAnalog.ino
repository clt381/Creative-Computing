
int A0Reading;    //to store the sound input (should return between 0-1023

//storing the digital output pins for three red LEDs
int red1 = 3;
int red2 = 4;
int red3 = 5;

//amount of time that LEDs should light up for in milliseconds
int delayTime = 400;

//amount of time between responses
int timeBetweenResponses = 1000;
int timer;
int nextResponseTime;

//bools for responses given
bool response1Given;
bool response2Given;
bool response3Given;
bool response4Given;

//responses to display
String response1 = "*grumbles*";
String response2 = "Ugh, leave me alone...";
String response3 = "Stooop... just five more minutes...";
String response4 = "Okay! Fine! I'm up!";


void setup() {
  Serial.begin(9600);
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(red3, OUTPUT);

}

void loop() {
  timer = millis();
  A0Reading = analogRead(A0);   //returns reading of pin A0 to A0reading variable

  //setting all pins to low reading until microphone tests work
  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(red3, LOW);

  //clearing throat and snapping fingers raises microphone sensor to above 300
  //snapping successively raises sensor input to almost 600

  //lighting up LEDs according to increasing sound levels; LEDs light up independent of each other
  if (A0Reading > 300 && response1Given == false)
  {
    Serial.println(response1);
    response1Given = true;
    nextResponseTime = timer + timeBetweenResponses;
  }

  if (A0Reading > 350 && response1Given == true && response2Given == false && timer > nextResponseTime)
  {
    Serial.println(response2);
    response2Given = true;
    nextResponseTime = timer + timeBetweenResponses;
  }

  if (A0Reading > 400 && response2Given == true && response3Given == false && timer > nextResponseTime)
  {
    Serial.println(response3);
    response3Given = true;
    nextResponseTime = timer + timeBetweenResponses;
  }

  if (A0Reading > 500 && response3Given == true && response4Given == false && timer > nextResponseTime)
  {
    Serial.println(response4);
    response4Given = true;
    nextResponseTime = timer + timeBetweenResponses;
  }

}
