var express = require('express');
var router = express.Router();
var fs = require('fs');

/* GET home page. */
router.get('/', function(req, res) {
  var data1 = fs.readFileSync('recipe1.txt', 'utf8');
  var data2 = fs.readFileSync('recipe2.txt', 'utf8');
  var data3 = fs.readFileSync('recipe3.txt', 'utf8');
  var data4 = fs.readFileSync('recipe4.txt', 'utf8');

  data1 = data1.split("\n")[0];
  data2 = data2.split("\n")[0];
  data3 = data3.split("\n")[0];
  data4 = data4.split("\n")[0];
  res.render('recipe', {recipe1:data1, recipe2:data2, recipe3:data3, recipe4:data4});
});

router.get('/add', function(req, res) {
  var data1 = fs.readFileSync('recipe1.txt', 'utf8');
  var data2 = fs.readFileSync('recipe2.txt', 'utf8');
  var data3 = fs.readFileSync('recipe3.txt', 'utf8');
  var data4 = fs.readFileSync('recipe4.txt', 'utf8');

  data1 = data1.split("\n")[0];
  data2 = data2.split("\n")[0];
  data2 = data3.split("\n")[0];
  data4 = data4.split("\n")[0];
  res.render('recipe_add', {recipe1:data1, recipe2:data2, recipe3:data3, recipe4:data4});
});

router.get('/add_recipe', function(req, res){
  res.render('add_recipe');
});

router.get('/storage', function(req, res){
  res.render('storage');
});

router.get('/view', function(req, res){
  const { PythonShell } = require('python-shell');

  var num = fs.readFileSync('recipe_num.txt', 'utf8');
  if(num == '1'){
    var data = fs.readFileSync('recipe1.txt', 'utf8');
  } else if(num == '2') {
    var data = fs.readFileSync('recipe2.txt', 'utf8');
  } else if(num == '3') {
    var data = fs.readFileSync('recipe3.txt', 'utf8');
  } else if(num == '4') {
    var data = fs.readFileSync('recipe4.txt', 'utf8');
  }

  data = data.split('\n');
  var salt = data[1];
  var sugar = data[2];
  var pepper = data[3];
  var chilipowder = data[4];

  let options = {
    scriptPath: "C:\\Users\\user\\AppData\\Local\\Programs\\Python\\Python37\\Scripts\\",
    scriptPath: '/home/pi/seasoningPrinter/python/',
    args: [ salt, sugar, pepper, chilipowder ]
  };
  PythonShell.run('index.py', options, function(err, data){
    if(err) throw err;
    console.log(data);
  });

  data = '소금 : ' + salt + '\n' + '설탕 : ' + sugar + '\n' + '후추 : ' + pepper + '\n' + '고춧가루 : ' + chilipowder + '\n' + data[5];
  console.log(data);
  res.render('view_recipe', {content:data});
});

router.post('/recipe_num', function(req, res){
  console.log(req.body.num);
  var data = req.body.num;
  fs.writeFileSync('recipe_num.txt', data, 'utf8');
  res.redirect('/add_recipe');
});

router.post('/num_recipe', function(req, res){
  console.log(req.body.num);
  var data = req.body.num;
  fs.writeFileSync('recipe_num.txt', data, 'utf8');
  res.redirect('/view');
});

router.post('/modify_recipe', function(req, res){
  var c_name = req.body.cook_name;
  var salt = req.body.salt;
  var sugar = req.body.sugar;
  var pepper = req.body.pepper;
  var chilipowder = req.body.chilipowder;
  var explain = req.body.explain;
  var data = fs.readFileSync('recipe_num.txt', 'utf8');
  
  var content = c_name + '\n' + salt + '\n' + sugar + '\n' + pepper + '\n' + chilipowder + '\n' + explain;
  if(data == '1'){
    fs.writeFileSync('recipe1.txt', content, 'utf8');
  } else if(data == '2') {
    fs.writeFileSync('recipe2.txt', content, 'utf8');
  } else if(data == '3'){
    fs.writeFileSync('recipe3.txt', content, 'utf8');
  } else if(data == '4'){
    fs.writeFileSync('recipe4.txt', content, 'utf8');
  }

  res.redirect('/');
});

module.exports = router;
