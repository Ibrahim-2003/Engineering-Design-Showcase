#define DS_PIN 8
#define SHCP_PIN 9
#define STCP_PIN 10

int RED = 0;
int YELLOW = 1;
int GREEN = 2;

const int register_count = 5;

int HOURS[12][3] = {{12,24,37},
                        {0,13,25},
                        {1,14,26},
                        {2,15,27},
                        {3,16,28},
                        {4,5,17},
                        {6,18,29},
                        {7,19,30},
                        {8,23,31},
                        {9,20,32},
                        {10,21,33},
                        {11,22,34}};

float sample_data[12] = {
    10,
    10,
    3,
    2,
    1,
    20,
    20,
    35,
    35,
    50,
    55,
    55
};

boolean registers[8*register_count];

void setup() {
  Serial.begin(250000);
  pinMode(DS_PIN, OUTPUT);
  pinMode(SHCP_PIN, OUTPUT);
  pinMode(STCP_PIN, OUTPUT);
  for(int hour = 0; hour<8*register_count; hour++){
    registers[hour] = LOW;
  };
  writereg();
}

void writereg(void){
  digitalWrite(STCP_PIN, LOW);
  for (int i = 8*register_count; i>=0; i--){
    digitalWrite(SHCP_PIN, LOW);
    digitalWrite(DS_PIN, registers[i]);
    digitalWrite(SHCP_PIN, HIGH);
    };
    digitalWrite(STCP_PIN, HIGH);
  }


void loop() {
  for(int i = 0; i < 12; i++){
    registers[HOURS[i][trafficLevel(i)]] = HIGH;
    writereg();
  };
   

}


 float largest(float arr[], int n)
{
    int i;
    
    // Initialize maximum element
    int max = arr[0];
 
    // Traverse array elements from second and
    // compare every element with current max 
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
 
    return max;
}

//This function normalizes the traffic data for each hour and converts to analog output (0 to 255)
int trafficLevel(int hour){
  float current_visits = sample_data[hour];
  float largest_num = float(largest(sample_data, 12));
    float weight = current_visits/largest_num;
    weight = 255*weight;
    if(weight>255*2/3){
      return RED;
      }else if(weight<=255*2/3 && weight>=255*1/3){
        return YELLOW;
        }else{
          return GREEN;
          }
}
