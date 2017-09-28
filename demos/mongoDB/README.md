# MongoDB

Simple example tying together HTML, socket.io, node.js, and MongoDB.

Assumes you already have MongoDB installed and running and have the packages included in node.js files also installed.

This example creates a MongoDB record of a random value. This random value is updated at a fixed interval, 1000 ms, with another random value. Opening up ```localhost:3000``` on your web browser will bring up a simple interface that will show the current random value stored in the database with any keypress.

### Running:

Create the first document (record) using:

```
node create_db.js```


Then  run:
```
node html_db.js ```

This will host a server with a frontend defined by the ```barebones.html``` file. Socket.io maintains the connection between node.js and the html file.
