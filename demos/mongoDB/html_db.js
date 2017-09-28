/*
EC544 Fall 2017, Basic HTML, socket.io node.js, MongoDB example
Emily Lam
*/

// Include packages, make sure they are installed on your system
var MongoClient = require('mongodb').MongoClient;
var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);

// Variables
var url = "mongodb://localhost:27017/mydb";

// HTML
app.get('/', function(req, res){
  res.sendFile(__dirname + '/barebones.html');
});

// Connect socket
io.on('connection', function(socket) {
  // When there is a message
  socket.on('command', function(msg) {
    // Connect to database
    MongoClient.connect(url, function(err, db) {
      if (err) throw err;
      // Basic query of database
      db.collection("randomNum").findOne({},function(err, result) {
        if (err) throw err;
          console.log(result);
          var number = result.number;
          // Send message aquired from query to socket
          io.emit('message', number);
        db.close();
      });
    });
  });
});

// Generate random number at a set interval and update value in DB
setInterval(function() {
  MongoClient.connect(url, function(err, db) {
    if (err) throw err;
    var queryID= {_id: 123};
    var newvalue = {number: Math.floor((Math.random() * 100) + 1)};
    db.collection("randomNum").updateOne(queryID, newvalue, function(err, res) {
      if (err) throw err;
      console.log("Updated number:", newvalue.number);
      db.close();
    });
  });
}, 1000);


// Listen on localhost:3000
http.listen(3000, function() {
  console.log('listening on *:3000');
});
