const express = require('express');
const path = require('path');
const mysql = require("mysql");
var bodyParser = require('body-parser');
const { time } = require('console');

const connection = mysql.createConnection({
    host: "localhost",
    user: "root",
    //port: "3306",
    // password: "mytOUrnEysql2003$",
    password: "password",
    database: "oedk",
    timezone: 'utc'
});

connection.connect(function(error){
    if (error) throw error
    else console.log(`Connected to database successfully. Open port ${port}`);
});

const app = express();
const port = 80;
app.use(bodyParser.urlencoded({ extended: false }));
app.set('view engine', 'ejs');

app.use(express.static(path.join(__dirname, '')));

makeQuery = function(query,vals){
    return new Promise(function(resolve,reject){
        if(vals){
            connection.query(
                query,
                vals,
                function(err,rows){
                    if(rows === undefined){
                        console.log(new Error(`Error, the query was not successful - ${err}`));
                        reject(0);
                    }else{
                        resolve(rows);
                    }
                }
            )
        }else{
            connection.query(
                query,
                function(err,rows){
                    if(rows === undefined){
                        console.log(new Error(`Error, the query was not successful - ${err}`));
                        reject(0);
                    }else{
                        resolve(rows);
                    }
                }
            )
        }
        
    })
}

// This function gets the number of visitors between two years
app.get('/get_visitors_between/', async function(req, res){

    time_start = req.query.time_start;
    time_end = req.query.time_end;
    query = `SELECT * FROM daily_visitors WHERE YEAR(date) BETWEEN ${time_start} AND ${time_end}`;
    visitors = await makeQuery(query, "");

    amount = 0;
    for (point of visitors){
        amount = amount + point.visitor_count;
    }
    Amount = {
        "visitors": amount
    };
    res.json(Amount);
})

// This function tells the Arduino how many years to cycle through
app.get('/year_count/', async function(req, res){

    const todaysDate = new Date();
    const currentYear = todaysDate.getFullYear();
    amount = currentYear - 2015;
    Amount = {
        "year_count": amount
    };
    res.json(Amount);
})

// This function gets the number of visitors in a single year
app.get('/year/', async function(req, res){

    year = req.query.year;
    query = `SELECT * FROM daily_visitors WHERE YEAR(date) = '${year}'`;
    visitors = await makeQuery(query, "");

    amount = 0;
    for (point of visitors){
        amount = amount + point.visitor_count;
    }
    Amount = {
        "visitors": amount
    };
    res.json(Amount);
})

app.get('/time/',async function(req,res){
    
    const todaysDate = new Date();
    const currentYear = todaysDate.getHours;
    let timer = "AM";
    if(currentYear >= 11){
        timer = "PM";
    };
    Time = {
        "time":  timer
    };
    res.json(Time);

});

app.get('/hourly/', async function(req, res){
    let hours = [];
    for(let i = 1; i < 25; i++){
        query = `SELECT * FROM daily_visitors WHERE HOUR(date) = '${i}'`;
        visitors = await makeQuery(query, "");

        amount = 0;
        for (point of visitors){
            amount = amount + point.visitor_count;
        }
        hours[i-1] = amount;
    }
    Amount = {
        "12am": hours[0],
        "1am": hours[1],
        "2am": hours[2],
        "3am":  hours[3],
        "4am":  hours[4],
        "5am":  hours[5],
        "6am":  hours[6],
        "7am":  hours[7],
        "8am":  hours[8],
        "9am":  hours[9],
        "10am":  hours[10],
        "11am": hours[11],
        "12pm": hours[12],
        "1pm":  hours[13],
        "2pm":  hours[14],
        "3pm":  hours[15],
        "4pm":  hours[16],
        "5pm":  hours[17],
        "6pm":  hours[18],
        "7pm":  hours[19],
        "8pm":  hours[20],
        "9pm":  hours[21],
        "10pm": hours[22],
        "11pm": hours[23]
    };
    res.json(Amount);
})

// This function allows the user to update the active times table with the US sensor
app.get('/sensor_triggered', async function(req, res){

    query = `INSERT INTO active_times SET ?`;
    vals = {
        visitor_tracker: 1
    };
    
    visitors = await makeQuery(query, vals);

    res.json({
        "Status": "SUCCESS"
    });
})

app.listen(port);
console.log(`Listening on port ${port}...`);