var http = require('http');
var fs = require('fs');
//hglee require
var multer = require('multer');
var express = require('express');
var util = require("util");
var mime = require('mime');
//var app = express();
var router = express.Router();
//hglee val
var osm_path = './Town01.osm'


var WebSocket = require("ws");
var WebSocketServer = require('ws').Server
wss = new WebSocketServer({ port: 3001 });


router.get('/Map', function(req, res, next) {
  var upload_folder = '';
  //var file = '/Town01.osm' // ex) /upload/files/sample.txt
 // var file = req.params.name // ex) /upload/files/sample.txt
 // console.log(file);
  try {
    if (fs.existsSync(file)) { // 파일이 존재하는지 체크
      var filename = path.basename(file); // 파일 경로에서 파일명(확장자포함)만 추출
      var mimetype = mime.getType(file); // 파일의 타입(형식)을 가져옴
    
      res.setHeader('Content-disposition', 'attachment; filename=' +filename); // 다운받아질 파일명 설정
      res.setHeader('Content-type', mimetype); // 파일 형식 지정
    
      var filestream = fs.createReadStream(file);
      filestream.pipe(res);
      console.log('map_complet');
    } else {
      res.send('해당 파일이 없습니다.');  
      return;
    }
  } catch (e) { // 에러 발생시
    console.log(e);
    res.send('파일을 다운로드하는 중에 에러가 발생하였습니다.');
    return;
  }
});


//module.exports = router;

var app = http.createServer(function(request,response){
    var url = request.url;

    if(request.url == '/'){
      url = '/index.html';
    }
    if(request.url == '/favicon.ico'){
      return response.writeHead(404);
    }

    response.writeHead(200);
    response.end(fs.readFileSync(__dirname +url));

});
app.listen(3000);



wss.on('connection', function connection(ws) {
  ws.on('message', function incoming(message) {
    console.log('received: %s', message);
    ws.send('something');
  });

 // ws.send('something');
});