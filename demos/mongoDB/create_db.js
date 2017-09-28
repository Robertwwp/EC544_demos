/*
Create first instance in database
*/

var MongoClient = require('mongodb').MongoClient;
var url = "mongodb://localhost:27017/mydb";


// Create database and store initial value
MongoClient.connect(url, function(err, db) {
  if (err) throw err;
  var myobj = {_id: 123, number: 1};
  db.collection("randomNum").insertOne(myobj, function(err, res) {
    if (err) throw err;
    console.log("Created intial value");
    db.close();
    process.exit()
  });
});
