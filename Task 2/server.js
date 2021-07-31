const express = require('express')
var bodyParser = require('body-parser')

const app = express()
const path = require('path')
const fs = require('fs')

const port = 3000

// Middleware
app.use(express.urlencoded({extended:true})); 
app.use(express.json());

var file = './data.json';


app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname+'/index.html'));
})

app.get('/success', (req, res) => {
    res.sendFile(path.join(__dirname+'/success.html'));
})

app.post('/submit', (req,res) =>{
    let name = req.body.name;
    let lat = req.body.lat;
    let long= req.body.long;
    let newData = {
        name,
        lat,
        long
    }
 
    fs.readFile(file, (err, data) => {
        if (err && err.code === "ENOENT") {
            return fs.writeFile(file, JSON.stringify([newData],null,2), error => console.error);
        }
        else if(err){
            console.log(err);
        }
          
        else {
            try {
                const fileData = JSON.parse(data);
    
                fileData.push(newData);
    
                return fs.writeFile(file, JSON.stringify(fileData,null,2), error => console.error)
            } catch(err) {
                console.log(err);
            }
        }
    });
    res.redirect('/success');
})




app.listen(port, () => {
  console.log(`App listening at port ${port}`)
})