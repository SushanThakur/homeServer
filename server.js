const express = require('express');
const { exec } = require('child_process');
const path = require('path');

const app = express();
const PORT = 3000;

// Serve static files (your HTML, CSS, etc.)
app.use(express.static(path.join(__dirname, 'public')));

// Route for running the script
app.post('/run-on-script', (req, res) => {
  
  exec('python on.py', (error, stdout, stderr) => {
    if (error) {
      console.error(`Error executing script: ${error}`);
      return res.status(500).send('Error running the script.');
    }
    res.send(`Script executed successfully: ${stdout}`);
  });
});
app.post('/run-off-script', (req, res) => {
  
  exec('python off.py', (error, stdout, stderr) => {
    if (error) {
      console.error(`Error executing script: ${error}`);
      return res.status(500).send('Error running the script.');
    }
    res.send(`Script executed successfully: ${stdout}`);
  });
});


app.listen(PORT, () => {
  console.log(`Server running on http://localhost:${PORT}`);
});
