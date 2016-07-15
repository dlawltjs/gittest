const  http = require('http')
const server = http.createServer(function (req,res) {
    res.statusCode = 200;
    res.setHeader("Content-Type","text/html");
    res.end("<h1>hello world Lim ji Seon</h1>");
});

server.listen(8081,function () {
   console.log("http server start")
});
