var Transferclass = (function() {
//*********************************************  
var flagAsync = false;

function _signIn(login, password){
	var data = JSON.stringify([login, password]);
	var xhr = new XMLHttpRequest();
  	xhr.open("POST", "api/SignIn", flagAsync);
    xhr.setRequestHeader("Content-Type", "application/json");
    xhr.send(data);
    
    console.log(xhr.responseText);
    if(xhr.responseText == "200"){
		return true;
	}
	else{
		return false;
	}
}
  

function _signUp(login, password){
	var data = JSON.stringify([login, password]);
	var xhr = new XMLHttpRequest();
  	xhr.open("POST", "api/SignUp", flagAsync);
    xhr.setRequestHeader("Content-Type", "application/json");
    xhr.send(data);
    
    if(xhr.responseText == "200"){
		return true;
	}
	else{
		return false;
	}
}


function _getCatalog(){
	var xhr = new XMLHttpRequest();
  	
  	xhr.open("GET", "api/Catalog/GameCatalog", flagAsync);
    xhr.send();
    
    var catalogJSON = new Array();
    for(i = 0; i < JSON.parse(xhr.responseText).length; i++){
    	catalogJSON[i] = JSON.parse(xhr.responseText)[i];
    }
    console.log(catalogJSON)
    return catalogJSON;
}


function _getKey(id_game){
	var xhr = new XMLHttpRequest();
  	
  	xhr.open("POST", "api/Key", flagAsync);
    xhr.setRequestHeader("Content-Type", "text/plain");
    xhr.send(id_game);
   	//document.getElementById("contentMessage").innerHTML += xhr.responseText + "<br>";
   	return xhr.responseText;
}


return {
  checkSignIn: _signIn,
  trunSignUp: _signUp,
  getCatalog: _getCatalog,  
  getKey: _getKey  
 };

//*********************************************   
})();