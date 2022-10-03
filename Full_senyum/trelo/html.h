//==================================================================================PROGRAM HTML================================================
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
  <head>
    <meta name="viewport" content="width=device-width">
    <meta http-equiv="Content-Type" content="text/html;" charset="utf-8">
    <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
    <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Raleway">
    <style>
      body,h1 {font-family: "Raleway", sans-serif}
      body, html {height: 100%}
    h1 {
        text-shadow: 1px 2px #ffffff;
      }
    .nice{
        text-shadow: 1px 2px #f7f7f7;
    }
    div {
    height: device-widthpx;
    background: linear-gradient(to top right, red, rgba(0, 219, 248, 0.932) );
    }
    .button {
      display: inline-block;
      padding: 10px 55px;
      font-size: 15px;
      cursor: pointer;
      text-align: center;
      text-decoration: none;
      outline: none;
      color: #fff;
      background-color: #11b5e7;
      border: none;
      border-radius: 15px;
      box-shadow: 0 9px #999;
    }
    .button:hover {background-color: #b93131}
    .button:active {
      background-color: #ffffff;
      box-shadow: 0 5px #666;
      transform: translateY(4px);
    }
    .button1 {
      box-shadow: 0 8px 16px 0 rgba(0,0,0,0.2), 0 6px 20px 0 rgba(0,0,0,0.19);
    }
    .box {
      border-radius: 10px;
      width: 98%;
      height: 30%;  
      padding: 5px;
      border: 0px solid rgb(255, 255, 255);
      box-sizing: border-box;
      text-align: center;
   }.bgimg {
      background-image: url('https://github.com/RafiMM0609/ESP8266_WebServer_Relay-SonOff-/blob/main/Pictures/rm209-ning-20-g.jpg?raw=true');
      min-height: 100%;
      background-position: center;
      background-size: cover;
  }
      </style>
    <title>Frelo</title>
  </head>
  <body bgcolor="white">
    <div class="bgimg w3-display-container w3-animate-opacity w3-text-white">
    <h2 align="center">
      <img src="https://www.telkom.co.id/data/image_upload/page/1594108255409_compress_logo%20telkom%20indonesia.png" alt="Simply Easy Learning" width="260" height="200">
    </h2>
    <h1 align="center"><font size="6" color="#262626">Y O G Y A K A R T A</font></h1>
      <form action="/get">
        <h1 align="center"><font  size="5" color="#262626" style="font-family: Trebuchet MS">Pemeliharaan FTM</font></h2>
        <font class="nice" color="black" style="font-family: Trebuchet MS">
          <table border="0" align="center">
            <tbody>
              <tr height="30px"><td><strong>Nama</strong></td><td><input class="box" type="text" name="nama" size="15"></td></tr>
              <tr height="30px"><td><strong>Mitra</strong></td> <td><input class="box" type="text" name="mitra" size="15"></td></tr>
              <tr height="30px"><td><strong>Nomor HP</strong></td> <td><input class="box" type="number" name="nohp" size="15"></td></tr>
              <tr height="30px"><td><label for="keperluan"><strong>Keperluan</strong></label></td><td><select class="box" name="keperluan" id="keperluan">
                <option value="Pasang Baru"> Pasang baru </option>
                <option value="Maintenance"> Maintenance </option>
                <option value="Gangguan"> Gangguan </option>
              </select></td></tr>
              <tr height="30px"><td><strong>Detail Kegiatan</strong></td> <td><input class="box" type="text" name="det_keg" size="15"></td></tr> 
              <tr height="30px"><td><strong>Link KTP</strong></td> <td><input class="box" type="text" name="linkktp" size="15"></td></tr>
              <tr height="30px"><td><input class="button button1" type="submit" value="Submit"></td><td><input class="button button1" type="reset" value="Clear"></td></tr>
            </tbody>
          </table>
        </font>
        </form>
        </div>
        </body>
</html>)rawliteral";
//================================================================welcome========================================================
const char welcome[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><!DOCTYPE html>
<html>
<head>
<title>W3.CSS Template</title>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Raleway">
<style>
body,h1 {font-family: "Raleway", sans-serif}
body, html {height: 100%}
.bgimg {
  background-image: url('https://img.freepik.com/free-vector/blue-copy-space-digital-background_23-2148821698.jpg?t=st=1658471309~exp=1658471909~hmac=f229a120e74c20f2049d411c5e376f0c6f3918de048ce6007a500d8de27cdf83&w=740');
  min-height: 100%;
  background-position: center;
  background-size: cover;
}
</style>
</head>
<body>
<div class="bgimg w3-display-container w3-animate-opacity w3-text-white">
  <div class="w3-display-middle">
    <h1 class="w3-jumbo w3-animate-top">Selamat Datang</h1>
    <hr class="w3-border-grey" style="margin:auto;width:40%">
    <p class="w3-large w3-center">Selamat Bekerja</p>
  </div>
</div>
</body>
</html>)rawliteral";
