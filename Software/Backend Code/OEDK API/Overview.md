 
 # Backend
 There are 3 functions:
 ### 1) "get_visitors_between"
 This function takes inputs from the GET request of an interval between one year and another to return the number of visitors.

 SAMPLE GET REQUEST: http://localhost:4800/get_visitors_between/?time_start=2015&time_end=2021
 RESPONSE: 25519

 ### 2) "year"
 This function takes input from the GET request as a year and returns the number of visitors that year

 SAMPLE GET REQUEST: http://localhost:4800/year?year=2021
 RESPONSE: 107

 ### 3) "sensor_triggered"
 This function records a user entering the OEDK once the ultrasonic sensor is triggered. No inputs for this function.
 SAMPLE POST REQUEST: http://localhost:4800/sensor_triggered/