export const  Transferclass = (function() {
//*********************************************  
let flagAsync = false;

 let _signIn =  async (login, password) =>{ // функция лежит в основе переменной let
	let response = await fetch("api/SignIn", {
		method: "POST",
		headers: {'Content-Type': 'application/json;charset=utf-8'},
		body:  JSON.stringify([login, password]),
	});
    
    if(response.ok){
		return true;
	}
	else{
		throw response.status;
	}
}
  

let _signUp = async (login, password) => {
	let response = await fetch("api/SignUp", {
		method: "POST",
		headers: {'Content-Type': 'application/json;charset=utf-8'},
		body:  JSON.stringify([login, password]),
	});
    
    if(response.ok){
		return true;
	}
	else{
		throw response.status;
	}
}


let _getCatalog = async ()=>{
	let catalogJSON = new Array();
	let response = await fetch("api/Catalog/GameCatalog", {
		method: "GET",
	});
    
    if(response.ok){
		catalogJSON = await response.json();
		return catalogJSON;
	}
	else{
		throw response.status;
	}
}

return {
  checkSignIn: _signIn,
  trunSignUp: _signUp,
  getCatalog: _getCatalog
 };

//*********************************************   
})();
